#include "Enemy.h"
#include <iostream>
Enemy::Enemy()
{
	Enemy::x_position = 0;
	Enemy::y_position = 0;
	Enemy::width = 0;
	Enemy::height = 0;
	Enemy::status = 0;
}

Enemy::~Enemy()
{
	//std::cout << "Enemy destructor called." << std::endl;
}

void Enemy::setHeight(short temph)
{
	height = temph;
}

void Enemy::setWidth(short tempw)
{
	width = tempw;
}

void Enemy::setXPosition(short xpos)
{
	if (xpos>=0 && xpos <=800)
		x_position = xpos;
	else
		std::cout << "Invalid x-coordinate." << std:: endl;
}

void Enemy::setYPosition(short ypos)
{
	if (ypos >=0 && ypos <= 600)
		y_position = ypos;
	else
		std::cout << "Invalid y-coordinate." << std::endl;
}

void Enemy::setStatus(short tempstat)
{
	if (tempstat >= 0)
		status = tempstat;
	else
		std::cout << "Invalid status." << std::endl;
}

short Enemy::getXPosition()
{
	return x_position;
}

short Enemy::getYPosition()
{
	return y_position;
}

short Enemy::getWidth()
{
	return width;
}

short Enemy::getHeight()
{
	return height;
}

short Enemy::getStatus()
{
	return status;
}
