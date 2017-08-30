﻿#include "FightLayer.h"
#include"Supply.h"
#include"GameManager.h"
#include"Bullet.h"
#include"SaveLayer.h"
#include"MapLayer.h"
FightLayer::FightLayer()
{
}

FightLayer::~FightLayer()
{

}
bool FightLayer::init() {
	auto visibleSize = Director::getInstance()->getVisibleSize();
	boss = Enemy::create();
	boss->setAttri(50, 2000, 50, 1);
	TTFConfig ttfConfig("fonts/Marker Felt.ttf", 24);
	bosshp = Label::createWithTTF(ttfConfig, CCString::createWithFormat("boss:%d", boss->getHp())->getCString());
	bosshp->setColor(Color3B::RED);
	bosshp->setPosition(100, visibleSize.height - 20);
	this->addChild(bosshp, 4);
	bossExist = 0;
	skill2_1 = false;
	skill1_1 = false;
	skill3_1 = false;

	SpriteBatchNode *batchNode = SpriteBatchNode::create("res/UI/a3Game/11.png");
	this->addChild(batchNode);
	fightImg = Sprite::createWithTexture(batchNode->getTexture());
	//fightImg->setScale(1.1);
	fightImg->setAnchorPoint(Point::ZERO);
	fightImg->setPosition(Vec2(Point::ZERO));
	//fightImg->getTexture()->setAliasTexParameters();
	this->addChild(fightImg, 1);
	fightImg2 = Sprite::createWithTexture(batchNode->getTexture());
	//fightImg2->setScale(1.1);
	fightImg2->setAnchorPoint(Point::ZERO);
	fightImg2->setPosition(Point(fightImg->getPositionX(), fightImg->getPositionY() + fightImg->getContentSize().height));
	//fightImg2->getTexture()->setAliasTexParameters();
	this->addChild(fightImg2, 1);
	this->schedule(schedule_selector(FightLayer::backMove));



	auto skillBar = Sprite::create("res/skillBar.png");
	this->addChild(skillBar, 1);
	skill_1 = Sprite::create("res/skill_1.png");
	skill_2 = Sprite::create("res/skill_2.png");
	auto barSize = skillBar->getContentSize();
	skillBar->setAnchorPoint(Point::ZERO);
	skillBar->setPosition(20, 50);
	skillBar->setScaleX(0.5);
	skill_1->setScaleX(2);
	skill_2->setScaleX(2);
	skill_1->setPosition(barSize.width / 4, barSize.height / 2);
	skill_2->setPosition(barSize.width / 1.5, barSize.height / 2);
	skillBar->addChild(skill_1, 2);
	skillBar->addChild(skill_2, 2);


	
	scoreValue = 0;
	score = Label::createWithTTF(ttfConfig, CCString::createWithFormat("score:%d", scoreValue)->getCString());
	score->setColor(Color3B::RED);
	score->setPosition(visibleSize.width -100, visibleSize.height -20);
	this->addChild(score, 3);

	secTime = 0;
	minTime = 0;
	time = Label::createWithTTF(ttfConfig, CCString::createWithFormat("time:%d:%d",minTime, secTime)->getCString());
	time->setColor(Color3B::RED);
	time->setPosition(visibleSize.width - 100, visibleSize.height - 40);
	this->addChild(time, 3);

	Sprite * hpIco = Sprite::create("res/UI/a3Game/shield_bronze.png");
	hpIco->setAnchorPoint(Vec2(1, 0));
	hpIco->setPosition(Vec2(visibleSize.width, 20));
	this->addChild(hpIco,3);
	hpSprite = Sprite::create("res/RedBar.png");
	hpSprite->setAnchorPoint(Vec2(1, 0));
	hpSprite->setPosition(Vec2(visibleSize.width - 40, 30));
	Sprite * hpImg = Sprite::create("res/EmptyBar.png");
	hpImg->setAnchorPoint(Vec2(1, 0));
	hpImg->setPosition(Vec2(visibleSize.width-40,30));
	this->addChild(hpImg,3);
	this->addChild(hpSprite, 4);

	expSprite = Sprite::create("res/expBar.png");
	expSprite->setAnchorPoint(Vec2(0, 0));
	expSprite->setScaleX(0);
	expSprite->setPosition(Vec2(0, 0));
	Sprite * expImg = Sprite::create("res/expEmpty.png");
	expImg->setAnchorPoint(Vec2(0, 0));
	expImg->setPosition(Vec2(0 ,0));
	this->addChild(expImg, 3);
	this->addChild(expSprite, 4);

	auto listenerKeyboard = EventListenerKeyboard::create();
	listenerKeyboard->onKeyPressed = CC_CALLBACK_2(FightLayer::onKeyPressed, this);
	listenerKeyboard->onKeyReleased = CC_CALLBACK_2(FightLayer::onKeyReleased, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listenerKeyboard, this);
	this->scheduleUpdate();
	this->schedule(schedule_selector(FightLayer::addSupply), 5.0f);
	this->schedule(schedule_selector(FightLayer::is_crash));
	this->schedule(schedule_selector(FightLayer::timeSche),1.0f);
	return true;
}
void FightLayer::backMove(float)
{
	//通过不断改变背景y轴的位置来实现背景滚动  
	fightImg->setPositionY(fightImg->getPositionY() - 2);
	fightImg2->setPositionY(fightImg2->getPositionY() - 2);
	//判断条件，当背景一滚出屏幕的时候让背景二接在背景一后面，背景二同理  
	if (fightImg->getPositionY() == -fightImg->getContentSize().height)
	{
		fightImg->setPositionY(fightImg2->getPositionY() + fightImg2->getContentSize().height);
	}
	else if (fightImg2->getPositionY() == -fightImg2->getContentSize().height)
	{
		fightImg2->setPositionY(fightImg->getPositionY() + fightImg->getContentSize().height);
	}
}
void FightLayer::bossSkill(float)
{
	Bullet * bullet_1 = Bullet::create();
	bullet_1->setPosition(boss->getPosition());
	bullet_1->setType(2);
	bullet_1->setBulletImg("res/bomb.png");
	bullet_1->setScale(0.5);
	this->addChild(bullet_1, 3);
	GameManager::getInstance()->setEBullet(bullet_1);
	if (player_1->getGrade()<10)
	{
		this->schedule(schedule_selector(FightLayer::bossSkill_1), 10.0f);
	}
	else if (player_1->getGrade()<15)
	{
		this->schedule(schedule_selector(FightLayer::bossSkill_2), 10.0f);
	}
	else {
		this->schedule(schedule_selector(FightLayer::bossSkill_3), 10.0f);
	}
}
void FightLayer::bossSkill_1(float)
{
	for (int i = 0; i < 10; i++)
	{
		Bullet * bullet_1 = Bullet::create();
		bullet_1->setPosition(boss->getPositionX()*i/10,boss->getPositionY());
		bullet_1->setType(2);
		bullet_1->setBulletImg("res/bomb.png");
		bullet_1->setScale(0.5);
		this->addChild(bullet_1, 3);
		GameManager::getInstance()->setEBullet(bullet_1);
	}	
}
void FightLayer::bossSkill_2(float)
{
	player_1->changeHp(-player_1->getHp() / 3);
}
void FightLayer::bossSkill_3(float)
{
	for (int i = 0; i < 10; i--)
	{
		Enemy * enemy_1 = Enemy::create();
		enemy_1->setType(3);
		enemy_1->setGrade(player_1->getGrade());
		GameManager::getInstance()->setPlane(enemy_1);
		this->addChild(enemy_1, 3);
	}
}

