#pragma once
#include "cocos2d.h"
#include"CCPlane.h"

USING_NS_CC;
class FightLayer :
	public Layer
{
public:
	FightLayer();
	~FightLayer();
	CREATE_FUNC(FightLayer);
	virtual bool init();
	void setPlayer(int cType);
	virtual void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
	virtual void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
	virtual void update(float dt);
	void addSupply(float dt);
	void addBullet(int bType);
	void addEnemyPlane(int playerLevel);
	void is_crash(float dt);
	long getCurrentTime();
	void onEnterTransitionDidFinish();
	void openSkillU();
	void closeSkillU(float dt);
private:
	Sprite * fightImg;
	CCPlane * player_1;
	EventKeyboard::KeyCode key;
	int scoreValue;
	Label * score;
	Label * hp;
	Label * exp;
	Label * grade;
	Sprite * shield;
};


