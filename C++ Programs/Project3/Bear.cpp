#include "Bear.h"
#include <iostream>
#include <ctime>
using namespace std;

short number;
const short numsteps = 6;

Bear::Bear()
{
	Bear::setHeight(10);		// Bear characteristics
	Bear::setWidth(3);
	Bear::setStatus(20);
	int xpos = rand() % (800-Bear::getWidth());	// screen width - object width, and a position generated between that
	Bear::setXPosition(xpos);
	Bear::setYPosition(500);
	number = rand() % 10;
}

Bear::~Bear()
{
	//cout << "Bear destructor called." << endl;
}

void Bear::movePosition()
{
	int number = rand() % 2;

	if (number == 0)	// go left
	{
		if (Bear::getStatus() != 0)
		{
			if (Bear::getXPosition() == 0)	// if at beginning go to right
				Bear::setXPosition(Bear::getXPosition() + numsteps);
			else
				Bear::setXPosition(Bear::getXPosition() - numsteps);	// else go to left
		}
		cout << "Bear move to " << Bear::getXPosition() << "," << Bear::getYPosition() << "\t";
	}
		
	if (number == 1)	// go right
	{
		if (Bear::getStatus() != 0)
		{
			if (Bear::getXPosition() + numsteps > 800)	// if goes over 800, turn around and go to left
				Bear::setXPosition(Bear::getXPosition() - numsteps);
			else
				Bear::setXPosition(Bear::getXPosition() + numsteps);	// else go to right
		}
		cout << "Bear move to " << Bear::getXPosition() << "," << Bear::getYPosition() << "\t";		
	}
}

void Bear::fireWeapon()
{
	int number = rand() % 3;
	if (Bear::getStatus() != 0)
	{
		if (number == 0)
			cout << "Bear fires weapon: Bite neck" << endl;
		if (number == 1)
			cout << "Bear fires weapon: Slash chest" << endl;
		if (number == 2)
			cout << "Bear fires weapon: Maul face" << endl;
	}
	else
		cout << "Bear fires weapon: Dead. No weapon fired" << endl;

}

void Bear::updateStatus()
{
	if (Bear::getStatus() > 0)
	{
		Bear::setStatus(Bear::getStatus() - 10);

		cout << "Bear: Raaawr (Growl!). Health: " << Bear::getStatus() << endl;
	}
	else if (Bear::getStatus() == 0)
	{
		cout << "Bear: Dead. Health: " << Bear::getStatus() << endl;
	}
}