void FightLayer::onExit()
{
	auto bullet_list_1 = GameManager::getInstance()->getBulletList();
	auto plane_list_1 = GameManager::getInstance()->getPlaneList();
	auto supply_list_1 = GameManager::getInstance()->getSupplyList();
	auto skill_list_1 = GameManager::getInstance()->getSkillList();
	Layer::onExit();
	for (int i = bullet_list_1.size()-1; i >=0; i--)
	{
		GameManager::getInstance()->removeBullet(bullet_list_1.at(i));
	}
	for (int i = plane_list_1.size() - 1; i >= 0; i--)
	{
		GameManager::getInstance()->removePlane(plane_list_1.at(i));
	}
	for (int i = supply_list_1.size() - 1; i >= 0; i--)
	{
		GameManager::getInstance()->removeSupply(supply_list_1.at(i));
	}
	for (int i = skill_list_1.size() - 1; i >= 0; i--)
	{
		GameManager::getInstance()->removeSkill(skill_list_1.at(i));
	}
}
void FightLayer::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event)
{
	if (keyCode== EventKeyboard::KeyCode::KEY_W||keyCode== EventKeyboard::KeyCode::KEY_A||keyCode== EventKeyboard::KeyCode::KEY_S||keyCode== EventKeyboard::KeyCode::KEY_D)
	{
		key = keyCode;
	}
	else
	{
		atkKey = keyCode;
	}
	
}

void FightLayer::onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event)
{
	if (key==keyCode)
	{
		key = EventKeyboard::KeyCode::KEY_NONE;
	}
	else if (atkKey==keyCode)
	{
		atkKey = EventKeyboard::KeyCode::KEY_NONE;
	}
}

