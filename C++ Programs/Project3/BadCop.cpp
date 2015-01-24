#include "BadCop.h"
#include <iostream>
using namespace std;

short number1;
//const short numsteps = 3;
//short ammo1;

BadCop::BadCop()
{
	BadCop::setHeight(6);		// BadCop characteristics
	BadCop::setWidth(2);
	BadCop::setStatus(70);
	int xpos = rand() % (800-BadCop::getWidth());	// screen width - object width, and a position generated between that
	BadCop::setXPosition(xpos);
	BadCop::setYPosition(500);
	//ammo1 = 30;
	BadCop::setAmmo(30);
	BadCop::setSteps(3);
}

BadCop::~BadCop()
{
	//std::cout << "BadCop destructor called." << std::endl;
}

void BadCop::movePosition()
{
	int number1 = rand() % 2;

	if (number1 == 0)	// go left
	{
		if (BadCop::getStatus() != 0)
		{
			if (BadCop::getXPosition() == 0)	// if at beginning go to right
				BadCop::setXPosition(BadCop::getXPosition() + numsteps);
			else
				BadCop::setXPosition(BadCop::getXPosition() - numsteps);	// else go to left
		}
		cout << "BadCop move to " << BadCop::getXPosition() << "," << BadCop::getYPosition() << "\t";
	}
		
	if (number1 == 1)	// go right
	{
		if (BadCop::getStatus() != 0)
		{
			if (BadCop::getXPosition() + numsteps > 800)	// if goes over 800, turn around and go to left
				BadCop::setXPosition(BadCop::getXPosition() - numsteps);
			else
				BadCop::setXPosition(BadCop::getXPosition() + numsteps);	// else go to right
		}
		cout << "BadCop move to " << BadCop::getXPosition() << "," << BadCop::getYPosition() << "\t";		
	}
}

void BadCop::fireWeapon()
{
	if (BadCop::getStatus() != 0)
	{
		if (BadCop::getAmmo() > 1)
		{
			BadCop::setAmmo(BadCop::getAmmo()-5);//ammo1 -= 5;
			cout << "BadCop fires weapon: HK G36 Assault rifle, " << BadCop::getAmmo() << " bullets left" << endl;

		}
		else
		{
			cout << "BadCop fires weapon: No ammo, reloading" << endl;
			BadCop::setAmmo(30);
		}
	}
	else
		cout << "BadCop fires weapon: Dead. No weapon fired" << endl;
}

void BadCop::updateStatus()
{
	if (BadCop::getStatus() > 0)
	{
		BadCop::setStatus(BadCop::getStatus() - 10);

		cout << "BadCop: Officer hit (Bang!). Health: "<< BadCop::getStatus() << endl;
	}
	else if (BadCop::getStatus() == 0)
	{
		cout << "BadCop: Officer down. Health: " << BadCop::getStatus() << endl;
	}
}