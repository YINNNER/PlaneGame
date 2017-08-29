#pragma once
#include"cocos2d.h"
#include"Equip.h"
USING_NS_CC;
class CCPlane :public Sprite {
public:
	CREATE_FUNC(CCPlane);
	virtual bool init();
	void setImg(const char * filename);
	void setAttri(int attack, int hp, int armor, int speed,int grade);
	void changeAttri(int attack, int hp, int armor, int speed, int grade);
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
	void removePlane(float dt);
	void plane_death();
	void hero_death();
	void removeHero(float dt);
private:
	int attack;
	int hp;
	int exp;
	int speed;
	int grade;
	Sprite * planeImg;
	int type;
	Equip * planeEquip;
};