void FightLayer::update(float dt)
{
	static Size visibleSize = Director::getInstance()->getVisibleSize();
	switch (key) {
	case EventKeyboard::KeyCode::KEY_W:
		if (visibleSize.height - player_1->getPositionY() < player_1->getContentSize().height / 2) {
		}
		else
		{
			player_1->setPositionY(player_1->getPositionY() + 5);
		}
		break;
	case EventKeyboard::KeyCode::KEY_S:
		if (player_1->getPositionY() < player_1->getContentSize().height / 2)
		{

		}
		else {
			player_1->setPositionY(player_1->getPositionY() - 5);
		}
		break;
	case EventKeyboard::KeyCode::KEY_A:
		if (player_1->getPositionX() < player_1->getContentSize().width / 2) {
		}
		else {
			player_1->setPositionX(player_1->getPositionX() - 5);
		}
		break;
	case EventKeyboard::KeyCode::KEY_D:
		if (visibleSize.width - player_1->getPositionX() < player_1->getContentSize().width / 2)
		{

		}
		else {
			player_1->setPositionX(player_1->getPositionX() + 5);
		}
		break;
	}
	switch (atkKey)
	{
	case EventKeyboard::KeyCode::KEY_J:
		static long interval = this->getCurrentTime();
		if ((this->getCurrentTime() - interval)<250)
		{
			break;
		}
		else
		{
			if (skill2_1)
			{
				this->addBullet(1);
				this->addBullet(1);
				this->addBullet(1);
			}
			else
			{
				this->addBullet(1);
			}
			interval = this->getCurrentTime();
		}
		break;
	case EventKeyboard::KeyCode::KEY_U:
		static long interval_1 = this->getCurrentTime();
		if ((this->getCurrentTime() - interval_1)<10000)
		{
			break;
		}
		else
		{
			openSkillU();
			interval_1 = this->getCurrentTime();
		}
		break;
	case EventKeyboard::KeyCode::KEY_I:
		static long interval_2 = this->getCurrentTime();
		if ((this->getCurrentTime() - interval_2)<20000)
		{
			break;
		}
		else
		{
			openSkillI();
			interval_2 = this->getCurrentTime();
		}
		break;
	case EventKeyboard::KeyCode::KEY_ESCAPE:
		this->gamePause();
		break;
	default:
		break;
	}
}

void FightLayer::addSupply(float dt)
{
	static Size visibleSize = Director::getInstance()->getVisibleSize();
	int temp = rand();
	if (temp%2==0)
	{
		Supply * meteors_1 = Supply::create();
		
		if (temp%4<2)
		{
			meteors_1->setSpt(3);
			meteors_1->setPosition(Vec2(0, rand() % ((int)visibleSize.height / 2) + (int)visibleSize.height / 2));
		}
		else {
			meteors_1->setSpt(2);
			meteors_1->setPosition(Vec2(visibleSize.width, rand() % ((int)visibleSize.height / 2) + (int)visibleSize.height / 2));
		}
		this->addChild(meteors_1,3);
		GameManager::getInstance()->setSupply(meteors_1);
	}
	else
	{
		Supply * spy_1 = Supply::create();
		spy_1->setSpt(1);   //rand()%n;
		spy_1->setPosition(Vec2(rand() % (int)visibleSize.width, visibleSize.height));
		this->addChild(spy_1,3);
		GameManager::getInstance()->setSupply(spy_1);
	}
}

void FightLayer::addBullet(int bType)
{
	Bullet * bullet_1 = Bullet::create();
	bullet_1->setType(1);
	bullet_1->setPosition(player_1->getPosition());
	bullet_1->setBulletImg("res/fire01.png");
	this->addChild(bullet_1, 3);
	GameManager::getInstance()->setBullet(bullet_1);
}

