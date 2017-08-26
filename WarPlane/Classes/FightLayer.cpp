#include "FightLayer.h"
#include"Supply.h"
#include "SimpleAudioEngine.h"
#include"GameManager.h"
#include"Bullet.h"
FightLayer::FightLayer()
{
}

FightLayer::~FightLayer()
{

}
bool FightLayer::init() {
	fightImg = Sprite::create("res/star.png");
	fightImg->setAnchorPoint(Point::ZERO);
	fightImg->setPosition(Vec2(Point::ZERO));
	this->addChild(fightImg,1);
	

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
	static Size visibleSize = Director::getInstance()->getVisibleSize();
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
	//case EventKeyboard::KeyCode::KEY_ESCAPE:
		

	}

}

void FightLayer::addSupply(float dt)
{
	static Size visibleSize = Director::getInstance()->getVisibleSize();
	int temp = rand();
	if (temp%2==0)
	{
		Supply * meteors_1 = Supply::create();
		meteors_1->setSpt(2);
		if (temp%4<2)
		{
			meteors_1->setPosition(Vec2(0, rand() % ((int)visibleSize.height / 2) + (int)visibleSize.height / 2));
		}
		else {
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
void FightLayer::addEnemyPlane(float dt)
{
	static Size visibleSize = Director::getInstance()->getVisibleSize();
	CCPlane * plane_1 = CCPlane::create();
	plane_1->setImg("res/playerShip2_red.png");
	plane_1->setRotation(180);
	plane_1->setAttri(10, 200, 10, 10,1);
	plane_1->setPosition(visibleSize.width/2,visibleSize.height/2);
	this->addChild(plane_1,3);
	GameManager::getInstance()->setPlane(plane_1);
}
void FightLayer::is_crash(float dt)
{
	auto bullet_list_1 = GameManager::getInstance()->getBulletList();
	auto plane_list_1 = GameManager::getInstance()->getPlaneList();
	auto supply_list_1 = GameManager::getInstance()->getSupplyList();
	for (int i = plane_list_1.size() - 1; i >= 0; i--) {
		auto enemy_plane = plane_list_1.at(i);
		auto enemy_size = enemy_plane->getBoundingBox();
		if (enemy_size.intersectsRect(player_1->getBoundingBox())) {
			plane_list_1.at(i)->plane_death();
			this->unscheduleUpdate();
			this->unschedule(schedule_selector(FightLayer::addSupply));
			this->unschedule(schedule_selector(FightLayer::is_crash));
			player_1->hero_death();
		}
		for (int j = bullet_list_1.size()-1; j >= 0; j--) {
			if (enemy_size.containsPoint(bullet_list_1.at(j)->getPosition()))
			{
				bullet_list_1.at(j)->removeBullet();
				enemy_plane->changeHp(-(player_1->getAtk() - enemy_plane->getAr()));
				if (enemy_plane->getHp()<=0)
				{
					plane_list_1.at(i)->plane_death();
					player_1->changeExp(enemy_plane->getGrade());
				}
			}
		}
	}
	if (supply_list_1.size()>0) {
		for (int i = supply_list_1.size()-1; i >=0; i--)
		{
			auto supply_1 = supply_list_1.at(i);
			if (player_1->getBoundingBox().containsPoint(supply_1->getPosition())) {
				if (supply_1->getType()==1)
				{
					player_1->changeHp(50);
					supply_1->removeSupply();
				}
				else if (supply_1->getType() == 2)
				{
					player_1->changeHp(-50);
					if (player_1->getHp()<=0)
					{
						this->unscheduleUpdate();
						this->unschedule(schedule_selector(FightLayer::addSupply));
						this->unschedule(schedule_selector(FightLayer::is_crash));
						player_1->hero_death();
					}
					supply_1->removeSupply();
				}
				
			}
		}
}
}
long FightLayer::getCurrentTime()
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return tv.tv_sec * 1000 + tv.tv_usec / 1000;
}
void FightLayer::setPlayer(int cType) {
	static Size visibleSize = Director::getInstance()->getVisibleSize();
	player_1 = CCPlane::create();
	player_1->setAttri(20,200,10,10,1);
	player_1->setPosition(Vec2(visibleSize.width, visibleSize.height / 2));
	player_1->setImg("res/playerShip1_blue.png");
	this->addChild(player_1,2);
}

//代码优化 补给、陨石和敌机合并；
