#include <iostream>
#include "Savings.h"
#include "Checking.h"
#include "Creditcard.h"
#include <string>
#include <cstdlib>
using namespace std;

void displayMenu(short input, Savings *savingsAccount, CreditCard *creditCardAccount, Checking *checkingAccount);	// output menu to screen
void runMenu(short choice, Savings *savingsAccount, CreditCard *creditCardAccount, Checking *checkingAccount);	// check user selection
void savingsDeposit(Savings *savingsAccount);	// run the savings deposit method
void savingsWithdrawal(Savings *savingsAccount);	// run the savings withdrawal method
void checkingDeposit(Checking *checkingAccount);	// run the checking deposit method
void checkingCheck(Checking *checkingAccount);	// run the checking withdrawal method
void creditCardPayment(CreditCard *creditCardAccount);	// run the creditcard depsoit method
void creditCardCharge(CreditCard *creditCardAccount);	// run the creditcard withdrawal method
void clearScreen();	// clears the screen
bool showMenu = true;	// run menu till showMenu turns false, then exit

int main()
{
	string user;	// setup the name, id and balance
	long id = 123456789;
	double balance = 100.0;
	cout << "Enter your name: ";
	getline(cin,user);

	system("cls");	// clearscreen
	Savings *savingsAccount = new Savings(user, id, balance);	// setup the three user objects and pointers
	CreditCard *creditCardAccount = new CreditCard(user, id, balance);
	Checking *checkingAccount= new Checking(user, id, balance);
	
	short input = 0;	// menu option selector
	displayMenu(input, savingsAccount, creditCardAccount, checkingAccount);	// display the menu
	
    return 0;
}

void displayMenu(short input, Savings *savingsAccount, CreditCard *creditCardAccount, Checking *checkingAccount)
{
	while (showMenu)	// display menu till showMenu turns false
	{
		cout << "Project #2 by Karan Bhamra" << endl;
		cout << "\nChecking balance: $" << checkingAccount->getBalance() << "\tSavings balance: $" << savingsAccount->getBalance() << "\tCredit Card balance: $" << creditCardAccount->getBalance() << endl;
		cout << "1. Savings Deposit" << endl;
		cout << "2. Savings Withdrawal" << endl;
		cout << "3. Checking Deposit" << endl;
		cout << "4. Write A Check" << endl;
		cout << "5. Credit Card Payment" << endl;
		cout << "6. Make A Charge" << endl;
		cout << "7. Display Savings" << endl;
		cout << "8. Display Checking" << endl;
		cout << "9. Display Credit Card" << endl;
		cout << "0. Exit" << endl;
		cout << ": ";
		cin >> input;
		runMenu(input, savingsAccount, creditCardAccount, checkingAccount);		// run the method which checks the input
	}
}

void runMenu(short choice, Savings *savingsAccount, CreditCard *creditCardAccount, Checking *checkingAccount)
{
	switch(choice)	// run the methods relating to the option and then clear the screen
	{
	case 0:
		delete savingsAccount;	// free up object memory
		delete creditCardAccount;
		delete checkingAccount;
		showMenu = false;	// exit program
		break;
	case 1:
			savingsDeposit(savingsAccount);
			clearScreen();
			break;
	case 2:
			savingsWithdrawal(savingsAccount);
			clearScreen();
			break;
	case 3:
			checkingDeposit(checkingAccount);
			clearScreen();
			break;
	case 4:
			checkingCheck(checkingAccount);
			clearScreen();
			break;
	case 5:
			creditCardPayment(creditCardAccount);
			clearScreen();
			break;
	case 6:
			creditCardCharge(creditCardAccount);
			clearScreen();
			break;
	case 7:
			savingsAccount->display();
			clearScreen();
			break;
	case 8:
			checkingAccount->display();
			clearScreen();
			break;
	case 9:
			creditCardAccount->display();
			clearScreen();
			break;
	}
}

void savingsDeposit(Savings *savingsAccount)	// run savings deposit method
{
	double depositAmount=0.0;
	cout << "Savings Deposit Amount: $";
	cin >> depositAmount;
	savingsAccount->MakeDeposit(depositAmount);
}

void savingsWithdrawal(Savings *savingsAccount) // run savings withdrawl method
{
	double withdrawAmount = 0.0;
	cout << "Savings Withdrawal Amount: $";
	cin >> withdrawAmount;
	savingsAccount->DoWithdraw(withdrawAmount);
}

void checkingDeposit(Checking *checkingAccount)		// run checkings depsosit method
{
	double depositAmount = 0.0;
	cout << "Checking Deposit Amount: $";
	cin >> depositAmount;
	checkingAccount->MakeDeposit(depositAmount);
}

void checkingCheck(Checking *checkingAccount)	// run checkings withdrawal method
{
	double checkAmount = 0.0;
	int checkNum = 0;
	cout << "Check Number: ";
	cin >> checkNum;
	cout << "Check Amount: $";
	cin >> checkAmount;			
	checkingAccount->WriteCheck(checkNum, checkAmount);
}

void creditCardPayment(CreditCard *creditCardAccount)	// run creditcard deposit method 
{
	double creditCardPayment = 0.0;
	cout << "Credit Card Payment Amount: $";
	cin >> creditCardPayment;
	creditCardAccount->MakePayment(creditCardPayment);
}

void creditCardCharge(CreditCard *creditCardAccount)	// run creditcard withdrawl method
{
	string location;
	double creditCardCharge = 0.0;
	cout << "Credit Card Charge Location: ";
	cin.ignore();
	getline(cin, location);
	cout << "Credit Card Charge Amount: $";
	cin >> creditCardCharge;
	creditCardAccount->DoCharge(location, creditCardCharge);
}

void clearScreen()		// clear screen and go back to menu
{
	cout << "Press enter to go back to main menu.";
	cin.ignore();
	cin.get();
	system("cls");
}