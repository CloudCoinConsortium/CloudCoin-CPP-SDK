#pragma once

#include <iostream>
#include <string>

using namespace std;

class BankTotal
	{
	private:
		int privateones = 0;
		int privatefives = 0;
		int privatetwentyfives = 0;
		int privatehundreds = 0;
		int privatetwohundredfifties = 0;


		//Fields
	public:
		int getones() const;
		void setones(const int &value);

		int getfives() const;
		void setfives(const int &value);

		int gettwentyfives() const;
		void settwentyfives(const int &value);

		int gethundreds() const;
		void sethundreds(const int &value);

		int gettwohundredfifties() const;
		void settwohundredfifties(const int &value);

		//Constructors
		BankTotal();

		BankTotal(int ones, int fives, int twentyfives, int hundreds, int twohundredfifties);

	};
