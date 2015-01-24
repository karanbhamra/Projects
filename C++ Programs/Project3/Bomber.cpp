#include "Bomber.h"
#include <iostream>
using namespace std;

short number2;
//const short numsteps = 20;
//short ammo;

Bomber::Bomber()
{
	Bomber::setHeight(35);		// B1 bomber characteristics
	Bomber::setWidth(145);
	Bomber::setStatus(40);
	int xpos = rand() % (800-Bomber::getWidth());	// screen width - object width, and a position generated between that
	Bomber::setXPosition(xpos);
	Bomber::setYPosition(100);
	//ammo = 4;
	Bomber::setAmmo(4);
	Bomber::setSteps(20);
}

Bomber::~Bomber()
{
	//std::cout << "Bomber destructor called." << std::endl;
}

void Bomber::movePosition()
{
	int number2 = rand() % 2;

	if (number2 == 0)	// go left
	{
		if (Bomber::getStatus() != 0)
		{
			if (Bomber::getXPosition() == 0)	// if at beginning go to right
				Bomber::setXPosition(Bomber::getXPosition() + numsteps);
			else
				Bomber::setXPosition(Bomber::getXPosition() - numsteps);	// else go to left
		}
		cout << "Bomber move to " << Bomber::getXPosition() << "," << Bomber::getYPosition() << "\t";
	}
		
	if (number2 == 1)	// go right
	{
		if (Bomber::getStatus() != 0)
		{
			if (Bomber::getXPosition() + numsteps > 800)	// if goes over 800, turn around and go to left
				Bomber::setXPosition(Bomber::getXPosition() - numsteps);
			else
				Bomber::setXPosition(Bomber::getXPosition() + numsteps);	// else go to right
		}
		cout << "Bomber move to " << Bomber::getXPosition() << "," << Bomber::getYPosition() << "\t";		
	}
}

void Bomber::fireWeapon()
{
	if (Bomber::getStatus() != 0)
	{
		if (Bomber::getAmmo() > 1)
		{
			Bomber::setAmmo(Bomber::getAmmo() -1 );
			cout << "Bomber fires weapon: Mk-82 bomb, " << Bomber::getAmmo() << " bombs left" << endl;
			//ammo--;
		}
		else
		{
			cout << "Bomber fires weapon: No ammo, reloading" << endl;
			Bomber::setAmmo(4);
		}
	}
	else
		cout << "Bomber fires weapon: Destroyed. No weapon fired" << endl;
}

void Bomber::updateStatus()
{
	if (Bomber::getStatus() > 0)
	{
		Bomber::setStatus(Bomber::getStatus() - 10);

		cout << "Bomber: Under fire (Ping!). Health: " << Bomber::getStatus() << endl;
	}
	else if (Bomber::getStatus() == 0)
	{
		cout << "Bomber: Shot down. Health: " << Bomber::getStatus() << endl;
	}
}