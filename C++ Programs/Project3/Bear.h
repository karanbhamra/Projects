#pragma once
#include "Enemy.h"

class Bear : public Enemy
{
public:
	Bear();
	virtual ~Bear();

	virtual void movePosition();
	virtual void fireWeapon();
	virtual void updateStatus();
};

