#include "CloudBankUtils.h"
#include "BankTotal.h"
#include <fstream>
#include "c:\Users\joshc\source\repos\C++ SDK\C++ SDK Class Library\JSON.h"
#include "c:\Users\joshc\source\repos\C++ SDK\C++ SDK Class Library\JSONValue.h"
#include <locale>
#include <utility>
#include <codecvt>
#include <string>



//static string last_response;
string response;

size_t function_pt(void *ptr, size_t size, size_t nmemb, void *)
{
	response += (const char*)ptr;
	return size * nmemb;
}


	CloudBankUtils::CloudBankUtils(BankKeys startKeys)
	{
		keys = startKeys;
		totalCoinsWithdrawn = 0;
		onesInBank = 0;
		fivesInBank = 0;
		twentyFivesInBank = 0;
		hundresInBank = 0;
		twohundredfiftiesInBank = 0;
	} //end constructor




	
	void CloudBankUtils::showCoins()
	{
		string privateKey = "pk=" + keys.getprivatekey();
		string https = "https://";
		string service = "/show_coins.aspx";
		string concat = https + keys.getpublickey() + service;


		CURL *curl;
		CURLcode res;

		curl_global_init(CURL_GLOBAL_ALL);

		curl = curl_easy_init();

		if (curl)
		{
			curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);

			curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);

			cout << "https://" + keys.getpublickey() + "/show_coins.aspx?k=" + keys.getprivatekey() << endl;
			//curl_easy_setopt(curl, CURLOPT_URL, L"https://" + keys.getpublickey() + L"/service/show_coins.aspx?k=" + keys.getprivatekey());
			curl_easy_setopt(curl, CURLOPT_URL, concat.c_str());
			curl_easy_setopt(curl, CURLOPT_POSTFIELDS, privateKey.c_str());
			curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, function_pt);
			res = curl_easy_perform(curl);

			if (res != CURLE_OK)
				cout << curl_easy_strerror(res);

			curl_easy_cleanup(curl);
			cout << response << endl;


			if (response.find("error") != string::npos)
			{
				cout << response << endl;
			}
			else
			{
				JSONValue *value = JSON::Parse(response.c_str());
				if (value == NULL)
				{
					cout << "Error" << endl;
				}
				else
				{
					JSONObject root;
					if (value->IsObject() == false)
					{
						cout << "The root element is not an object, did you change the example?\r\n" << endl;
					}
					else
					{
						root = value->AsObject();
						if (root.find(L"ones") != root.end() && root[L"ones"]->IsNumber())
						{
							onesInBank = (int)root[L"ones"]->AsNumber();
						}
						if (root.find(L"fives") != root.end() && root[L"fives"]->IsNumber())
						{
							fivesInBank = (int)root[L"fives"]->AsNumber();
						}
						if (root.find(L"twentyfives") != root.end() && root[L"twentyfives"]->IsNumber())
						{
							twentyFivesInBank = (int)root[L"twentyfives"]->AsNumber();
						}
						if (root.find(L"hundreds") != root.end() && root[L"hundreds"]->IsNumber())
						{
							hundresInBank = (int)root[L"hundreds"]->AsNumber();
						}
						if (root.find(L"twohundredfifties") != root.end() && root[L"twohundredfifties"]->IsNumber())
						{
							twohundredfiftiesInBank = (int)root[L"twohundredfifties"]->AsNumber();
						}
						
					}
				}
			};

		};
		response ="";
	}

		// End ShowCoins
	
		void CloudBankUtils::loadStackFromFile(const wstring & filename)
		{
			ifstream inFile;
			string finalstring;

			inFile.open(filename);

			if (!inFile)
			{
				cout << "Unable to open file" << endl;
				exit(1);
			}

			while (inFile >> finalstring)
			{
				rawStackForDeposit = rawStackForDeposit + finalstring;
			}

			cout << rawStackForDeposit << endl;

			inFile.close();
		};
	//End loadstackfromfile
		
		void CloudBankUtils::sendStackToCloudBank(const string &toPublicURL)
		{
			string CloudBankFeedback;
			string stack = "stack=" + rawStackForDeposit;

			string toPublic = "https://";
			string depositOne = "/deposit_one_stack.aspx";
			string concat = toPublic + toPublicURL + depositOne;

			using convert_type = std::codecvt_utf8<wchar_t>;
			std::wstring_convert<convert_type, wchar_t> converter;
			

			CURL *curl;
			CURLcode res;

			//string postfields = curl_easy_escape(curl, stack.c_str(), stack.length());
			string postfields = stack.c_str();
			int plength = (long)strlen(postfields.c_str());

			curl_global_init(CURL_GLOBAL_ALL);

			curl = curl_easy_init();

			if (curl)
			{
				curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
				curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
				//cout << "https://" + keys.getpublickey() + "/service/show_coins.aspx?k=" + keys.getprivatekey() << endl;
				//curl_easy_setopt(curl, CURLOPT_URL, L"https://" + keys.getpublickey() + L"/service/show_coins.aspx?k=" + keys.getprivatekey());
				curl_easy_setopt(curl, CURLOPT_URL, concat.c_str());
				//curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, (long) strlen(postfields.c_str()));
				curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, plength);
				curl_easy_setopt(curl, CURLOPT_POSTFIELDS, postfields.c_str());
				curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, function_pt);
				
				
				res = curl_easy_perform(curl);

				if (res != CURLE_OK)
					cout << curl_easy_strerror(res);

				curl_easy_cleanup(curl);
				cout << response << endl;
				
				JSONValue *value = JSON::Parse(response.c_str());
				if (value == NULL)
				{
					cout << "Error" << endl;
				}
				else
				{
					JSONObject root;
					if (value->IsObject() == false)
					{
						cout << "The root element is not an object." << endl;
					}
					else
					{
						root = value->AsObject();
						if (root.find(L"receipt") != root.end())
						{
							receiptNumber = converter.to_bytes(root[L"receipt"]->AsString());
						}
						int x = 0;
					}
				}
			}
			response = "";
		}

		void CloudBankUtils::getReceipt(string toPublicURL)
		{
			CURL *curl;
			CURLcode res;

			string toPublic = "https://";
			string receiptnum = "/" + keys.getprivatekey() + "/Receipts/" + receiptNumber + ".json";
			string concat = toPublic + toPublicURL + receiptnum;

			curl_global_init(CURL_GLOBAL_ALL);

			curl = curl_easy_init();

			if (curl)
			{
				curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);

				curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);

				curl_easy_setopt(curl, CURLOPT_URL, concat.c_str());
				//curl_easy_setopt(curl, CURLOPT_POSTFIELDS, keys.getprivatekey().c_str());
				curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, function_pt);
				res = curl_easy_perform(curl);

				if (res != CURLE_OK)
					cout << curl_easy_strerror(res);

				curl_easy_cleanup(curl);
				rawReceipt = response;
		
			}
			response = "";
		}



		void CloudBankUtils::getStackFromCloudBank(int amountToWithdraw)
		{
			CURL *curl;
			CURLcode res;
			totalCoinsWithdrawn = amountToWithdraw;
			string postValues = "pk=" + keys.getprivatekey() + "&amount=" + to_string(amountToWithdraw);
			string toPublic = "https://";
			string withdrawOne = "/service/withdraw_account.aspx";
			string concat = toPublic + keys.getpublickey() + withdrawOne;

			curl_global_init(CURL_GLOBAL_ALL);

			curl = curl_easy_init();

			if (curl)
			{
				curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
				curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
				//curl_easy_setopt(curl, CURLOPT_URL, L"https://" + keys.getpublickey() + L"/service/show_coins.aspx?k=" + keys.getprivatekey());
				curl_easy_setopt(curl, CURLOPT_URL, concat.c_str());
				curl_easy_setopt(curl, CURLOPT_POSTFIELDS, postValues.c_str());
				curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, function_pt);
				res = curl_easy_perform(curl);

				if (res != CURLE_OK)
					cout << curl_easy_strerror(res);

				curl_easy_cleanup(curl);
				rawStackFromWithdrawal = response;


				//cout << response << endl;
				
				
			}
			response = "";
		}
		
			
		Interpretation CloudBankUtils::interpretReceipt()
		{
			Interpretation *inter = new Interpretation();
			int total = 0;
			int Tauth;
			int Tfrack;
			int Tnote;


			JSONValue *value = JSON::Parse(rawReceipt.c_str());
			if (value == NULL)
			{
				cout << "Error" << endl;
			}
			else
			{
				JSONObject root;
				JSONObject detail;
				JSONArray receiptDet;
				if (value->IsObject() == false)
				{
					cout << "The root element is not an object." << endl;
				}
				else
				{
					root = value->AsObject();
					if (root.find(L"receipt") != root.end())
					{
						receiptDet = root[L"receipt"]->AsArray();
						for (int i = 0; i < receiptDet.size(); i++)
						{
							if (!receiptDet[i]->IsNull())
							{
								detail = receiptDet[i]->AsObject();
								if (detail[L"status"]->AsString() == L"authentic")
								{
									int sn = detail[L"sn"]->AsNumber();
									int dn = getDenomination(sn);
									total = total + dn;
								};
							};
							
						}
					}

					if (root.find(L"total_authentic") != root.end() && root[L"total_authentic"]->IsNumber())
					{
						Tauth = (int)root[L"total_authentic"]->AsNumber();
					}

					if (root.find(L"total_fracked") != root.end() && root[L"total_fracked"]->IsNumber())
					{
						Tfrack = (int)root[L"total_fracked"]->AsNumber();
					}
					Tnote = Tauth + Tfrack;
					string interpretation = "receipt number: " + receiptNumber + " total authentic notes: " + to_string(Tnote) + " total authentic coins: " + to_string(total);
					inter->interpretation = interpretation;
					inter->totalAuthenticCoins = total;
					inter->totalAuthenticNotes = Tnote;
					return *inter;
					
					int x = 0;
				}
			}

		}

		int CloudBankUtils::getDenomination(int sn)
			{
				int nom = 0;
				if ((sn < 1))
				{
					nom = 0;
				}
				else if ((sn < 2097153))
				{
					nom = 1;
				}
				else if ((sn < 4194305))
				{
					nom = 5;
				}
				else if ((sn < 6291457))
				{
					nom = 25;
				}
				else if ((sn < 14680065))
				{
					nom = 100;
				}
				else if ((sn < 16777217))
				{
					nom = 250;
				}
				else
				{
					nom = '0';
				}

				return nom;
				return 0;
			}
		
		string CloudBankUtils::getStackName()
        {
            return to_string(totalCoinsWithdrawn) + ".CloudCoin." + receiptNumber + ".stack";
		};


		void CloudBankUtils::saveStackToFile(string path)
		{
			ofstream myfile;
			myfile.open(path + getStackName());
			myfile << rawStackFromWithdrawal;
			myfile.close();

		};

		void CloudBankUtils::transferCloudCoins(string toPublicKey, int coinsToSend)
		{
			//Download amount
			getStackFromCloudBank(coinsToSend);
			rawStackForDeposit = rawStackFromWithdrawal;//Make it so it will send the stack it recieved
			sendStackToCloudBank(toPublicKey);
		}