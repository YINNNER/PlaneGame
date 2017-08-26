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
	//�л���ը
	void enemyBlowUp();
	//�л��ƶ�
	void enemyMoveY(float dt);     //����
	void enemyRemove(float dt);
	//�����л�
	void onEnterTransitionDidFinish();
	void removePlane(float dt);
	void plane_death();
private:
	//�л�����
	std::string enemyName;
	//��������
	int getRandomNumber(int a, int b);
	//�л�ƫ��
	const int OFFSET = 1;
	//Ѫ��
	int HP;
	//����
	int armor;
	//�ȼ�
	int Level;
};

