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
	void setHp(int hp);
	void onEquip(Equip * _equip);
	void hero_death();
	void removeHero(float dt);
	void setEquip(Equip * _equip);
	void removeEquip(Equip * _equip);
	void setEquip_2(Equip * _equip);
	void removeEquip_2(Equip * _equip);
	void putOnEquip_1(int type);
	void putOnEquip_2(int type);
	void putOnEquip_3(int type);
	Vector<Equip *>equip_list;
	Vector<Equip *>equip_list_2;
protected:
	int attack;
	int hp;
	int exp;
	int speed;
	int grade;
	Sprite * equip_1;
	Sprite * equip_2;
	Sprite * equip_3;
	Sprite * equip_1_1;
	Sprite * planeImg;
	int type;
};
