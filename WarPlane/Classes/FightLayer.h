#pragma once
#include "cocos2d.h"
#include"CCPlane.h"
#include"Bullet.h"

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
	void openSkillI();

	void closeSkillU(float dt);
	void closeSkillI(float dt);

	void hpChange();
	void expChange();
	void goToGameOver(int value);
	void timeSche(float dt);
	void goToSave(Ref * psender);
	void goToMap(Ref * psender);
	void gamePause();
	void goToBack(Ref * psender);
	void goToHelp(Ref * psender);
	void goToOption(Ref * psender);
	void exitGame(Ref * psender);
	void addSkill(int i);

	void removeAnimation(float dt);
	void closeWhite(float dt);
	void addHp(float dt);
private:
	Sprite * fightImg;
	CCPlane * player_1;
	EventKeyboard::KeyCode key;
	int scoreValue;
	time_t secTime;
	int minTime;
	Label * score;
	Label * hp;
	Label * exp;
	Label * grade;
	Label * time;
	Label * pause;
	Menu * menu;
	Sprite * shield;
	Sprite * hpSprite;
	Sprite * expSprite;
	Sprite * gameOver;
	Bullet * skillImg;
	Sprite * Anim;
	Sprite * skill_1;
	Sprite * skill_2;
	Sprite * white;

};


