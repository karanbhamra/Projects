#include "Creditcard.h"
#include <iostream>
#include <string>
using namespace std;

// Initialize default constructor
CreditCard::CreditCard()
{
    setName("unnamed");		// initialize the account variables
    setTaxID(000000000);
    setBalance(0.0);
	cardnum = 000000000;
	Account::numdeposits = 0;
	Account::numwithdraws = 0;
    for (int x=0; x<10;x++)
    {
        last10deposites[x] = 0.0;
        last10withdraws[x] = 0.0;
        last10charges[x] = "";
    }
}

// Initialize secondary constructor
CreditCard::CreditCard(string n, long tid, double b)
{
    setName(n);		// initialize the account variables
    setTaxID(tid);
    setBalance(b);
	cardnum = 000000000;
	Account::numdeposits = 0;
	Account::numwithdraws = 0;
    for (int x=0; x<10;x++)
    {
        last10deposites[x] = 0.0;
        last10withdraws[x] = 0.0;
        last10charges[x] = "";
    }
}

// Add the amount to the balance of CreditCard account and add the location name to the last10locations array
void CreditCard::DoCharge(string name, double amount)
{
    setBalance(getBalance()+amount);

    for (int x=0; x<10; x++)
    {
        if (last10withdraws[x] == 0)        // check to see if there is an empty element (0), if so then insert amount to that element
        {
            last10withdraws[x] = amount;
            last10charges[x] = name;
			Account::numwithdraws++;
            return;
        }
    }

    for (int x=0; x<10;x++)
    {
        if (x<9)
        {
            last10withdraws[x] = last10withdraws[x+1];      // when there are no empty elements, shift elements back one slot, and then
            last10charges[x] = last10charges[x+1];             //  free the last element in the array
        }
    }
    last10withdraws[(sizeof(last10withdraws)/sizeof(double))-1] = amount;   // insert array into new slot
    last10charges[(sizeof(last10charges)/sizeof(string))-1] = name;   // insert array into new slot
	Account::numwithdraws++;
}

void CreditCard::MakePayment(double amount)
{
    setBalance(getBalance()-amount);    // set the balance

    for (int x=0; x<10; x++)
    {
        if (last10deposites[x] == 0)        // check to see if there is an empty element (0), if so then insert amount to that element
        {
            last10deposites[x] = amount;
			Account::numdeposits++;
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

// Display the CreditCard account info
void CreditCard::display() const
{
    cout << "CreditCard Account" << endl;
    cout << "Name: " << getName() << endl;
    cout << "TaxID: " << getTaxID() << endl;
    cout << "Balance: $" << getBalance() << endl;
    cout << "Last 10 charges: ";
    for (int x=0; x<10; x++)
    {
        cout << last10charges[x] <<"-$" << last10withdraws[x] << " | ";	// last 10 locations and amount
    }
    cout << endl;
    cout << "Last 10 payments: ";
    for (int x=0; x<10; x++)
    {
        cout << "$" << last10deposites[x] << " | ";	// last 10 payments
    }
	cout << "\nNumber of deposits: " << Account::numdeposits << endl;
	cout << "Number of withdrawals: " << Account::numwithdraws << endl;
    cout << endl;
}