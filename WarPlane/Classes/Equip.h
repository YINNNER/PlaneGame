#pragma once
#include"cocos2d.h"
using namespace cocos2d;
class Equip :public Node
{
public:
	virtual bool init();
	void setEquipNum(int);
	void setEquipImg(const char * filename);
	void setType(int);
	void setEHp(int);
	void setEAtk(int);
	void setESpd(int);
	int getEquipNum();
	int getEAtk();
	int getEHp();
	int getESpd();
	int getEquipType();
	int getImpHp();
	int getImpSpd();
	int getImpAtk();

	CREATE_FUNC(Equip);

	//static Equip * createWithSpriteFrameName(const char * spriteFrameName);

private:
	int _ImpAtk;
	int _ImpHp;
	int _ImpSpd;
	int _EquipNum;

	int EHp;
	int EAtk;
	int ESpd;

	char _EquipType;
	Sprite * _EquipImg;
};

