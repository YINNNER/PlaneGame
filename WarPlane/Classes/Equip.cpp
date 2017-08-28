#include "Equip.h"
using namespace std;

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
		_ImpHp = 500;
		_EquipNum = 0;
		_ImpSpd = 0;

		break;

	case 3:
		_ImpAtk = 0;
		_ImpHp = 1000;
		_EquipNum = 0;
		_ImpSpd = 0;

		break;
	
	case 4:
		_ImpAtk = 100;
		_ImpHp = 0;
		_EquipNum = 0;
		_ImpSpd = 0;

		break;

	case 5:
		_ImpAtk = 500;
		_ImpHp = 0;
		_EquipNum = 0;
		_ImpSpd = 0;

		break;

	case 6:
		_ImpAtk = 1000;
		_ImpHp = 0;
		_EquipNum = 0;
		_ImpSpd = 0;

		break;
	
	case 7:
		_ImpAtk = 0;
		_ImpHp = 0;
		_EquipNum = 0;
		_ImpSpd = 100;

		break;

	case 8:
		_ImpAtk = 0;
		_ImpHp = 0;
		_EquipNum = 0;
		_ImpSpd = 500;

		break;


	case 9:
		_ImpAtk = 0;
		_ImpHp = 0;
		_EquipNum = 0;
		_ImpSpd = 1000;

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




int Equip::getEquipNum() {
	return _EquipNum;
}

int Equip::getEquipType() {
	return _EquipType;
}

int Equip::getImpSpd()
{
	return _ImpSpd;
}

int Equip::getImpAtk()
{
	return _ImpAtk;
}

int Equip::getImpHp()
{
	return _ImpHp;
}

void Equip::setEquipNum(int equipNum) {
	_EquipNum = equipNum;
	//如果获得该装备数量+1
}

int Equip::getEAtk()
{
	return EAtk;
}

int Equip::getEHp()
{
	return EHp;
}

int Equip::getESpd()
{
	return ESpd;
}







