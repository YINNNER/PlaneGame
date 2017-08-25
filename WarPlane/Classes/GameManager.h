#pragma once
#include"CCPlane.h"
#include"Bullet.h"
#include"Supply.h"
class GameManager
{
public:
	GameManager();
	~GameManager();
	static GameManager* getInstance();
	static void removeInstance();
	void setPlane(CCPlane * plane);
	void setBullet(Bullet * bullet);
	void setSupply(Supply * supply);
	void removePlane(CCPlane * plane);
	void removeBullet(Bullet * bullet);
	void removeSupply(Supply * supply);
	Vector<Bullet *>& getBulletList();
	Vector<CCPlane *>& getPlaneList();
	Vector<Supply *>& getSupplyList();
	Vector<Bullet *>bullet_list;
	Vector<CCPlane *>plane_list;
	Vector<Supply *>supply_list;
private:
	static GameManager * manager_;
};

