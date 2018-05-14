// This is the main DLL file.

#include "stdafx.h"
#include "CloudBankUtils.h"
#include "C++ SDK Class Library.h"

using namespace std;


int main()
{
	string publickey = "bank.cloudcoin.global";
	string privatekey = "0DECE3AF-43EC-435B-8C39-E2A5D0EA8676";
	string email = "cloudbank@protonmail.com";


	BankKeys* keys = new BankKeys(publickey, privatekey, email);


	CloudBankUtils* cbu = new CloudBankUtils(*keys);

	//cbu->showCoins();

	//cbu->loadStackFromFile(L"C:\\Users\\joshc\\Desktop\\Bank\\1.CloudCoin.1.1195357..stack");

	//cbu->sendStackToCloudBank("bank.cloudcoin.global/service");

	//cbu->getReceipt("bank.cloudcoin.global/service");

	cbu->getStackFromCloudBank(5);
	
	//cout << cbu->last_response << endl;

	//Interpretation interpretReceipt;

	//interpretReceipt = cbu->interpretReceipt();

	cbu->saveStackToFile("C:\\CloudTest\\");



	int x = 0;
	
	return 0;

}
