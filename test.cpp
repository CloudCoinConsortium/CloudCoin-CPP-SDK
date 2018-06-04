/**
 * File Name: test.cpp
 * Author: Dipen Chauhan (https://github.com/overdrivemachines)
 */
#include "bank_keys.h"
using namespace std;

int main()
{
	BankKeys bk;
	bk.set_public_key("7cc454a9");
	bk.set_private_key("1a23b4c5");	
	bk.set_email("hello@helloworld.com");

	BankKeys bk2("1234", "4567", "test@test.com");

	cout << bk.get_public_key() << "\n";
	cout << bk.get_private_key() << "\n";
	cout << bk.get_email() << "\n";

	bk2.to_s();

	return 0;
}