#include"Arms.h"
bool Arms::init() {
	
	this->atkValue = 0;
	return true;
}

void Arms::setAtkValue(int atkValue)
{
	this->atkValue = atkValue;
}

void Arms::changeAtkValue(int changeValue)
{
	atkValue += changeValue;
}

void Arms::setArmsImg(const char * filename)
{
	armsImg = Sprite::create(filename);
	this->addChild(armsImg);
}

int Arms::getAtk()
{
	return atkValue;
}
