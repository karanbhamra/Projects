#pragma once
#include "Account.h"
#include <string>
using namespace std;

class Checking : public Account
{
public:
    Checking();	// default constructor
    Checking(string n, long tid, double b); // secondary constructor
    void display() const;	// output Checking account info to screen
    void WriteCheck(int checknum, double amount);	// Withdraw amount from checking account
private:
    int last10checks[10];	// holds the last 10 check numbers
};