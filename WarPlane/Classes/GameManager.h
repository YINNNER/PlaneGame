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
	void removePlane(enemyPlane * plane);
	void removeBullet(Bullet * bullet);
	void removeSupply(Supply * supply);
	Vector<Bullet *>& getBulletList();
	Vector<enemyPlane *>& getPlaneList();
	Vector<Supply *>& getSupplyList();
	Vector<Bullet *>bullet_list;
	Vector<enemyPlane *>plane_list;
	Vector<Supply *>supply_list;
private:
	static GameManager * manager_;
};

