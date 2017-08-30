#pragma once
#include"Enemy.h"
#include"Bullet.h"
#include"Supply.h"
class GameManager
{
public:
	GameManager();
	~GameManager();
	static GameManager* getInstance();
	static void removeInstance();
	void setPlane(Enemy * plane);
	void setBullet(Bullet * bullet);
	void setEBullet(Bullet * bullet);
	void setSupply(Supply * supply);
	void setSkill(Bullet * skill);
	void removePlane(Enemy * plane);
	void removeBullet(Bullet * bullet);
	void removeEBullet(Bullet * bullet);
	void removeSupply(Supply * supply);
	void removeSkill(Bullet * skill);
	Vector<Bullet *>& getBulletList();
	Vector<Bullet *>& getEBulletList();
	Vector<Bullet *>& getSkillList();
	Vector<Enemy *>& getPlaneList();
	Vector<Supply *>& getSupplyList();
	Vector<Bullet *>bullet_list;
	Vector<Bullet *>Ebullet_list;
	Vector<Enemy *>plane_list;
	Vector<Supply *>supply_list;
	Vector<Bullet *>skill_list;
private:
	static GameManager * manager_;
};