void FightLayer::is_crash(float dt)
{
	auto Ebullet_list_1 = GameManager::getInstance()->getEBulletList();
	auto bullet_list_1 = GameManager::getInstance()->getBulletList();
	auto plane_list_1 = GameManager::getInstance()->getPlaneList();
	auto supply_list_1 = GameManager::getInstance()->getSupplyList();
	auto skill_list_1 = GameManager::getInstance()->getSkillList();
	//敌机碰撞计算
	for (int i = plane_list_1.size() - 1; i >= 0; i--) {
		auto enemy_plane = plane_list_1.at(i);
		auto enemy_size = enemy_plane->getBoundingBox();
		if (enemy_size.intersectsRect(player_1->getBoundingBox()))
		{
			if (skill3_1)
			{
				break;
			}
			else
			{
				plane_death(plane_list_1.at(i));
				player_1->changeHp(-100);
				this->hpChange();
			}
		}
		for (int j = bullet_list_1.size() - 1; j >= 0; j--) {
			
			/*
			if (bossExist == 1)
			{
				CCLOG("%d", bullet_list_1.size());
				if (boss->getBoundingBox().containsPoint(bullet_list_1.at(j)->getPosition()))
				{
					boss->changeHp(-player_1->getAtk()/5);
					CCLOG("%d", boss->getHp());
					bullet_list_1.at(j)->removeBullet();
					if (boss->getHp() <= 0)
					{
						bossExist = 0;
						this->unschedule(schedule_selector(FightLayer::bossSkill));
						boss->removeFromParent();
						if (player_1->getGrade() < 10)
						{
							this->unschedule(schedule_selector(FightLayer::bossSkill_1));
						}
						else if (player_1->getGrade() < 15)
						{
							this->unschedule(schedule_selector(FightLayer::bossSkill_2));
						}
						else {
							this->unschedule(schedule_selector(FightLayer::bossSkill_3));
						}
						this->goToGameOver(2);
					}
				}
			}*/
			if (enemy_size.containsPoint(bullet_list_1.at(j)->getPosition()))
			{
				bullet_list_1.at(j)->removeBullet();
				enemy_plane->changeHp(-(player_1->getAtk()));
				if (enemy_plane->getHp() <= 0)
				{
					if (enemy_plane->getIsBoss()==1)
					{
						bossExist = 0;
						this->unschedule(schedule_selector(FightLayer::bossSkill));
						boss->removeFromParent();
						if (player_1->getGrade() < 10)
						{
							this->unschedule(schedule_selector(FightLayer::bossSkill_1));
						}
						else if (player_1->getGrade() < 15)
						{
							this->unschedule(schedule_selector(FightLayer::bossSkill_2));
						}
						else {
							this->unschedule(schedule_selector(FightLayer::bossSkill_3));
						}
						this->goToGameOver(2);
					}
					else if (rand() % 15 > 13)
					{
						this->dropEquip(plane_list_1.at(i));
					}
					plane_death(plane_list_1.at(i));
					player_1->changeExp(player_1->getGrade());
					this->expChange();
					scoreValue++;
				}
			}
		}
	}
		for (int i = Ebullet_list_1.size() - 1; i >= 0; i--)
		{
			if (skill1_1)
			{
				bullet_list_1.at(i)->removeBullet();
				break;
			}
			else if (skill3_1)
			{
				break;
			}
			else {
				if (player_1->getBoundingBox().containsPoint(Ebullet_list_1.at(i)->getPosition())) {
					player_1->changeHp(-10);
					Ebullet_list_1.at(i)->removeBullet();
					this->hpChange();
				}
			}
		}
		//补给、陨石碰撞计算
		if (supply_list_1.size() > 0) {
			for (int i = supply_list_1.size() - 1; i >= 0; i--)
			{
				auto supply_1 = supply_list_1.at(i);
				if (player_1->getBoundingBox().containsPoint(supply_1->getPosition())) {
					if (supply_1->getType() == 1)
					{
						if (player_1->getMaxHp() > player_1->getHp())
						{
							player_1->changeHp(50);
							this->hpChange();
						}
						scoreValue++;
						supply_1->removeSupply();
					}
					else if (supply_1->getType() == 2 || supply_1->getType() == 3)
					{
						if (skill3_1)
						{
							break;
						}
						else
						{
							player_1->changeHp(-50);
							this->hpChange();
							supply_1->removeSupply();
							player_1->setImg_2();
							player_1->scheduleOnce(schedule_selector(CCPlane::removeMetors), 1.0f);
						}
					}
				}
			}
		}
		if (skill_list_1.size() > 0)
		{
			auto skill_1 = skill_list_1.at(0);
			for (int i = 0; i <= plane_list_1.size() - 1; i++)
			{
				auto enemy_1 = plane_list_1.at(i);

				if (enemy_1->getBoundingBox().containsPoint(skill_1->getPosition()))
				{
					Anim1 = Sprite::create("res/skill1.png");
					Anim1->setScale(3);
					this->addChild(Anim1, 3);
					Anim1->setPosition(skill_1->getPosition());
					auto animation = Animation::create();

					char str[20] = { 0 };
					for (int i = 1; i <= 9; i++)
					{
						sprintf(str, "res/skill%d.png", i);
						animation->addSpriteFrameWithFile(str);
					}
					animation->setDelayPerUnit(0.05f);
					animation->setLoops(1);
					animation->setRestoreOriginalFrame(false);
					auto action = Animate::create(animation);
					Anim1->runAction(action);

					this->scheduleOnce(schedule_selector(FightLayer::removeAnimation1), 0.5f);

					Rect rect = Rect::Rect(enemy_1->getPositionX() - 160, enemy_1->getPositionY() - 160, 320, 320);
					for (int j = 0; j <= plane_list_1.size() - 1; j++)
					{
						auto enemy_2 = plane_list_1.at(j);
						if (rect.containsPoint(enemy_2->getPosition()))
						{
							enemy_2->changeHp(-500);
							if (enemy_2->getHp() <= 0)
							{
								this->dropEquip(enemy_2);
								plane_death(enemy_2);
							}
						}
					}
					skill_1->removeSkill();
					break;
				}
			}
		}
		if (player_1->getHp() <= 0)
		{
			this->goToGameOver(2);
		}
		score->setString(CCString::createWithFormat("score:%d", scoreValue)->getCString());
		grade->setString(CCString::createWithFormat("LV:%d", player_1->getGrade())->getCString());
		hpLabel->setString(CCString::createWithFormat("%d", player_1->getHp())->getCString());
		attarkLabel->setString(CCString::createWithFormat("%d", player_1->getAtk())->getCString());		
		bosshp->setString(CCString::createWithFormat("%d", boss->getHp())->getCString());
}
void FightLayer::removeAnimation1(float dt)
{
	Anim1->removeFromParentAndCleanup(true);
}

void FightLayer::removeAnimation2(float dt)
{
	Anim2->removeFromParentAndCleanup(true);
}

long FightLayer::getCurrentTime()
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return tv.tv_sec * 1000 + tv.tv_usec / 1000;
}

