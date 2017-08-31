#include "Equip.h"
void Equip::setType(int  type) {
	this->type=type;
	switch (type) {
	case 1:
		_ImpAtk = 0;
		_ImpHp = 10;
		_ImpSpd = 0;
		this->setEquipImg("res/UI/plane_parts/playerShip1_blue_02.png");
		break;
	case 2:
		_ImpAtk = 0;
		_ImpHp = 50;
		_ImpSpd = 0;
		this->setEquipImg("res/UI/plane_parts/playerShip1_orange_02.png");
		break;
	case 3:
		_ImpAtk = 0;
		_ImpHp = 100;
		_ImpSpd = 0;
		this->setEquipImg("res/UI/plane_parts/playerShip1_red_02.png");
		break;
	case 4:
		_ImpAtk = 10;
		_ImpHp = 0;
		_ImpSpd = 0;
		this->setEquipImg("res/UI/plane_parts/playerShip1_blue_01.png");
		break;
	case 5:
		_ImpAtk = 50;
		_ImpHp = 0;
		_ImpSpd = 0;
		this->setEquipImg("res/UI/plane_parts/playerShip1_orange_01.png");
		break;
	case 6:
		_ImpAtk = 100;
		_ImpHp = 0;
		_ImpSpd = 0;
		this->setEquipImg("res/UI/plane_parts/playerShip1_red_01.png");
		break;
	case 7:
		_ImpAtk = 0;
		_ImpHp = 0;
		_ImpSpd = 10;
		this->setEquipImg("res/UI/plane_parts/playerShip1_blue_04.png");
		break;
	case 8:
		_ImpAtk = 0;
		_ImpHp = 0;
		_ImpSpd = 50;
		this->setEquipImg("res/UI/plane_parts/playerShip1_orange_04.png");
		break;
	case 9:
		_ImpAtk = 0;
		_ImpHp = 0;
		_ImpSpd = 100;
		this->setEquipImg("res/UI/plane_parts/playerShip1_red_04.png");
		break;
	}
}
bool Equip::init() {
	_ImpAtk = 0;
	_ImpHp = 0;
	_ImpSpd = 0;
	return true;
}
int Equip::getEAtk() {
	return _ImpAtk;
}
int Equip::getEHp() {
	return _ImpHp;
}
int Equip::getESpd() {
	return _ImpSpd;
}
int Equip::getEquipType() {
	return type;
}
void Equip::setEquipImg(const char * filename) {
	equipImg = Sprite::create(filename);
	this->addChild(equipImg);
}