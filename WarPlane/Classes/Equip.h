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
	int getEquipNum();
	int getImpAtk();
	int getImpHp();
	int getImpSpd();
	int getEquipType();

	CREATE_FUNC(Equip);

	//static Equip * createWithSpriteFrameName(const char * spriteFrameName);

private:
	int _ImpAtk;
	int _ImpHp;
	int _ImpSpd;
	int _EquipNum;
	char _EquipType;
	Sprite * _EquipImg;
};

