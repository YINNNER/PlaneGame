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
	void initEnemyBoss(std::string name = "enemy3", int level = 5);

	void enemyBossMove(float dt);
	//场景切换
	void onEnterTransitionDidFinish();
	//boss技能
	void initBossSkill_1(std::string name);
	void initEnemyBoss_1Little(std::string name);
private:
	//获得随机数
	int getRandomNumber(int a, int b);
	//血量
	int enemyHP;
	//攻击
	int enemyAttack;
};

