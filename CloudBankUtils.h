#pragma once

#define CBU_API  __declspec( dllexport )
//#define CBU_API  __declspec( dllimport )

#include "BankKeys.h"
#include <string>
#include <unordered_map>
#include <vector>
#include <iostream>
#include <stdexcept>
#include <curl.h>
#include "Interpretation.h"
#include "Receipt.h"

using namespace std;


	class CloudBankUtils
	{
	private:
		//BankKeys *keys;
		BankKeys keys;
		string rawStackForDeposit;
		string rawStackFromWithdrawal;
		string receiptNumber;
	public:
		int onesInBank = 0;
		int fivesInBank = 0;
		int twentyFivesInBank = 0;
		int hundresInBank = 0;
		int twohundredfiftiesInBank = 0;
		int totalCoinsWithdrawn = 0;
		string rawReceipt;
		

		/*
		virtual CloudBankUtils()
		{
			delete keys;
			delete cli;
		}
		*/

		CBU_API CloudBankUtils(BankKeys startKeys);

		CBU_API void showCoins();
		

		CBU_API void loadStackFromFile(const std::wstring &filename);
	
		
		CBU_API void sendStackToCloudBank(const std::string &toPublicURL);

		CBU_API void getReceipt(string toPublicURL);

		CBU_API void getStackFromCloudBank(int amountToWithdraw);


	private:
		

	public:

		CBU_API Interpretation interpretReceipt();

		CBU_API void saveStackToFile(string path);

		CBU_API std::string getStackName();

		CBU_API void transferCloudCoins(string toPublicKey, int coinsToSend);

		CBU_API int getDenomination(int sn);

	};
