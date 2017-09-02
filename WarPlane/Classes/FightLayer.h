#pragma once
#include "cocos2d.h"
#include"CCPlane.h"
#include"Bullet.h"
#include"Enemy.h"
#include"UserInfo.h"
#include"Supply.h"
USING_NS_CC;
class FightLayer :
	public Layer
{
public:
	FightLayer();
	~FightLayer();
	CREATE_FUNC(FightLayer);
	virtual bool init();
	void setPlayer(UserInfo &user);
	virtual void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
	virtual void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
	virtual void update(float dt);
	void addSupply(float dt);
	void addBullet(int bType);
	void is_crash(float dt);
	long getCurrentTime();

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

	void removeAnimation1(float dt);
	void removeAnimation2(float dt);
	void closeWhite(float dt);
	void addHp(float dt);

	void dropEquip(Enemy * plane);
	void drawEquip(float dt);

	void addEnemy(float dt);
	void addBoss();
	void backMove(float);
	void bossSkill(float);
	void bossSkill_1(float);
	void bossSkill_2(float);
	void bossSkill_3(float);


	void plane_death(Enemy * enemy);
	UserInfo user;
	void showSkillCD1(float dt);
	void showSkillCD2(float dt);
    void showDamage(Supply * spy);
    void removeMetor(float);
    void onEnter();
    void getGameLevel(int l);
	void bossHpChange();
	void addResault(float);
	void addResault_2(float);
	void addResault_3(float);
	
	Vector<Sprite *>ani;
private:
	Sprite * fightImg;
	Sprite * fightImg2;
	CCPlane * player_1;
	EventKeyboard::KeyCode key;
	EventKeyboard::KeyCode atkKey;
	int scoreValue;
	time_t secTime;
	int minTime;
	Label * score;
	Label * hpLabel;
	Label * grade;
	Label * time;
	Label * pause;
	Label * attarkLabel;
	Menu * menu;
	Sprite * shield;
	Sprite * hpSprite;
	Sprite * expSprite;
	Sprite * gameOver;
	Bullet * skillImg;
	Sprite * Anim1;
	Sprite * Anim2;
	Sprite * skill_11;
	Sprite * skill_22;
	Sprite * white;
    Sprite * metors;
	Sprite * bossHp;
	Sprite * bossTips;
	Enemy * boss;
	int bossExist;
	bool skill2_1;
	bool skill1_1;
	bool skill3_1;
    Sprite * CD1;
    Sprite * CD2;
	int cd1;
	int cd2;
    int gameLevel;
	int bossMaxHp;
};


