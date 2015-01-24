#include "Savings.h"
#include <iostream>
using namespace std;

// Initialize the default constructor
Savings::Savings()
{
    setName("unnamed");		// initialize the account variables
    setTaxID(000000000);
    setBalance(0.0);
	Account::numdeposits = 0;
	Account::numwithdraws = 0;
    for (int x=0; x<10;x++)
    {
        last10withdraws[x] = 0.0;
        last10deposites[x] = 0.0;
    }
}

// Initialize the secondary constructor
Savings::Savings(string n, long tid, double b)
{
    setName(n);
    setTaxID(tid);
    setBalance(b);
	Account::numdeposits = 0;
	Account::numwithdraws = 0;
    for (int x=0; x<10;x++)
    {
        last10withdraws[x] = 0.0;
        last10deposites[x] = 0.0;
    }
}

// Withdraw the given amount from the savings account
void Savings::DoWithdraw(double amount)
{
    setBalance(getBalance()-amount);    // set the balance

    for (int x=0; x<10; x++)
    {
        if (last10withdraws[x] == 0)        // check to see if there is an empty element (0), if so then insert amount to that element
        {
            last10withdraws[x] = amount;
			Account::numwithdraws++;	// increment total num of withdraws counter
            return;
        }
    }

    for (int x=0; x<10;x++)
    {
        if (x<9)
            last10withdraws[x] = last10withdraws[x+1];      // when there are no empty elements, shift elements back one slot, and then
    }                                                       //  free the last element in the array
    last10withdraws[(sizeof(last10withdraws)/sizeof(double))-1] = amount;   // insert array into new slot
	Account::numwithdraws++;
}

// Output the savings account info to screen
void Savings::display() const
{
    cout << "Savings Account" << endl;
    cout << "Name: " << getName() << endl;
    cout << "TaxID: " << getTaxID() << endl;
    cout << "Balance: $" << getBalance() << endl;
    cout << "Last 10 withdrawls: ";
    for (int x=0; x<10; x++)
    {
        cout << "$" << last10withdraws[x] << " | ";	// display last10withdraws array
    }
    cout << endl;
    cout << "Last 10 deposits: ";
    for (int x=0; x<10; x++)
    {
        cout << "$" << last10deposites[x] << " | ";	// display last10depsoites to screen
    }
	cout << "\nNumber of deposits: " << Account::numdeposits << endl;
	cout << "Number of withdrawals: " << Account::numwithdraws << endl;
    cout << endl;
}