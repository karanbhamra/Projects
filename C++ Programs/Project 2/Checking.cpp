#include "Checking.h"
#include <iostream>
using namespace std;

// Initialize the default constructor
Checking::Checking()
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
        last10checks[x] = 0;
    }
}

// Initialize the secondary constructor
Checking::Checking(string n, long tid, double b)
{
    setName(n);		// initialize the account variables
    setTaxID(tid);
    setBalance(b);
	Account::numdeposits = 0;
	Account::numwithdraws = 0;
    for (int x=0; x<10;x++)
    {
        last10withdraws[x] = 0.0;
        last10deposites[x] = 0.0;
        last10checks[x] = 0;
    }
}

// Output the Checking account info to screen
void Checking::display() const
{
    cout << "Checkings Account" << endl;
    cout << "Name: " << getName() << endl;
    cout << "TaxID: " << getTaxID() << endl;
    cout << "Balance: $" << getBalance() << endl;
    cout << "Last 10 checks: ";
    for (int x=0; x<10; x++)
    {
        cout << "#" << last10checks[x] << "-$" << last10withdraws[x] <<" | ";
    }
    cout << endl;	
    cout << "Last 10 deposits: ";
    for (int x=0; x<10; x++)
    {
        cout << "$" << last10deposites[x] << " | ";
    }
	cout << "\nNumber of deposits: " << Account::numdeposits << endl;
	cout << "Number of withdrawals: " << Account::numwithdraws << endl;
    cout << endl;
}

// Withdraw amount from Checking account, and add check number to the last10checks array
void Checking::WriteCheck(int checknum, double amount)
{
    setBalance(getBalance()-amount);

    for (int x=0; x<10; x++)
    {
        if (last10withdraws[x] == 0 && last10checks[x] == 0)        // check to see if there is an empty element (0), if so then insert amount to that element
        {
            last10withdraws[x] = amount;
            last10checks[x] = checknum;
			Account::numwithdraws++;
            return;
        }
    }

    for (int x=0; x<10;x++)
    {
        if (x<9)
        {
            last10withdraws[x] = last10withdraws[x+1];      // when there are no empty elements, shift elements back one slot, and then
            last10checks[x] = last10checks[x+1];             //  free the last element in the array
        }
    }
    last10withdraws[(sizeof(last10withdraws)/sizeof(double))-1] = amount;   // insert array into new slot
    last10checks[(sizeof(last10checks)/sizeof(int))-1] = checknum;   // insert array into new slot
	Account::numwithdraws++;
}