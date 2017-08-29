#include "FightLayer.h"
#include"Supply.h"
#include"GameManager.h"
#include"Bullet.h"
#include"enemyPlane.h"
#include"SaveLayer.h"
#include"MapLayer.h"
FightLayer::FightLayer()
{
}

FightLayer::~FightLayer()
{

}

void FightLayer::onEnterTransitionDidFinish() {
	Layer::onEnterTransitionDidFinish();
	this->schedule(SEL_SCHEDULE(&FightLayer::addEnemyPlane), 2.0f);
}

//场景中加入敌机
void FightLayer::addEnemyPlane(int playerLevel) {
	//创建敌机
	auto enemy = enemyPlane::create();
	int enemyLevel = 14;
	//根据随机数来出现不同的敌机
	int enemy_x = CCRANDOM_0_1() * 9 + 1;
	if (enemyLevel <= 4) {
		if (enemy_x > 0 && enemy_x < 8) {
			enemy_x = 1;
		}
		else {
			enemy_x = 2;
		}
	}
	else if (enemyLevel == 5) {
		enemy_x = 3;
		auto str = String::createWithFormat("enemy%d", enemy_x);
		enemy->initEnemy1(str->getCString(), enemyLevel);
	}
	else if (enemyLevel <= 9) {
		if (enemy_x > 0 && enemy_x < 6) {
			enemy_x = 4;
		}
		else {
			enemy_x = 5;
		}
	}
	else if (enemyLevel == 10) {
		enemy_x = 6;
		auto str = String::createWithFormat("enemy%d", enemy_x);
		enemy->initEnemy1(str->getCString(), enemyLevel);
	}
	else if (enemyLevel <= 14) {
		if (enemy_x > 0 && enemy_x < 4) {
			enemy_x = 7;
		}
		else {
			enemy_x = 8;
		}
	}
	else {
		enemy_x = 9;
		auto str = String::createWithFormat("enemy%d", enemy_x);
		enemy->initEnemy1(str->getCString(), enemyLevel);
	}

	auto str = String::createWithFormat("enemy%d", enemy_x);
	if (CCRANDOM_0_1() > 0.7) {
		enemy->initEnemy1(str->getCString(), enemyLevel);
	}
	else {
		enemy->initEnemy2(str->getCString(), enemyLevel);
	}
	this->addChild(enemy,3);
	GameManager::getInstance()->setPlane(enemy);
}

bool FightLayer::init() {
	auto visibleSize = Director::getInstance()->getVisibleSize();
	fightImg = Sprite::create("res/star.png");
	fightImg->setAnchorPoint(Point::ZERO);
	fightImg->setPosition(Vec2(Point::ZERO));
	this->addChild(fightImg,1);
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
	TTFConfig ttfConfig("fonts/Marker Felt.ttf", 24);
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
	//this->schedule(schedule_selector(FightLayer::addEnemyPlane), 5.0f);
	addEnemyPlane(1);
	return true;
}
void FightLayer::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event)
{
	key = keyCode;
}

void FightLayer::onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event)
{
	if (key==keyCode)
	{
		key = EventKeyboard::KeyCode::KEY_NONE;
	}
}

void FightLayer::update(float dt)
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	switch (key) {
	case EventKeyboard::KeyCode::KEY_W:
		if(visibleSize.height-player_1->getPositionY()<player_1->getContentSize().height/2){			
		}
		else
		{
			player_1->setPositionY(player_1->getPositionY() + 5);
		}		
		break;
	case EventKeyboard::KeyCode::KEY_S:
		if (player_1->getPositionY()<player_1->getContentSize().height / 2)
		{

		}
		else {
			player_1->setPositionY(player_1->getPositionY() - 5);
		}
		break;
	case EventKeyboard::KeyCode::KEY_A:
		if (player_1->getPositionX()<player_1->getContentSize().width / 2){
		}
		else {
			player_1->setPositionX(player_1->getPositionX() - 5);
		}
		break;
	case EventKeyboard::KeyCode::KEY_D:
		if (visibleSize.width-player_1->getPositionX()<player_1->getContentSize().width / 2)
		{

		}
		else {
			player_1->setPositionX(player_1->getPositionX() + 5);
		}
		break;
	case EventKeyboard::KeyCode::KEY_J:
		static long interval = this->getCurrentTime();
		if ((this->getCurrentTime()-interval)<250)
		{
			break;
		}
		else
		{
			this->addBullet(1);
			interval = this->getCurrentTime();
		}
		break;
	case EventKeyboard::KeyCode::KEY_U:
		static long interval_1 = this->getCurrentTime();
		if ((this->getCurrentTime() - interval_1)<2000)
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
		if ((this->getCurrentTime() - interval_2)<2000)
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
	}
}

void FightLayer::addSupply(float dt)
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
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
	bullet_1->setPosition(player_1->getPosition());
	bullet_1->setBulletImg("res/fire01.png");
	this->addChild(bullet_1, 3);
	GameManager::getInstance()->setBullet(bullet_1);
}

