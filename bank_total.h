/**
 * File Name: bank_total.h
 * Author: Dipen Chauhan (https://github.com/overdrivemachines)
 */
#include <iostream>
#include <string>
using namespace std;

class BankTotal
{
	unsigned long int ones;
	unsigned long int fives;
	unsigned long int twenty_fives;
	unsigned long int hundreds;
	unsigned long int two_hundred_fifties;
	string bank_server;
	string status;
	string time;

public:
	BankTotal();
	BankTotal(unsigned long int ones,
				unsigned long int fives,
				unsigned long int twenty_fives,
				unsigned long int hundreds,
				unsigned long int two_hundred_fifties);

	// Getters and Setters
	unsigned long int 	get_ones() const;
	void 				set_ones(const unsigned long int &value);
	unsigned long int 	get_fives() const;
	void 				set_fives(const unsigned long int &value);
	unsigned long int 	get_twenty_fives() const;
	void 				set_twenty_fives(const unsigned long int &value);
	unsigned long int 	get_hundreds() const;
	void 				set_hundreds(const unsigned long int &value);
	unsigned long int 	get_two_hundred_fifties() const;
	void 				set_two_hundred_fifties(const unsigned long int &value);
	
	// To String function
	void to_s();
};