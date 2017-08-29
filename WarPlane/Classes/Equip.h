#pragma once
#include"cocos2d.h"
USING_NS_CC;
class Equip :public Node {
public:
	CREATE_FUNC(Equip);
	virtual bool init();

	void setType(int);
	int getEAtk();
	int getEHp();
	int getESpd();
	int getEquipType();
	void setEquipImg(const char * filename);
private:
	int _ImpAtk;
	int _ImpHp;
	int _ImpSpd;
	int type;
	Sprite * equipImg;
};