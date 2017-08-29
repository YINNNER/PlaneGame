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
	//��ʼ���л�
	void initEnemy1(std::string name = "enemy1", int level = 1);
	void initEnemy2(std::string name = "enemy1", int level = 1);
	void initEnemyBoss(std::string name = "enemy3", int level = 5);

	void enemyBossMove(float dt);
	//�����л�
	void onEnterTransitionDidFinish();
	//boss����
	void initBossSkill_1(std::string name);
	void initEnemyBoss_1Little(std::string name);
private:
	//��������
	int getRandomNumber(int a, int b);
	//Ѫ��
	int enemyHP;
	//����
	int enemyAttack;
};

