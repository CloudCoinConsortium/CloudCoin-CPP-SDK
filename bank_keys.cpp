/**
 * File Name: bank_keys.cpp
 * Author: Dipen Chauhan (https://github.com/overdrivemachines)
 */
#include "bank_keys.h"

BankKeys::BankKeys()
{

}

BankKeys::BankKeys(const string public_key, const string private_key, const string email)
{
	this->public_key = public_key;
	this->private_key = private_key;
	this->email = email;
}


string BankKeys::get_public_key() const
{
	return public_key;
}

void BankKeys::set_public_key(const string &value)
{
	public_key = value;
}

string BankKeys::get_private_key() const
{
	return private_key;
}

void BankKeys::set_private_key(const string &value)
{
	private_key = value;
}

string BankKeys::get_email() const
{
	return email;
}

void BankKeys::set_email(const string &value)
{
	email = value;
}
