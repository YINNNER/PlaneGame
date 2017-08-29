#pragma once
#include"enemyPlane.h"
#include"Bullet.h"
#include"Supply.h"
class GameManager
{
public:
	GameManager();
	~GameManager();
	static GameManager* getInstance();
	static void removeInstance();
	void setPlane(enemyPlane * plane);
	void setBullet(Bullet * bullet);
	void setSupply(Supply * supply);
	void setSkill(Bullet * skill);
	void removePlane(enemyPlane * plane);
	void removeBullet(Bullet * bullet);
	void removeSupply(Supply * supply);
	void removeSkill(Bullet * skill);
	Vector<Bullet *>& getBulletList();
	Vector<Bullet *>& getSkillList();
	Vector<enemyPlane *>& getPlaneList();
	Vector<Supply *>& getSupplyList();
	Vector<Bullet *>bullet_list;
	Vector<enemyPlane *>plane_list;
	Vector<Supply *>supply_list;
	Vector<Bullet *>skill_list;
private:
	static GameManager * manager_;
};

