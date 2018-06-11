/**
 * File Name: bank_total.cpp
 * Author: Dipen Chauhan (https://github.com/overdrivemachines)
 */
#include "bank_total.h"

// Constructors
BankTotal::BankTotal()
{

}

BankTotal::BankTotal(unsigned long int ones,
			unsigned long int fives,
			unsigned long int twenty_fives,
			unsigned long int hundreds,
			unsigned long int two_hundred_fifties)
{
	this->ones = ones;
	this->fives = fives;
	this->twenty_fives = twenty_fives;
	this->hundreds = hundreds;
	this->two_hundred_fifties = two_hundred_fifties;
}

// Getters and Setters
unsigned long int BankTotal::get_ones() const
{
	return ones;
}
void BankTotal::set_ones(const unsigned long int &value)
{
	ones = value;
}

unsigned long int BankTotal::get_fives() const
{
	return fives;
}
void BankTotal::set_fives(const unsigned long int &value)
{
	fives = value;
}

unsigned long int BankTotal::get_twenty_fives() const
{
	return twenty_fives;
}
void BankTotal::set_twenty_fives(const unsigned long int &value)
{
	twenty_fives = value;
}

unsigned long int BankTotal::get_hundreds() const
{
	return hundreds;
}
void BankTotal::set_hundreds(const unsigned long int &value)
{
	hundreds = value;
}

unsigned long int BankTotal::get_two_hundred_fifties() const
{
	return two_hundred_fifties;
}
void BankTotal::set_two_hundred_fifties(const unsigned long int &value)
{
	two_hundred_fifties = value;
}

// To String function
void BankTotal::to_s()
{
	cout << "Ones: " << ones << "\n";
	cout << "Fives: " << fives << "\n";
	cout << "Twenty Fives: " << twenty_fives << "\n";
	cout << "Hundreds: " << hundreds << "\n";
	cout << "Two Hundred Fifties: " << two_hundred_fifties << "\n";
}