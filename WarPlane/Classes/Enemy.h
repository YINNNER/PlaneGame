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
	void removePlane();
	void bossMove();
	void enemyBossMove(float dt);
	void enemyBossMove_1(float dt);
	void boss_death();
public:
	Enemy();
	~Enemy();
private:

};