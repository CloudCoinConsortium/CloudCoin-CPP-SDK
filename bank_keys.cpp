/**
 * File Name: bank_keys.cpp
 * Author: Dipen Chauhan (https://github.com/overdrivemachines)
 */
#include "bank_keys.h"

BankKeys::BankKeys()
{

}

/**
 * Constructor for BankKeys
 * 
 */
BankKeys::BankKeys(const string public_key, const string private_key, const string email)
{
	this->public_key = public_key;
	this->private_key = private_key;
	this->email = email;
}

/**
 * Getter Function for Public Key
 * @return - Public Key
 */
string BankKeys::get_public_key() const
{
	return public_key;
}

/**
 * Setter Function for Public Key
 * @param - Public Key
 */
void BankKeys::set_public_key(const string &value)
{
	public_key = value;
}

/**
 * Getter Function for Private Key
 * @return - Private Key
 */
string BankKeys::get_private_key() const
{
	return private_key;
}

/**
 * Setter Function for Private Key
 * @param - Private Key
 */
void BankKeys::set_private_key(const string &value)
{
	private_key = value;
}

/**
 * Getter Function for Email
 * @return - Email
 */
string BankKeys::get_email() const
{
	return email;
}

/**
 * Setter Function for Email
 * @param - Email
 */
void BankKeys::set_email(const string &value)
{
	email = value;
}

/**
 * To String Function - Prints Public Key, Private Key and Email
 */
void BankKeys::to_s()
{
	cout << "Public Key: " << public_key << "\n";
	cout << "Private Key: " << private_key << "\n";
	cout << "Email: " << email << "\n";
}