#pragma once
#include "Account.h"
#include <string>
using namespace std;

class CreditCard : public Account
{
public:
    CreditCard();	// default constructor
    CreditCard(string n, long tid, double b); // secondary constructor
    void display() const;  // display CreditCard account info to screen
    void DoCharge(string name, double amount);	// Make a charge to the account, requires location name and charge amount
    void MakePayment(double amount);	// Pay off certain amount of the creditcard balance

private:
    long cardnum;	// holds the creditcard number
    string last10charges[10];	// array that holds the last 10 locations of the charge
};
