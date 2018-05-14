
#include "BankKeys.h"
using namespace std;

	string BankKeys::getpublickey() const
	{
		return privatepublickey;
	}

	void BankKeys::setpublickey(const string &value)
	{
		privatepublickey = value;
	}

	string BankKeys::getprivatekey() const
	{
		return privateprivatekey;
	}

	void BankKeys::setprivatekey(const string &value)
	{
		privateprivatekey = value;
	}

	string BankKeys::getemail() const
	{
		return privateemail;
	}

	void BankKeys::setemail(const string &value)
	{
		privateemail = value;
	}

	


	BankKeys::BankKeys()
	{

	} //end of constructor

	BankKeys::BankKeys(const string publickey, const string privatekey, const string email)
	{
		this->setpublickey(publickey);
		this->setprivatekey(privatekey);
		this->setemail(email);
	} //end of constructor

