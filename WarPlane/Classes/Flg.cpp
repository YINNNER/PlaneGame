#include "Flg.h"



Flg::Flg()
{
}


Flg::~Flg()
{
}
bool Flg::init() {
	this->hp = 0;
	this->armor = 0;
	return true;
}

void Flg::setAttri(int hp, int armor)
{
	this->hp = hp;
	this->armor = armor;
}

void Flg::changeAttri(int hp, int armor)
{
	this->hp += hp;
	this->armor += armor;
}

void Flg::setFlgImg(const char * filename)
{
	flgImg = Sprite::create(filename);
}

int Flg::getHp()
{
	return hp;
}

int Flg::getArmor()
{
	return armor;
}
