#include "FightLayer.h"
#include"Supply.h"
#include"GameManager.h"
#include"Bullet.h"
#include"enemyPlane.h"
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
	static VISIBLESIZE;
	fightImg = Sprite::create("res/star.png");
	fightImg->setAnchorPoint(Point::ZERO);
	fightImg->setPosition(Vec2(Point::ZERO));
	this->addChild(fightImg,1);
	
	scoreValue = 0;
	TTFConfig ttfConfig("fonts/Marker Felt.ttf", 24);
	score = Label::createWithTTF(ttfConfig, CCString::createWithFormat("score:%d", scoreValue)->getCString());
	score->setColor(Color3B::RED);
	score->setPosition(visibleSize.width -100, visibleSize.height -20);
	this->addChild(score, 3);




	auto listenerKeyboard = EventListenerKeyboard::create();
	listenerKeyboard->onKeyPressed = CC_CALLBACK_2(FightLayer::onKeyPressed, this);
	listenerKeyboard->onKeyReleased = CC_CALLBACK_2(FightLayer::onKeyReleased, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listenerKeyboard, this);
	this->scheduleUpdate();
	this->schedule(schedule_selector(FightLayer::addSupply), 5.0f);
	this->schedule(schedule_selector(FightLayer::is_crash));
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
	static VISIBLESIZE;
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
		static long interval_U = this->getCurrentTime();
		if ((this->getCurrentTime() - interval_U)<5000)
		{
			break;
		}
		else
		{
			this->openSkillU();
			interval_U = this->getCurrentTime();
		}
		break;
	}
}

void FightLayer::addSupply(float dt)
{
	static VISIBLESIZE;
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
	static VISIBLESIZE;
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

	//敌机碰撞计算
	for (int i = plane_list_1.size() - 1; i >= 0; i--) {
		auto enemy_plane = plane_list_1.at(i);
		auto enemy_size = enemy_plane->getBoundingBox();
		if (enemy_size.intersectsRect(player_1->getBoundingBox())) {
			plane_list_1.at(i)->plane_death();
			player_1->changeHp(-100);
		}
		for (int j = bullet_list_1.size() - 1; j >= 0; j--) {
			if (enemy_size.containsPoint(bullet_list_1.at(j)->getPosition()))
			{
				bullet_list_1.at(j)->removeBullet();
				enemy_plane->changeHp(-(player_1->getAtk() - enemy_plane->getAr()));
				if (enemy_plane->getHp() <= 0)
				{
					plane_list_1.at(i)->plane_death();
					player_1->changeExp(player_1->getGrade());
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
					player_1->changeHp(50);
					scoreValue++;
					supply_1->removeSupply();
				}
				else if (supply_1->getType() == 2)
				{
					player_1->changeHp(-50);
					supply_1->removeSupply();				
				}
			}
		}
	}
	if (player_1->getHp() <= 0)
	{
		CCLOG("MTEORS");
		this->unscheduleUpdate();
		this->unschedule(schedule_selector(FightLayer::addSupply));
		this->unschedule(schedule_selector(FightLayer::is_crash));
		player_1->hero_death();
	}
	score->setString(CCString::createWithFormat("score:%d", scoreValue)->getCString());
	hp->setString(CCString::createWithFormat("HP:%d", player_1->getHp())->getCString());
	exp->setString(CCString::createWithFormat("EXP:%d", player_1->getExp())->getCString());
	grade->setString(CCString::createWithFormat("LV::%d", player_1->getGrade())->getCString());
}
long FightLayer::getCurrentTime()
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return tv.tv_sec * 1000 + tv.tv_usec / 1000;
}
void FightLayer::setPlayer(int cType) {
	WINSIZE;
	player_1 = CCPlane::create();
	player_1->setPosition(Vec2(winSize.width/2, winSize.height / 2));
	player_1->setType(cType);
	//auto user = new userInfo();
	//user->getInfo();

	switch (cType)
	{
	case 1:
		player_1->setAttri(20, 600, 10, 10, 1);	//刺客
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
	default:
		break;
	}
	this->addChild(player_1, 3);
	static VISIBLESIZE;
	TTFConfig ttfConfig("fonts/Marker Felt.ttf", 24);
	hp = Label::createWithTTF(ttfConfig, CCString::createWithFormat("HP:%d", player_1->getHp())->getCString());
	hp->setColor(Color3B::RED);
	hp->setPosition(Vec2(visibleSize.width - 60, 20));
	this->addChild(hp, 3);
	exp = Label::createWithTTF(ttfConfig, CCString::createWithFormat("EXP:%d", player_1->getExp())->getCString());
	exp->setColor(Color3B::RED);
	exp->setPosition(Vec2(visibleSize.width - 60, 40));
	this->addChild(exp, 3);
	grade = Label::createWithTTF(ttfConfig, CCString::createWithFormat("LV:%d", player_1->getGrade())->getCString());
	grade->setColor(Color3B::RED);
	grade->setPosition(Vec2(visibleSize.width - 60, 60));
	this->addChild(grade, 3);
}
void FightLayer::openSkillU()
{
	//static long currentTime = getCurrentTime();
	switch (2)
	{
	case 1:
		addBullet(1);
		addBullet(1);
		addBullet(1);
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
}
void FightLayer::closeSkillU(float dt)
{
	switch (player_1->getType())
	{
	case 1:

	case 2:
		shield->removeFromParentAndCleanup(true);
	case 3:
		player_1->setOpacity(255);
	}

}

//代码优化 补给、陨石和敌机合并；
