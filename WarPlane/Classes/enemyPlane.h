#pragma once
#include"cocos2d.h"
#include"CCPlane.h"
USING_NS_CC;
class enemyPlane:public CCPlane{
public:
	CREATE_FUNC(enemyPlane);
	virtual bool init();
public:
	enemyPlane();
	~enemyPlane();
public:
	//初始化敌机
	void initEnemy1(std::string name = "enemy1", int level = 1);
	void initEnemy2(std::string name = "enemy1", int level = 1);
	//敌机爆炸
	void enemyBlowUp();
	//敌机移动
	void enemyMoveY(float dt);     //纵轴
	void enemyRemove(float dt);
	//场景切换
	void onEnterTransitionDidFinish();
	void removePlane(float dt);
	void plane_death();
private:
	//敌机名字
	std::string enemyName;
	//获得随机数
	int getRandomNumber(int a, int b);
	//敌机偏移
	const int OFFSET = 1;
	//血量
	int HP;
	//护甲
	int armor;
	//等级
	int Level;
};

