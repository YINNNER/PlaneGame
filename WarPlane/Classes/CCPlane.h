#pragma once
#include"cocos2d.h"
#include"Arms.h"
#include"Fuel.h"
#include"Flg.h"
USING_NS_CC;
class CCPlane :public Sprite {
public:
	CREATE_FUNC(CCPlane);
	virtual bool init();
	void setImg(const char * filename);
	void setAttri(int attack, int hp, int armor, int speed,int grade);
	void changeAtk(int atk);
	void changeHp(int hp);
	void changeAr(int armor);
	void changeSpd(int spd);
	void changeExp(int exp);
	int getAtk();
	int getHp();
	int getAr();
	int getSpd();
	int getExp();
	int getGrade();
	void removePlane(float dt);
	void plane_death();
	void hero_death();
	void removeHero(float dt);
private:
	int attack;
	int hp;
	int armor;
	int exp;
	int speed;
	int grade;
	Arms * planeArms;
	Fuel * planeFuel;
	Flg * planeFlg;
	Sprite * planeImg;
	

};
