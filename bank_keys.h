/**
 * File Name: bank_keys.h
 * Author: Dipen Chauhan (https://github.com/overdrivemachines)
 */
#include <iostream>
using namespace std;
class BankKeys
{
private:
	string public_key;
	string private_key;
	string email;
public:
	BankKeys();
	BankKeys(const string public_key, const string private_key, const string email);

	string	get_public_key() const;
	void 	set_public_key(const string &value);
	string	get_private_key() const;
	void 	set_private_key(const string &value);
	string	get_email() const;
	void 	set_email(const string &value);
	void	to_s();
};