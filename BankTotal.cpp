#include "BankTotal.h"

using namespace std;


	int BankTotal::getones() const
	{
		return privateones;
	}

	void BankTotal::setones(const int &value)
	{
		privateones = value;
	}

	int BankTotal::getfives() const
	{
		return privatefives;
	}

	void BankTotal::setfives(const int &value)
	{
		privatefives = value;
	}

	int BankTotal::gettwentyfives() const
	{
		return privatetwentyfives;
	}

	void BankTotal::settwentyfives(const int &value)
	{
		privatetwentyfives = value;
	}

	int BankTotal::gethundreds() const
	{
		return privatehundreds;
	}

	void BankTotal::sethundreds(const int &value)
	{
		privatehundreds = value;
	}

	int BankTotal::gettwohundredfifties() const
	{
		return privatetwohundredfifties;
	}

	void BankTotal::settwohundredfifties(const int &value)
	{
		privatetwohundredfifties = value;
	}

	BankTotal::BankTotal()
	{

	} //end of constructor

	BankTotal::BankTotal(int ones, int fives, int twentyfives, int hundreds, int twohundredfifties)
	{
		this->setones(ones);
		this->setfives(fives);
		this->settwentyfives(twentyfives);
		this->sethundreds(hundreds);
		this->settwohundredfifties(twohundredfifties);

	} //end of constructor
