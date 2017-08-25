#include "Fuel.h"



Fuel::Fuel()
{
}


Fuel::~Fuel()
{
}
bool Fuel::init() {
	this->speed = 0;
	return true;
}

void Fuel::setSpeed(int spd)
{
	speed = spd;
}

void Fuel::changeSpeed(int changeSpd)
{
	this->speed += changeSpd;
}

void Fuel::setFuelImg(const char * filename)
{
	this->spdImg = Sprite::create(filename);
	this->addChild(spdImg);
}

int Fuel::getSpd()
{
	return speed;
}
