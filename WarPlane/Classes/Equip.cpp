#include "Equip.h"


void Equip::setType(int  type) {
	switch (type) {
	case 1:
		_ImpAtk = 0;
		_ImpHp = 100;
		_EquipNum = 0;
		_ImpSpd = 0;
		break;
	
	case 2:
		_ImpAtk = 0;
		_ImpHp = 0;
		_EquipNum = 0;
		_ImpSpd = 100;

		break;
	
	case 3:
		_ImpAtk = 0;
		_ImpHp = 0;
		_EquipNum = 0;
		_ImpSpd = 100;

		break;
	}
		
	

}

bool Equip::init() {
	_ImpAtk = 0;
	_ImpHp = 0;
	_EquipNum = 0;
	_ImpSpd = 0;
	return true;
}

void Equip::setEquipImg(const char * filename) {
	_EquipImg = Sprite::create(filename);
	this->addChild(_EquipImg);
	setContentSize(_EquipImg->getContentSize());
}

int Equip::getEquipNum() {
	return _EquipNum;
}

int Equip::getEquipType() {
	return _EquipType;
}

void Equip::setEquipNum(int equipNum) {
	_EquipNum = equipNum;
	//如果获得该装备数量+1
}

int Equip::getImpAtk()
{
	return _ImpAtk;
}

int Equip::getImpHp()
{
	return _ImpHp;
}

int Equip::getImpSpd()
{
	return _ImpSpd;
}





