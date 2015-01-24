#pragma once
#include "Enemy.h"

class Bomber : public Enemy
{
public:
	Bomber();
	virtual ~Bomber();

	virtual void movePosition();
	virtual void fireWeapon();
	virtual void updateStatus();
	void setAmmo(short a) { ammo = a; }
	short getAmmo() { return ammo; }
	void setSteps(short s) { numsteps = s; }
	short getSteps() { return numsteps; }
private:
	short numsteps;
	short ammo;
//private:
//	short numsteps = 20;
//	short ammo;
};

