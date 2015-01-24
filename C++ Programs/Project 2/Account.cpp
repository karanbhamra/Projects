#include "Account.h"
#include "string"
#include <iostream>
using namespace std;

// Initialize values in the constructor
Account::Account()
{
    name = "unnamed";
    taxID = 000000000;
    balance = 0.0;
	Account::numdeposits = 0;
	Account::numwithdraws = 0;
    for (int x=0; x<10;x++)
    {
        last10deposites[x] = 0.0;
        last10withdraws[x] = 0.0;
    }
}

// Initialize values in the constructor
Account::Account(string n, long int tid, double b)
{
    name = n;
    taxID = tid;
    balance = b;
	Account::numdeposits = 0;
	Account::numwithdraws = 0;
    for (int x=0; x<10;x++)
    {
        last10deposites[x] = 0.0;
        last10withdraws[x] = 0.0;
    }
}

double Account::getBalance() const
{
    return balance;	// returns user balance
}

long int Account::getTaxID() const
{
    return taxID;	// returns user taxid
}

string Account::getName() const
{
    return name;  // returns user name
}

void Account::setBalance(double b)
{
    balance = b;	// set user balance
}

void Account::setTaxID(long tid)
{
    taxID = tid;	// set user taxid
}

void Account::setName(string n)
{
    name = n;	// set user name
}

void Account::display() const
{
    cout << "Name: " << getName() << endl;		// output user info to screen
    cout << "TaxID: " << getTaxID() << endl;
    cout << "Balance: $" << getBalance() << endl;
}

void Account::MakeDeposit(double amount)
{
    setBalance(getBalance()+amount);    // set the balance

    for (int x=0; x<10; x++)
    {
        if (last10deposites[x] == 0)        // check to see if there is an empty element (0), if so then insert amount to that element
        {
            last10deposites[x] = amount;
			Account::numdeposits++;		// increment total num of depsoites
            return;
        }
    }

    for (int x=0; x<10;x++)
    {
        if (x<9)
            last10deposites[x] = last10deposites[x+1];      // when there are no empty elements, shift elements back one slot, and then
    }                                                       //  free the last element in the array
    last10deposites[(sizeof(last10deposites)/sizeof(double))-1] = amount;   // insert array into new slot
	Account::numdeposits++;
}