void FightLayer::setPlayer(UserInfo &user) {
	Size visibleSize = Director::getInstance()->getVisibleSize();
	player_1 = CCPlane::create();
	player_1->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	player_1->setType(user.getPlaneType());
	player_1->setExp(user.getExp());
	player_1->setAttri(user.getAtk(),user.getHp(),user.getSpd(),user.getGameLevel());	//坦克
	player_1->setImg(CCString::createWithFormat("res/SpaceShooterRedux/PNG/Planes/playerShip%d_green.png", user.getPlaneType())->getCString());

	this->addChild(player_1, 3);
	TTFConfig ttfConfig("fonts/Marker Felt.ttf", 24);
	grade = Label::createWithTTF(ttfConfig, CCString::createWithFormat("LV:%d", player_1->getGrade())->getCString());
	grade->setColor(Color3B::RED);
	grade->setPosition(Vec2(10, 20));
	this->addChild(grade, 3);

	hpLabel = Label::createWithTTF(ttfConfig, CCString::createWithFormat("%d", player_1->getHp())->getCString());
	hpLabel->setColor(Color3B::RED);
	hpLabel->setPosition(Vec2(hpSprite->getPositionX()-hpSprite->getContentSize().width-hpLabel->getContentSize().width, hpSprite->getPositionY()));
	this->addChild(hpLabel, 3);

	attarkLabel = Label::createWithTTF(ttfConfig, CCString::createWithFormat("%d", player_1->getAtk())->getCString());
	attarkLabel->setColor(Color3B::RED);
	attarkLabel->setPosition(Vec2(50,20));
	this->addChild(attarkLabel, 3);
	this->schedule(schedule_selector(FightLayer::addEnemy),2.0f);
}

void FightLayer::hpChange()
{
	float scalex = ((float)(player_1->getHp())) / ((float)(player_1->getMaxHp()));
	if (scalex > 0)
	{
		hpSprite->setScaleX(scalex);
	}
	else
	{
		hpSprite->setScaleX(0);
	}
}

void FightLayer::expChange()
{
	expSprite->setScaleX(((float)player_1->getExp()) / (10.0*player_1->getGrade()));
}

void FightLayer::goToGameOver(int value)
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	gameOver = Sprite::create("res/UI/a5GameFin/rect.png");
	auto gameOverSize = gameOver->getContentSize();
	Sprite * star_1 = Sprite::create("res/star_gold.png");
	star_1->setPosition(Vec2(gameOverSize.width / 3, gameOverSize.height * 3 / 5));
	star_1->setScale(2);
	Sprite * star_2 = Sprite::create("res/star_gold.png");
	star_2->setPosition(Vec2(gameOverSize.width / 2, gameOverSize.height * 3 / 5));
	star_2->setScale(2);
	Sprite * star_3 = Sprite::create("res/star_gold.png");
	star_3->setPosition(Vec2(gameOverSize.width * 2 / 3, gameOverSize.height * 3 / 5));
	star_3->setScale(2);

	Label * result_1 = Label::createWithTTF("mission failure", "fonts/Marker Felt.ttf", 24);
	result_1->setPosition(Vec2(gameOverSize.width / 2, gameOverSize.height * 4 / 5));
	Label * result_2 = Label::createWithTTF("Mission Success", "fonts/Marker Felt.ttf", 24);
	result_2->setPosition(Vec2(gameOverSize.width / 2, gameOverSize.height * 4 / 5));
	switch (value)
	{
	case 1:
		gameOver->addChild(result_1);
		break;
	case 2:
		gameOver->addChild(result_2);
		if (scoreValue > 30)
		{
		gameOver->addChild(star_1);
		gameOver->addChild(star_2);
		gameOver->addChild(star_3);
		}
		else if (scoreValue > 20)
		{
		gameOver->addChild(star_1);
		gameOver->addChild(star_2);
		}
		else {
		gameOver->addChild(star_1);
		}
		break;
	}
	Label * score = Label::createWithTTF(CCString::createWithFormat("score:%d", scoreValue)->getCString(), "fonts/Marker Felt.ttf", 18);
	score->setPosition(Vec2(gameOverSize.width / 2, gameOverSize.height / 2));
	gameOver->addChild(score);
	gameOver->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));

	MenuItemImage * save = MenuItemImage::create("res/UI/a5GameFin/save.png", "res/UI/a5GameFin/saveS.png", CC_CALLBACK_1(FightLayer::goToSave, this));
	save->setPosition(Vec2(gameOverSize.width / 4, 50));
	MenuItemImage * map = MenuItemImage::create("res/UI/a5GameFin/selectLevel.png", "res/UI/a5GameFin/selectLevelS.png", CC_CALLBACK_1(FightLayer::goToMap, this));
	map->setPosition(Vec2(gameOverSize.width * 3 / 4, 50));
	Menu * menu = Menu::create(save, map, NULL);
	menu->setPosition(Vec2(0, 0));
	menu->setAnchorPoint(Vec2(0, 0));
	gameOver->addChild(menu);
	this->addChild(gameOver, 5);
	player_1->hero_death();
	this->unscheduleUpdate();
	this->unschedule(schedule_selector(FightLayer::addSupply));
	this->unschedule(schedule_selector(FightLayer::is_crash));
	this->unschedule(schedule_selector(FightLayer::timeSche));
}