/*
void FightLayer::addEnemyPlane(float dt)
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	CCPlane * plane_1 = CCPlane::create();
	plane_1->setImg("res/playerShip2_red.png");
	plane_1->setRotation(180);
	plane_1->setAttri(10, 200, 10, 10,1);
	plane_1->setPosition(visibleSize.width/2,visibleSize.height/2);
	this->addChild(plane_1,3);
	GameManager::getInstance()->setPlane(plane_1);
}*/
void FightLayer::is_crash(float dt)
{
	auto bullet_list_1 = GameManager::getInstance()->getBulletList();
	auto plane_list_1 = GameManager::getInstance()->getPlaneList();
	auto supply_list_1 = GameManager::getInstance()->getSupplyList();
	auto skill_list_1 = GameManager::getInstance()->getSkillList();
	//敌机碰撞计算
	for (int i = plane_list_1.size() - 1; i >= 0; i--) {
		auto enemy_plane = plane_list_1.at(i);
		auto enemy_size = enemy_plane->getBoundingBox();
		if (enemy_size.intersectsRect(player_1->getBoundingBox())) {
			plane_list_1.at(i)->plane_death();
			player_1->changeHp(-100);
			this->hpChange();
		}
		for (int j = bullet_list_1.size() - 1; j >= 0; j--) {
			if (enemy_size.containsPoint(bullet_list_1.at(j)->getPosition()))
			{
				bullet_list_1.at(j)->removeBullet();
				enemy_plane->changeHp(-(player_1->getAtk()));
				if (enemy_plane->getHp() <= 0)
				{
					plane_list_1.at(i)->plane_death();
					player_1->changeExp(player_1->getGrade());
					this->expChange();
					scoreValue++;
				}
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
					player_1->changeHp(-50);
					this->hpChange();
					supply_1->removeSupply();
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
				Anim = Sprite::create("res/skill1.png");
				this->addChild(Anim);
				Anim->setPosition(skill_1->getPosition());
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
				Anim->runAction(action);
				this->scheduleOnce(schedule_selector(FightLayer::removeAnimation), 0.5f);
				Rect rect = Rect::Rect(enemy_1->getPositionX() - 100, enemy_1->getPositionY() - 100, 200, 200);
				for (int j = 0; j <= plane_list_1.size() - 1; j++)
				{
					auto enemy_2 = plane_list_1.at(j);
					if (rect.containsPoint(enemy_2->getPosition()))
					{
						enemy_2->changeHp(-500);
						if (enemy_2->getHp() <= 0)
						{
							enemy_2->plane_death();
						}
					}
				}
				skill_1->removeSkill();
				break;
				if (player_1->getHp() <= 0)
				{
					this->goToGameOver(2);
				}
				score->setString(CCString::createWithFormat("score:%d", scoreValue)->getCString());
				//grade->setString(CCString::createWithFormat("LV::%d", player_1->getGrade())->getCString());
			}
		}
	}
}
void FightLayer::removeAnimation(float dt)
{
	Anim->removeFromParentAndCleanup(true);
}

long FightLayer::getCurrentTime()
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return tv.tv_sec * 1000 + tv.tv_usec / 1000;
}
void FightLayer::setPlayer(int cType) {
	auto winSize = Director::getInstance()->getWinSize();
	player_1 = CCPlane::create();
	player_1->setPosition(Vec2(winSize.width / 2, winSize.height / 2));
	player_1->setType(cType);
	//auto user = new userInfo();
	//user->getInfo();

	switch (cType)
	{
	case 1:
		player_1->setAttri(20, player_1->getMaxHp(), 10, 10, 1);	//刺客
		player_1->setImg("res/SpaceShooterRedux/PNG/Planes/playerShip1_blue.png");
		break;
	case 2:
		player_1->setAttri(20, 500, 10, 10, 1);//坦克
		player_1->setImg("res/playerShip1_blue.png");
		break;
	case 3:
		player_1->setAttri(20, 400, 10, 10, 1);//战士
		player_1->setImg("res/playerShip1_blue.png");
		break;
	}
	this->addChild(player_1, 3);
	auto visibleSize = Director::getInstance()->getVisibleSize();
	TTFConfig ttfConfig("fonts/Marker Felt.ttf", 24);
	exp = Label::createWithTTF(ttfConfig, CCString::createWithFormat("EXP:%d", player_1->getExp())->getCString());
	exp->setColor(Color3B::RED);
	exp->setPosition(Vec2(visibleSize.width - 60, 40));
	//this->addChild(exp, 3);
	grade = Label::createWithTTF(ttfConfig, CCString::createWithFormat("LV:%d", player_1->getGrade())->getCString());
	grade->setColor(Color3B::RED);
	grade->setPosition(Vec2(visibleSize.width - 60, 60));
	//this->addChild(grade, 3);
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
	auto visibleSize = Director::getInstance()->getVisibleSize();
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
}

