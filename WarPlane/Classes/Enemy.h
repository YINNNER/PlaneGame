#pragma once
#include"cocos2d.h"
#include "CCPlane.h"
USING_NS_CC;
class Enemy :public CCPlane {
public:
	CREATE_FUNC(Enemy);
	virtual bool init();
	void planeMove_1();
	void planeMove_2();
	int getRandomNumber(int a, int b);
	void setEnemyImg();
	void plane_death();
	void removePlane(float dt);
public:
	Enemy();
	~Enemy();
private:

};