void FightLayer::timeSche(float dt)
{
	secTime++;
	if (secTime >= 60)
	{
		secTime = 0;
		minTime++;
	}
	time->setString(CCString::createWithFormat("time:%d:%d", minTime, secTime)->getCString());


	auto plane_list_1 = GameManager::getInstance()->getPlaneList();
	for (int i=plane_list_1.size()-1 ; i>=0; i--)
	{
		Bullet * bullet_1 = Bullet::create();
		bullet_1->setPosition(plane_list_1.at(i)->getPosition());
		bullet_1->setType(2);
		bullet_1->setBulletImg("res/SpaceShooterRedux/PNG/Effects/fire07.png");
		bullet_1->setScale(0.5);
		this->addChild(bullet_1, 3);
		GameManager::getInstance()->setEBullet(bullet_1);
	}
}

void FightLayer::goToSave(Ref * psender)
{
	for (int i = player_1->equip_list.size()-1; i >=0; i--)
	{
		switch (player_1->equip_list.at(i)->getEquipType())
		{
		case 1:
			user.set_equip_head_have(1);
			break;
		case 2 :
			user.set_equip_head_b_have(1);
			break;
		case 3:
			user.set_equip_head_c_have(1);
			break;
		case 4:
			user.set_equip_arm_have(1);
			break;
		case 5:
			user.set_equip_arm_b_have(1);
			break;
		case 6:
			user.set_equip_arm_c_have(1);
			break;
		case 7:
			user.set_equip_tail_have(1);
			break;
		case 8:
			user.set_equip_tail_b_have(1);
			break;
		case 9:
			user.set_equip_tail_c_have(1);
			break;
		default:
			break;
		}
		
	}
	SceneManager::goSaveLayer(2, user);
}

void FightLayer::goToMap(Ref * psender)
{
	for (int i = player_1->equip_list.size() - 1; i >= 0; i--)
	{
		switch (player_1->equip_list.at(i)->getEquipType())
		{
		case 1:
			user.set_equip_head_have(1);
			break;
		case 2:
			user.set_equip_head_b_have(1);
			break;
		case 3:
			user.set_equip_head_c_have(1);
			break;
		case 4:
			user.set_equip_arm_have(1);
			break;
		case 5:
			user.set_equip_arm_b_have(1);
			break;
		case 6:
			user.set_equip_arm_c_have(1);
			break;
		case 7:
			user.set_equip_tail_have(1);
			break;
		case 8:
			user.set_equip_tail_b_have(1);
			break;
		case 9:
			user.set_equip_tail_c_have(1);
			break;
		default:
			break;
		}

	}
	SceneManager::goMapLayer(2, user);
}

void FightLayer::gamePause()
{
	this->unscheduleUpdate();
	this->unschedule(schedule_selector(FightLayer::addSupply));
	this->unschedule(schedule_selector(FightLayer::is_crash));
	this->unschedule(schedule_selector(FightLayer::timeSche));
	this->unschedule(schedule_selector(FightLayer::addEnemy));
	this->unschedule(schedule_selector(FightLayer::backMove));
	if (bossExist==1)
	{
		this->unschedule(schedule_selector(FightLayer::bossSkill));
		boss->unschedule(SEL_SCHEDULE(&Enemy::enemyBossMove));
		boss->unschedule(SEL_SCHEDULE(&Enemy::enemyBossMove_1));
	}
	if (player_1->getGrade()<10)
	{
		this->unschedule(schedule_selector(FightLayer::bossSkill_1));
	}
	else if (player_1->getGrade()<15)
	{
		this->unschedule(schedule_selector(FightLayer::bossSkill_2));
	}
	else {
		this->unschedule(schedule_selector(FightLayer::bossSkill_3));
	}

	auto bullet_list_1 = GameManager::getInstance()->getBulletList();
	auto plane_list_1 = GameManager::getInstance()->getPlaneList();
	auto supply_list_1 = GameManager::getInstance()->getSupplyList();
	for (int i = bullet_list_1.size() - 1; i >= 0; i--)
	{
		bullet_list_1.at(i)->unscheduleUpdate();
	}
	for (int i = plane_list_1.size() - 1; i >= 0; i--)
	{
	
		plane_list_1.at(i)->pause();
	}
	for (int i = supply_list_1.size() - 1; i >= 0; i--)
	{
		supply_list_1.at(i)->unscheduleUpdate();
	}
	static Size visibleSize = Director::getInstance()->getVisibleSize();
	pause = Label::createWithSystemFont("GamePause", "", 40);
	pause->setPosition(Vec2(visibleSize.width / 2, visibleSize.height * 3 / 4));
	this->addChild(pause, 5);
	MenuItemImage * backGame = MenuItemImage::create("res/UI/a4GamePause/backGame.png", "res/UI/a4GamePause/backGameS.png", CC_CALLBACK_1(FightLayer::goToBack, this));
	backGame->setPosition(Vec2(visibleSize.width / 2, visibleSize.height * 5 / 8));
	MenuItemImage * load = MenuItemImage::create("res/UI/a4GamePause/load.png", "res/UI/a4GamePause/loadS.png", CC_CALLBACK_1(FightLayer::goToOption, this));
	load->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	MenuItemImage * option = MenuItemImage::create("res/UI/a4GamePause/option.png", "res/UI/a4GamePause/optionS.png", CC_CALLBACK_1(FightLayer::goToHelp, this));
	option->setPosition(Vec2(visibleSize.width / 2, visibleSize.height * 3 / 8));
	MenuItemImage * exit = MenuItemImage::create("res/UI/a4GamePause/exitGame.png", "res/UI/a4GamePause/exitGameS.png", CC_CALLBACK_1(FightLayer::exitGame, this));
	exit->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 5));

	menu = Menu::create(backGame, load, option, exit, NULL);
	menu->setPosition(Point::ZERO);
	this->addChild(menu, 4);
}