void FightLayer::goToSave(Ref * psender)
{
	auto scene = Scene::create();
	SaveLayer * layer = SaveLayer::create();
	scene->addChild(layer);
	Director::getInstance()->replaceScene(scene);

}

void FightLayer::goToMap(Ref * psender)
{
	auto scene = Scene::create();
	MapLayer * layer = MapLayer::create();
	scene->addChild(layer);
	Director::getInstance()->replaceScene(scene);
}

void FightLayer::gamePause()
{
	this->unscheduleUpdate();
	this->unschedule(schedule_selector(FightLayer::addSupply));
	this->unschedule(schedule_selector(FightLayer::is_crash));
	this->unschedule(schedule_selector(FightLayer::timeSche));
	this->unschedule(SEL_SCHEDULE(&FightLayer::addEnemyPlane));
	auto bullet_list_1 = GameManager::getInstance()->getBulletList();
	auto plane_list_1 = GameManager::getInstance()->getPlaneList();
	auto supply_list_1 = GameManager::getInstance()->getSupplyList();
	for (int i = bullet_list_1.size() - 1; i >= 0; i--)
	{
		bullet_list_1.at(i)->unscheduleUpdate();
	}
	for (int i = plane_list_1.size() - 1; i >= 0; i--)
	{
		plane_list_1.at(i)->unschedule(CC_SCHEDULE_SELECTOR(enemyPlane::enemyMoveY));
		plane_list_1.at(i)->unschedule(CC_SCHEDULE_SELECTOR(enemyPlane::enemyRemove));
		plane_list_1.at(i)->pause();
	}
	for (int i = supply_list_1.size() - 1; i >= 0; i--)
	{
		supply_list_1.at(i)->unscheduleUpdate();
	}
	auto visibleSize = Director::getInstance()->getVisibleSize();
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
	this->schedule(schedule_selector(FightLayer::addSupply), 5.0f);
	this->schedule(schedule_selector(FightLayer::is_crash));
	this->schedule(schedule_selector(FightLayer::timeSche), 1.0f);
	this->schedule(SEL_SCHEDULE(&FightLayer::addEnemyPlane), 2.0f);
	auto bullet_list_1 = GameManager::getInstance()->getBulletList();
	auto plane_list_1 = GameManager::getInstance()->getPlaneList();
	auto supply_list_1 = GameManager::getInstance()->getSupplyList();
	for (int i = bullet_list_1.size() - 1; i >= 0; i--)
	{
		bullet_list_1.at(i)->scheduleUpdate();
	}
	for (int i = plane_list_1.size() - 1; i >= 0; i--)
	{
		plane_list_1.at(i)->schedule(CC_SCHEDULE_SELECTOR(enemyPlane::enemyMoveY));
		plane_list_1.at(i)->schedule(CC_SCHEDULE_SELECTOR(enemyPlane::enemyRemove));
	}
	for (int i = supply_list_1.size() - 1; i >= 0; i--)
	{
		supply_list_1.at(i)->scheduleUpdate();
	}
}

void FightLayer::goToHelp(Ref * psender)
{
	auto scene = Scene::create();
	HelpLayer * layer = HelpLayer::create();
	scene->addChild(layer);
	Director::getInstance()->replaceScene(scene);
}

void FightLayer::goToOption(Ref * psender)
{
	auto scene = Scene::create();
	SetLayer * layer = SetLayer::create();
	scene->addChild(layer);
	Director::getInstance()->replaceScene(scene);
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
		addBullet(1);
		addBullet(1);
		addBullet(1);
		player_1->changeSpd(player_1->getSpd() * 0.3);
		this->schedule(schedule_selector(FightLayer::closeSkillU), 5.0f);
		break;
	case 2:
		shield = Sprite::create("res/shield1.png");
		player_1->addChild(shield);
		shield->setPosition(player_1->getAnchorPoint());
		this->scheduleOnce(schedule_selector(FightLayer::closeSkillU), 4.0f);
		break;
	case 3:
		player_1->setOpacity(100);
		this->schedule(schedule_selector(FightLayer::closeSkillU), 2.0f);
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
		player_1->changeSpd((int)player_1->getSpd() / 1.3);
	case 2:
		if (shield)
		{
			shield->removeFromParentAndCleanup(true);
		}
		
	case 3:
		player_1->setOpacity(255);
	}
	skill_1->setColor(ccc3(255, 255, 255));
}

//I键触发的技能
void FightLayer::openSkillI()
{
	switch (2)
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
		this->addChild(white);
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
	player_1->changeAtk(-player_1->getAtk() / 2);
	player_1->changeSpd((int)player_1->getSpd() / 1.3);
	this->unschedule(schedule_selector(FightLayer::addHp));
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
	player_1->changeHp(50);
}

void  FightLayer::closeWhite(float dt)
{
	white->setVisible(false);
}
