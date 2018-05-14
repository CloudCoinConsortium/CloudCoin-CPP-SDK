#include "stdafx.h"
#include "Program.h"
#include "CloudBankUtils.h"
#include "CinReader.h"
#include <string>
#include <fstream>
#include "c:\Users\joshc\source\repos\C++ SDK\C++ SDK Class Library\JSON.h"
#include "c:\Users\joshc\source\repos\C++ SDK\C++ SDK Class Library\JSONValue.h"
#include <locale>
#include <utility>
#include <codecvt>

using namespace std;


int main()
{ 
	cout << "--------------------------------------------------------------------" << endl;
	cout << "                    CloudCoin C++ SDK Tester                        " << endl;
	cout << "      Used for testing and as a reference for alternate platforms   " << endl;
	cout << "       This Software is provided as is with all faults, defects     " << endl;
	cout << "           and errors, and without warranty of any kind.            " << endl;
	cout << "                 Free from the CloudCoin Consortium.                " << endl;
	cout << "--------------------------------------------------------------------" << endl;
	cout << "" << endl;

	CinReader reader;
	string publickey = "bank.cloudcoin.global";
	string privatekey = "0DECE3AF-43EC-435B-8C39-E2A5D0EA8676";
	//string privatekey = "pk=" + keys.getprivatekey();
	string email = "cloudbank@protonmail.com";
	BankKeys* keys = new BankKeys(publickey, privatekey, email);
	//string privateKey = "pk=" + keys->getprivatekey();
	//string publicKey = keys->getpublickey();
	CloudBankUtils* cbu = new CloudBankUtils(*keys);
	int Userchoice = 0;
	bool restart = false;
	int loope = 0;

	cout << "                            Welcome!                              " << endl;
	cout << "             Your public key is " + publickey << endl;
	cout << "        Your private key is " + privatekey << endl;
	cout << "               Your email is " + email << endl;
	cout << "                                                                  " << endl;
	cout << "          Pick a function below to test by pressing 1-7!           " << endl;
	cout << "                                                                   " << endl;
	cout << "                                                                   " << endl;
	cout << "[1] Show Coins" << endl;
	cout << "[2] Load your stack from a file" << endl;
	cout << "[3] Send a .stack to the CloudBank" << endl;
	cout << "[4] Get your receipt" << endl;
	cout << "[5] Get a .stack from the CloudBank" << endl;
	cout << "[6] Save a .stack to a local file" << endl;
	cout << "[7] End the program" << endl;
	cout << "Your selection: ";


	Userchoice = reader.readInt(1, 6);

	do
	{
		//Use the switch below to test each of the functions included in the C++ SDK!!
		switch (Userchoice)
		{
		case 1:
			cbu->showCoins();
			cout << "Ones in bank: ";
			cout << cbu->onesInBank << endl;
			cout << "Fives in bank: ";
			cout << cbu->fivesInBank << endl;
			cout << "Twentyfives in bank: ";
			cout << cbu->twentyFivesInBank << endl;
			cout << "Hundreds in bank: ";
			cout << cbu->hundresInBank << endl;
			cout << "TwoHundredFifties in bank: ";
			cout << cbu->twohundredfiftiesInBank << endl;
			loope = loope + 1;
			break;
		case 2:
			cbu->loadStackFromFile(L"C:\\Users\\joshc\\Desktop\\Bank\\1.CloudCoin.1.1195357..stack");
			loope = loope + 1;
			break;
		case 3:
			cbu->sendStackToCloudBank("bank.cloudcoin.global");
			loope = loope + 1;
			break;
		case 4:
			cbu->getReceipt("bank.cloudcoin.global");
			loope = loope + 1;
			break;
		case 5:
			cbu->getStackFromCloudBank(5);
			loope = loope + 1;
			break;
		case 6:
			cbu->saveStackToFile("C:\\CloudTest\\");
			loope = loope + 1;
			break;
		case 7:
			restart = true;
			break;
		default:
			cout << "Command not recognized, please try again." << endl;

			if (Userchoice > 0)
			{
				cout << endl << "Press ENTER to continue";
				reader.readString();
			}
		}

	} while (loope < 1);




	/* Show coins will populate the CloudBankUtils with the totals of each denominations
	These totals are public properties that can be accessed */


	//cbu->showCoins();

	//cbu->loadStackFromFile(L"C:\\Users\\joshc\\Desktop\\Bank\\1.CloudCoin.1.1195357..stack");

	//cbu->sendStackToCloudBank("bank.cloudcoin.global/service");

	//cbu->getReceipt("bank.cloudcoin.global/service");

	//cbu->getStackFromCloudBank(5);

	//cout << cbu->last_response << endl;

	//Interpretation interpretReceipt;

	//interpretReceipt = cbu->interpretReceipt();

	//cbu->saveStackToFile("C:\\CloudTest\\");



	int x = 0;

	return 0;
}