void FightLayer::goToBack(Ref * psender)
{
	menu->removeFromParentAndCleanup(true);
	pause->removeFromParentAndCleanup(true);

	this->resume();
	this->scheduleUpdate();
	this->schedule(schedule_selector(FightLayer::addSupply),5.0f);
	this->schedule(schedule_selector(FightLayer::is_crash));
	this->schedule(schedule_selector(FightLayer::timeSche),1.0f);
	this->schedule(schedule_selector(FightLayer::addEnemy),2.0f);
	this->schedule(schedule_selector(FightLayer::backMove));
	if (bossExist==1)
	{
		this->schedule(schedule_selector(FightLayer::bossSkill), 1.0);
		boss->schedule(SEL_SCHEDULE(&Enemy::enemyBossMove));
		boss->schedule(SEL_SCHEDULE(&Enemy::enemyBossMove_1));
	}
	if (player_1->getGrade()<10)
	{
		this->schedule(schedule_selector(FightLayer::bossSkill_1),10.0f);
	}
	else if (player_1->getGrade()<15)
	{
		this->schedule(schedule_selector(FightLayer::bossSkill_2),10.0f);
	}
	else {
		this->schedule(schedule_selector(FightLayer::bossSkill_3),10.0f);
	}
	//this->schedule(SEL_SCHEDULE(&FightLayer::addEnemyPlane), 2.0f);
	auto bullet_list_1 = GameManager::getInstance()->getBulletList();
	auto plane_list_1 = GameManager::getInstance()->getPlaneList();
	auto supply_list_1 = GameManager::getInstance()->getSupplyList();
	for (int i = bullet_list_1.size() - 1; i >= 0; i--)
	{
		bullet_list_1.at(i)->scheduleUpdate();
	}
	for (int i = plane_list_1.size() - 1; i >= 0; i--)
	{
		plane_list_1.at(i)->resume();
	}
	for (int i = supply_list_1.size() - 1; i >= 0; i--)
	{
		supply_list_1.at(i)->scheduleUpdate();
	}
}

void FightLayer::goToHelp(Ref * psender)
{
	SceneManager::goHelpLayer(1);
}

void FightLayer::goToOption(Ref * psender)
{
	SceneManager::goSetLayer(1);
}

void FightLayer::exitGame(Ref * psender)
{
	Director::getInstance()->end();
}

//代码优化 补给、陨石和敌机合并；
void FightLayer::openSkillU()
{
	switch (player_1->getType())
	{
	case 1:
		skill2_1 = true;
		player_1->changeSpd(player_1->getSpd() * 0.5);
		this->scheduleOnce(schedule_selector(FightLayer::closeSkillU), 5.0f);
		break;
	case 2:
		skill1_1 = true;
		shield = Sprite::create("res/shield1.png");
		shield->setAnchorPoint(Vec2(0.1, 0));
		shield->setPosition(player_1->getAnchorPoint());
		player_1->addChild(shield, 3);
		this->scheduleOnce(schedule_selector(FightLayer::closeSkillU), 3.0f);
		break;
	case 3:
		skill3_1 = true;
		player_1->setCascadeOpacityEnabled(true);
		player_1->setOpacity(50);
		this->scheduleOnce(schedule_selector(FightLayer::closeSkillU), 3.0f);
		break;
	}
	skill_1->setColor(ccc3(119, 136, 153));
}

//关闭U键触发的技能
void FightLayer::closeSkillU(float dt)
{
	switch (player_1->getType())
	{
	case 1:
		skill2_1 = false;
		player_1->changeSpd((int)player_1->getSpd() / 1.3);
		break;
	case 2:
		skill1_1 = false;
		shield->removeFromParentAndCleanup(true);
		break;
	case 3:
		skill3_1 = false;
		player_1->setOpacity(255);
		break;
	}
	skill_1->setColor(ccc3(255, 255, 255));
}

