#pragma once	//Header guard
#include <string>
using namespace std;

class Account
{
public:
    Account();	// default constructor
    Account(string n, long int tid, double b); // constuctor with name, taxid, and balance

    void setName(string n);	// set username of account
    void setTaxID(long int tid);	// set users taxid for account
    void setBalance(double b);	// set balance of the account

    string getName() const;	// return the username
    long int getTaxID() const;	// return the taxid
    double getBalance() const;	// return the balance

    void MakeDeposit(double amount);	// add funds to the account
    void display() const;	// display the account information to console

private:
    string name;	// user info
    long int taxID;
    double balance;

protected:
    double last10withdraws[10];	// array containing the amounts of last 10 withdraws
    double last10deposites[10];	// array containing the amounts of last 10 deposites
    int numdeposits;	// total num of deposites
    int numwithdraws;   // total num of withdraws
};