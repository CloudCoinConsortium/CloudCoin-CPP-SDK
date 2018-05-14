#pragma once
#include <iostream>
#include <string>

using namespace std;

	/*
	 example json file: 

	    {
	       "publickey":"preston.CloudCoin.Global",
	       "privatekey":"6e2b96d6204a4212ae57ab84260e747f",
	       "email":""
	     }
	     */

	class BankKeys
	{
	private:
		string privatepublickey;
		string privateprivatekey;
		string privateemail;

		//Fields
	public:
		string getpublickey() const;

		void setpublickey(const string &value);

		string getprivatekey() const;

		void setprivatekey(const string &value);

		string getemail() const;

		void setemail(const string &value);

		//void serialize(JSON::Adapter& adapter);


		//Constructors
		BankKeys();

		BankKeys(const string publickey, const string privatekey, const string email);


	};