//I键触发的技能
void FightLayer::openSkillI()
{
	switch (player_1->getType())
	{
	case 1:
		addSkill(1);
		this->scheduleOnce(schedule_selector(FightLayer::closeSkillI), 2.0f);
		break;
	case 2:
	{
		white = Sprite::create("res/white.png");
		white->setVisible(true);
		white->setScale(10);
		this->addChild(white,4);
		this->scheduleOnce(schedule_selector(FightLayer::closeWhite), 0.01f);
		auto bullet_list_1 = GameManager::getInstance()->getBulletList();
		for (int i = bullet_list_1.size() - 1; i >= 0; i--)
		{

			auto bullet = bullet_list_1.at(i);
			bullet->removeBullet();
		}
		this->scheduleOnce(schedule_selector(FightLayer::closeSkillI), 8.0f);
		break;
	}
	case 3:
		player_1->changeAtk(player_1->getAtk());
		player_1->changeSpd(player_1->getSpd());
		this->schedule(schedule_selector(FightLayer::addHp), 1.0f);
		this->scheduleOnce(schedule_selector(FightLayer::closeSkillI), 8.0f);
		break;
	}
	skill_2->setColor(ccc3(119, 136, 153));
}

//关闭I键触发的技能
void FightLayer::closeSkillI(float dt)
{
	switch (player_1->getType())
	{
	case 3:
		player_1->changeAtk(-player_1->getAtk() / 2);
		player_1->changeSpd((int)player_1->getSpd() / 1.3);
		this->unschedule(schedule_selector(FightLayer::addHp));
		break;
	default:
		break;
	}
	skill_2->setColor(ccc3(255, 255, 255));
}

void FightLayer::addSkill(int i)
{
	skillImg = Bullet::create();
	skillImg->setPosition(player_1->getPosition());
	this->addChild(skillImg, 3);
	skillImg->setSkillImg(1);
	GameManager::getInstance()->setSkill(skillImg);
	switch (1)
	{
	case 1:
		skillImg->addChild(skillImg->skillImg_1, 3);
		break;
	case 2:
		skillImg->addChild(skillImg->skillImg_2, 3);
		break;
	}
}

void FightLayer::addHp(float dt)
{
	if (player_1->getHp() + 50 <= player_1->getMaxHp())
	{
		player_1->changeHp(50);
		this->hpChange();
	}
	else
	{
		player_1->changeHp(player_1->getMaxHp() - player_1->getHp());
		this->hpChange();
	}
}

void FightLayer::dropEquip(Enemy * plane)
{
	Equip* equip_1 = Equip::create();
	equip_1->setPosition(plane->getPosition());
	int type = rand() % 9 + 1;
	equip_1->setType(type);
	this->addChild(equip_1,3);
	player_1->setEquip(equip_1);
	scheduleOnce(schedule_selector(FightLayer::drawEquip),2.0f);
}

void FightLayer::drawEquip(float dt)
{
	for (int i=player_1->equip_list.size()-1;i>=0;i-- )
	{
		player_1->equip_list.at(i)->removeFromParent();
	}
}

void  FightLayer::closeWhite(float dt)
{
	white->setVisible(false);
}

void FightLayer::addEnemy(float dt)
{
	Enemy * enemy_1 = Enemy::create();
	enemy_1->setType(3);
	enemy_1->setGrade(player_1->getGrade());
	for (int i = player_1->getGrade(); i >0; i--)
	{
		enemy_1->changeAttri();
	}
	enemy_1->setEnemyImg();
	if (rand()%2==0)
	{
		enemy_1->planeMove_1();
	}
	else
	{
		enemy_1->planeMove_2();
	}
	GameManager::getInstance()->setPlane(enemy_1);
	this->addChild(enemy_1,3);
	if (bossExist==0)
	{
		if (player_1->getGrade() == 15)
		{
			this->addBoss();
		}
		else if (player_1->getGrade() == 10)
		{
			this->addBoss();
		}
		else if (player_1->getGrade() == 2)
		{
			this->addBoss();
		}
	}
}

void FightLayer::addBoss()
{
	
	bossExist = 1;
	boss = Enemy::create();
	int lv = player_1->getGrade();
	boss->setAttri(50 , 2000, 50, lv);
	boss->setImg("res/SpaceShooterRedux/PNG/Enemies/enemyRed5.png");
	boss->setScale(2);
	boss->bossMove();
	this->addChild(boss, 3);
	GameManager::getInstance()->setPlane(boss);
	
	

	this->schedule(schedule_selector(FightLayer::bossSkill),3.0f);
}


void FightLayer::plane_death(Enemy * enemy)
{
	Anim2 = Sprite::create("res/crash1.png");
	Anim2->setScale(1.0);
	this->addChild(Anim2, 3);
	Anim2->setPosition(enemy->getPosition());
	auto animation = Animation::create();

	char str[20] = { 0 };
	for (int i = 1; i <= 9; i++)
	{
		sprintf(str, "res/crash%d.png", i);
		animation->addSpriteFrameWithFile(str);
	}
	animation->setDelayPerUnit(0.04f);
	animation->setLoops(1);
	animation->setRestoreOriginalFrame(false);
	auto action = Animate::create(animation);
	Anim2->runAction(action);
	scheduleOnce(schedule_selector(FightLayer::removeAnimation2), 0.4f);
	GameManager::getInstance()->removePlane(enemy);
	enemy->removePlane();
}
