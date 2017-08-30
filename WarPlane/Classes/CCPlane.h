#pragma once
#include"cocos2d.h"
#include"Equip.h"
USING_NS_CC;
class CCPlane :public Sprite {
public:
	CREATE_FUNC(CCPlane);
	virtual bool init();
	void setImg(const char * filename);
	void setAttri(int attack, int hp,  int speed,int grade);
	void changeAttri();
	void changeAtk(int atk);
	void changeHp(int hp);
	void changeSpd(int spd);
	void changeExp(int exp);
	int getMaxHp();
	int getAtk();
	int getHp();
	int getSpd();
	int getExp();
	int getGrade();
	int getType();
	void setType(int type);
	void setGrade(int grade);
	void setExp(int exp);
	void removePlane(float dt);
	void plane_death();
	void hero_death();
	void removeHero(float dt);
	void setEquip(Equip * _equip);
	void removeEquip(Equip * _equip);
	Vector<Equip *>equip_list;
protected:
	int attack;
	int hp;
	int exp;
	int speed;
	int grade;
	Sprite * planeImg;
	int type;
};
