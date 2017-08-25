#pragma once
#include "cocos2d.h"
#include"CCPlane.h"
#include"SceneManager.h"

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
	void addEnemyPlane(float dt);
	void is_crash(float dt);
	long getCurrentTime();
	void addSkill(int i);
	SceneManager * tsm;
private:
	Sprite * fightImg;
	CCPlane * player_1;
	EventKeyboard::KeyCode key;
};

