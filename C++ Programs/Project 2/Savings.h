#pragma once
#include "Account.h"
#include <string>
using namespace std;

class Savings : public Account
{
public:
    Savings();	// default constructor
    Savings(string n, long tid, double b);	// secondary constructor
    void display() const;	// display savings accuont info to screen
    void DoWithdraw(double amount);		// withrdaw from savings account
};