#include "FightLayer.h"
#include"Supply.h"
#include"GameManager.h"
#include"Bullet.h"
#include"SaveLayer.h"
#include"MapLayer.h"
#include "SimpleAudioEngine.h"
using namespace CocosDenshion;
FightLayer::FightLayer()
{
}

FightLayer::~FightLayer()
{
    auto bullet_list_1 = GameManager::getInstance()->getBulletList();
    auto plane_list_1 = GameManager::getInstance()->getPlaneList();
    auto supply_list_1 = GameManager::getInstance()->getSupplyList();
    auto skill_list_1 = GameManager::getInstance()->getSkillList();
    Layer::onExit();
    for (int i = bullet_list_1.size() - 1; i >= 0; i--)
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
bool FightLayer::init() {
	auto visibleSize = Director::getInstance()->getVisibleSize();
	TTFConfig ttfConfig("fonts/Anklepan.ttf", 22);
	bossExist = 0;
	skill2_1 = false;
	skill1_1 = false;
	skill3_1 = false;
	cd1 = 0;
	cd2 = 0;
	//set score label
    scoreValue = 0;
    score = Label::createWithTTF(ttfConfig, CCString::createWithFormat("score:%d", scoreValue)->getCString());
    score->setColor(Color3B::WHITE);
    score->setPosition(visibleSize.width -90, visibleSize.height -40);
    this->addChild(score, 3);
    //set time label
    secTime = 0;
    minTime = 0;
    time = Label::createWithTTF(ttfConfig, CCString::createWithFormat("time:%d:%d",minTime, secTime)->getCString());
    time->setColor(Color3B::WHITE);
    time->setPosition(visibleSize.width - 90, visibleSize.height - 70);
    this->addChild(time, 3);
    //set hp bar
    Sprite * hpIco = Sprite::create("res/UI/a3Game/shield_bronze.png");
    hpIco->setAnchorPoint(Vec2(1, 0));
    hpIco->setPosition(Vec2(visibleSize.width-20, 20));
    this->addChild(hpIco,3);
    hpSprite = Sprite::create("res/RedBar.png");
    hpSprite->setAnchorPoint(Vec2(1, 0));
    hpSprite->setPosition(Vec2(visibleSize.width - 50, 30));
    Sprite * hpImg = Sprite::create("res/EmptyBar.png");
    hpImg->setAnchorPoint(Vec2(1, 0));
    hpImg->setPosition(Vec2(visibleSize.width-50,30));
    this->addChild(hpImg,3);
    this->addChild(hpSprite, 4);
    //set exp bar
    expSprite = Sprite::create("res/expBar.png");
    expSprite->setAnchorPoint(Vec2(0, 0));
    expSprite->setScaleX(1);
    expSprite->setPosition(Vec2(0, 0));
    Sprite * expImg = Sprite::create("res/expEmpty.png");
    expImg->setAnchorPoint(Vec2(0, 0));
    expImg->setPosition(Vec2(0 ,0));
    expImg->setScaleX(1.1);
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
//boss技能
void FightLayer::bossSkill(float)
{
	//boss通用技能
	Bullet * bullet_1 = Bullet::create();
	bullet_1->setPosition(boss->getPosition());
    bullet_1->setType(3);
    bullet_1->move_1();
	bullet_1->setBulletImg("res/bomb.png");
	bullet_1->setScale(0.5);
	this->addChild(bullet_1, 3);
	//各boss特性技能
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
//boss1技能，冲撞
void FightLayer::bossSkill_1(float)
{
    for (int i = 1; i <= 2; i++) {
        auto size = Director::getInstance()->getWinSize();
        Bullet * bullet = Bullet::create();
        if (i == 1)bullet->setPosition(size.width / 2 * CCRANDOM_0_1(), size.height);
        else bullet->setPosition(size.width / 2 * CCRANDOM_0_1() + size.width / 2, size.height);
        bullet->setType(2);
        bullet->setBulletImg("res/bigPlane.png");
        bullet->setScale(2.0f);
        GameManager::getInstance()->setEBullet(bullet);
        this->addChild(bullet, 3);

	}	
}
//boss2技能，导弹群
void FightLayer::bossSkill_2(float)
{
    for (int i = 0; i < 10; i++)
    {
        Bullet * bullet_1 = Bullet::create();
        bullet_1->setPosition(boss->getPositionX(), boss->getPositionY());
        bullet_1->setType(3);
        bullet_1->move_1();
        bullet_1->setBulletImg("res/bomb.png");
        this->addChild(bullet_1, 3);
        GameManager::getInstance()->setEBullet(bullet_1);
    }
}
//boss3技能，百分比扣血
void FightLayer::bossSkill_3(float)
{
	player_1->changeHp(-player_1->getHp() / 3);
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
			player_1->setPositionY(player_1->getPositionY() + player_1->getSpd() );
		}
		break;
	case EventKeyboard::KeyCode::KEY_S:
		if (player_1->getPositionY() < player_1->getContentSize().height / 2)
		{

		}
		else {
			player_1->setPositionY(player_1->getPositionY() - player_1->getSpd() );
		}
		break;
	case EventKeyboard::KeyCode::KEY_A:
		if (player_1->getPositionX() < player_1->getContentSize().width / 2) {
		}
		else {
			player_1->setPositionX(player_1->getPositionX() - player_1->getSpd() );
		}
		break;
	case EventKeyboard::KeyCode::KEY_D:
		if (visibleSize.width - player_1->getPositionX() < player_1->getContentSize().width / 2)
		{

		}
		else {
			player_1->setPositionX(player_1->getPositionX() + player_1->getSpd() );
		}
		break;
	}
	switch (atkKey)
	{
	case EventKeyboard::KeyCode::KEY_J:
	{static long interval = 0;
	if ((this->getCurrentTime() - interval) < 250)
	{
		break;
	}
	else
	{
		if (skill2_1)
		{
			this->addBullet(2);
			this->addBullet(2);
			this->addBullet(2);
		}
		else
		{
			this->addBullet(1);
		}
		interval = this->getCurrentTime();
	}
    
	break; }
	case EventKeyboard::KeyCode::KEY_U:
	{static long interval_1 = 0;
	if ((this->getCurrentTime() - interval_1) < 10000)
	{
		break;
	}
	else
	{
		openSkillU();
		interval_1 = this->getCurrentTime();
	}
	break; }
	case EventKeyboard::KeyCode::KEY_I:
	{static long interval_2 = 0;
	if ((this->getCurrentTime() - interval_2) < 15000)
	{
		break;
	}
	else
	{
		openSkillI();
		interval_2 = this->getCurrentTime();
	}
	break; }
	case EventKeyboard::KeyCode::KEY_ESCAPE:
	{this->gamePause();
	break; }
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
    if (SetLayer::effectState == 1) {
        SimpleAudioEngine::getInstance()->playEffect("music/bullet3.mp3");
    }
	Bullet * bullet_1 = Bullet::create();
	bullet_1->setType(1);
	bullet_1->setPosition(player_1->getPosition());
    switch(bType)
    {
        case 1:
            bullet_1->setBulletImg("res/fire01.png");
            break;
        case 2:
            bullet_1->setBulletImg("res/fire02.png");
            break;
    }
	
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
				SimpleAudioEngine::getInstance()->playEffect("music/bomb4.wav");
				plane_death(plane_list_1.at(i));
				player_1->changeHp(-10);
				this->hpChange();
			}
		}
		for (int j = bullet_list_1.size() - 1; j >= 0; j--) {
			
			if (enemy_size.containsPoint(bullet_list_1.at(j)->getPosition()))
			{
				bullet_list_1.at(j)->removeBullet();
				enemy_plane->changeHp(-(player_1->getAtk()));
                if (SetLayer::effectState == 1) {
                    SimpleAudioEngine::getInstance()->playEffect("music/hited2.wav");
                }
				if (enemy_plane->getIsBoss() == 1)
				{
					this->bossHpChange();
				}

				if (enemy_plane->getHp() <= 0)
				{
                    if (SetLayer::effectState == 1) {
                        SimpleAudioEngine::getInstance()->playEffect("music/bomb4.wav");
                    }
                    
					if (enemy_plane->getIsBoss()==1)
					{
						bossExist = 2;
						this->unschedule(schedule_selector(FightLayer::bossSkill));
						this->unschedule(schedule_selector(FightLayer::bossSkill_1));
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
					else if (rand() % 10==0)
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
				Ebullet_list_1.at(i)->removeBullet();
				break;
			}
			else if (skill3_1)
			{
				break;
			}
			else {
				if (player_1->getBoundingBox().containsPoint(Ebullet_list_1.at(i)->getPosition())) {
					SimpleAudioEngine::getInstance()->playEffect("music/hited2.wav");
					player_1->changeHp(-player_1->getGrade());
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
							player_1->changeHp(5);
							this->hpChange();
						}
						scoreValue++;
						supply_1->removeSupply();
                        if (SetLayer::effectState == 1) {
                            SimpleAudioEngine::getInstance()->playEffect("music/getSupply03.wav");
                        }
                        
					}
					else if (supply_1->getType() == 2 || supply_1->getType() == 3)
					{
						if (skill3_1)
						{
							break;
						}
						else
						{
                            if (SetLayer::effectState == 1) {
                                SimpleAudioEngine::getInstance()->playEffect("music/stone1.wav");
                            }
                            
							player_1->changeHp(-5);
							this->hpChange();
							supply_1->removeSupply();
                            showDamage(supply_1);
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
					if (SetLayer::effectState == 1) {
						SimpleAudioEngine::getInstance()->playEffect("music/bomb3.wav");
					}
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
							enemy_2->changeHp(-50);
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
			player_1->setHp(0);
			this->goToGameOver(1);
		}
		score->setString(CCString::createWithFormat("score:%d", scoreValue)->getCString());
		grade->setString(CCString::createWithFormat("LV:%d", player_1->getGrade())->getCString());
		hpLabel->setString(CCString::createWithFormat("%d0", player_1->getHp())->getCString());
		attarkLabel->setString(CCString::createWithFormat("%d0", player_1->getAtk())->getCString());				
}
		
void FightLayer::removeAnimation1(float dt)
{
	Anim1->removeFromParentAndCleanup(true);
}

void FightLayer::removeAnimation2(float dt)
{
	for (int i = ani.size()-1; i >=0; i--)
	{
		ani.at(i)->removeFromParentAndCleanup(true);
	}
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
	player_1->setAttri(user.getAtk(),user.getHp(),user.getSpd(),user.getPlaneLevel());	//坦克
	player_1->setImg(CCString::createWithFormat("res/SpaceShooterRedux/PNG/Planes/playerShip%d_green.png", user.getPlaneType())->getCString());

	this->addChild(player_1, 3);
    
    
    //set skill bar
    if (user.getPlaneType()==1)
    {
        skill_11 = Sprite::create("res/skill1_1.png");
        skill_22 = Sprite::create("res/skill1_2.png");
    }
    else if (user.getPlaneType()==2)
    {
        skill_11 = Sprite::create("res/skill2_1.png");
        skill_22 = Sprite::create("res/skill2_2.png");
    }
    else
    {
        skill_11 = Sprite::create("res/skill3_1.png");
        skill_22 = Sprite::create("res/skill3_2.png");
    }
    
    auto barSize = skill_11->getContentSize();
    skill_11->setAnchorPoint(Point::ZERO);
    skill_22->setAnchorPoint(Point::ZERO);
    skill_11->setPosition(visibleSize.width*0.12, visibleSize.height*0.05);
    skill_22->setPosition(barSize.width+visibleSize.width*0.12, visibleSize.height*0.05);
    skill_11->setScale(0.8);
    skill_22->setScale(0.8);
    this->addChild(skill_11, 2);
    this->addChild(skill_22, 2);
    
    //set plane level
    TTFConfig ttfConfig("fonts/Anklepan.ttf", 18);
    grade = Label::createWithTTF(ttfConfig, CCString::createWithFormat("LV:%d", player_1->getGrade())->getCString());
    grade->setColor(Color3B::WHITE);
    grade->setPosition(Vec2(30, 20));
    this->addChild(grade, 3);
    
    //set hp
    hpLabel = Label::createWithTTF(ttfConfig, CCString::createWithFormat("%d0", player_1->getHp())->getCString());
    hpLabel->setColor(Color3B::WHITE);
    hpLabel->setPosition(Vec2(hpSprite->getPositionX()-hpSprite->getContentSize().width-hpLabel->getContentSize().width, hpSprite->getPositionY()));
    this->addChild(hpLabel, 3);
    
    //set atk
    attarkLabel = Label::createWithTTF(ttfConfig, CCString::createWithFormat("ATK:%d0", player_1->getAtk())->getCString());
    attarkLabel->setColor(Color3B::WHITE);
    attarkLabel->setPosition(Vec2(30,45));
    this->addChild(attarkLabel, 3);
	//生成敌机的频率
    this->schedule(schedule_selector(FightLayer::addEnemy),1.0f);
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
	expSprite->setScaleX(((float)player_1->getExp()) / (1.0*player_1->getGrade()));
}

void FightLayer::goToGameOver(int value)
{
	SimpleAudioEngine::getInstance()->stopBackgroundMusic();
	
	Size visibleSize = Director::getInstance()->getVisibleSize();
	gameOver = Sprite::create("res/UI/a5GameFin/rect.png");
	auto gameOverSize = gameOver->getContentSize();
	Sprite * star_1 = Sprite::create("res/star_gold.png");
	star_1->setPosition(Vec2(gameOverSize.width / 3, gameOverSize.height * 0.65));
	star_1->setScale(2);
	Sprite * star_2 = Sprite::create("res/star_gold.png");
	star_2->setPosition(Vec2(gameOverSize.width / 2, gameOverSize.height * 0.65));
	star_2->setScale(2);
	Sprite * star_3 = Sprite::create("res/star_gold.png");
	star_3->setPosition(Vec2(gameOverSize.width * 2 / 3, gameOverSize.height * 0.65));
	star_3->setScale(2);

	Label * result_1 = Label::createWithTTF("通关失败", "fonts/simhei.ttf", 30);
    result_1->setTextColor(Color4B::BLACK);
	result_1->setPosition(Vec2(gameOverSize.width / 2, gameOverSize.height * 0.75));
	
	Label * result_2 = Label::createWithTTF("通关成功", "fonts/simhei.ttf", 30);
    result_2->setTextColor(Color4B::BLACK);
	result_2->setPosition(Vec2(gameOverSize.width / 2, gameOverSize.height * 0.75));

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
	switch (value)
	{
	case 1:
        gameOver->addChild(result_1);
		if (SetLayer::effectState == 1) {
			SimpleAudioEngine::getInstance()->playEffect("music/lose1.wav");
		}
		if (scoreValue > 30)
		{
			gameOver->addChild(star_1);
			gameOver->addChild(star_2);
		}
		else if (scoreValue > 20)
		{
			gameOver->addChild(star_1);
		}
        player_1->hero_death();
        break;
	case 2:
           gameOver->addChild(result_2);
		   if (SetLayer::effectState == 1) {
			   SimpleAudioEngine::getInstance()->playEffect("music/win02.mp3");
		   }
			gameOver->addChild(star_1);
			 gameOver->addChild(star_2);
			   gameOver->addChild(star_3);
			   if (user.getGameLevel() == 3) {
				   ;
			   }
			   else
			   {
				   gameLevel++;
			   }


		break;
	}
    user.setAtk(player_1->getAtk());
    user.setExp(player_1->getExp());
    user.setPlaneLevel(player_1->getGrade());
    if (player_1->getHp()>0)
    {
        user.setHp(player_1->getHp());
    }
    else
    {
        user.setHp(player_1->getMaxHp());
    }

    user.setSpd(player_1->getSpd());
	if (user.getGameLevel()>=gameLevel)
	{
		;
	}
	else {
		user.setGameLevel(gameLevel);
	}

	
	
  
    //show score
	Label * score = Label::createWithTTF(CCString::createWithFormat("分数:%d", scoreValue)->getCString(), "fonts/simhei.ttf", 28);
    score->setTextColor(Color4B::BLACK);
	score->setPosition(Vec2(gameOverSize.width *0.5, gameOverSize.height *0.55));

	gameOver->addChild(score);

    //show time
    Label * time = Label::createWithTTF(CCString::createWithFormat("用时:%d:%d",minTime, secTime)->getCString(), "fonts/simhei.ttf", 28);
    time->setTextColor(Color4B::BLACK);
    time->setPosition(Vec2(gameOverSize.width *0.5, gameOverSize.height *0.45));
    gameOver->addChild(time);

	gameOver->setPosition(Vec2(visibleSize.width / 2, 0));


	MenuItemImage * save = MenuItemImage::create("res/UI/a5GameFin/save.png", "res/UI/a5GameFin/saveS.png", CC_CALLBACK_1(FightLayer::goToSave, this));
	save->setPosition(Vec2(gameOverSize.width *0.14, gameOverSize.height *0.2));
	MenuItemImage * map = MenuItemImage::create("res/UI/a5GameFin/selectLevel.png", "res/UI/a5GameFin/selectLevelS.png", CC_CALLBACK_1(FightLayer::goToMap, this));
	map->setPosition(Vec2(gameOverSize.width * 0.86, gameOverSize.height *0.2));
	Menu * menu = Menu::create(save, map, NULL);
	menu->setPosition(Vec2(0, 0));
	menu->setAnchorPoint(Vec2(0, 0));
	gameOver->addChild(menu);
	auto move = MoveTo::create(1.0f, Vec2(visibleSize.width / 2, visibleSize.height / 2));
	gameOver->runAction(move);
	this->addChild(gameOver, 5);
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
		bullet_1->setBulletImg("res/SpaceShooterRedux/PNG/Effects/fire12.png");
		//bullet_1->setScale(0.5);
		this->addChild(bullet_1, 3);
		GameManager::getInstance()->setEBullet(bullet_1);
	}
}

void FightLayer::goToSave(Ref * psender)
{
    if (SetLayer::effectState == 1) {
        SimpleAudioEngine::getInstance()->playEffect("music/trans1.wav");
        SimpleAudioEngine::sharedEngine()->playEffect("music/click8.wav");
    }
	SimpleAudioEngine::getInstance()->stopBackgroundMusic();
	SceneManager::goSaveLayer(2, user);

}

void FightLayer::goToMap(Ref * psender)
{
    if (SetLayer::effectState == 1) {
        SimpleAudioEngine::getInstance()->playEffect("music/trans1.wav");
        SimpleAudioEngine::sharedEngine()->playEffect("music/click8.wav");
    }
	SimpleAudioEngine::getInstance()->stopBackgroundMusic();
    SceneManager::goMapLayer(2, user);
}

void FightLayer::gamePause()
{
	_scheduler->pauseTarget(this);
	if (cd1==1)
	{
		CD1->pause();
	}
	if (cd2==1)
	{
		CD2->pause();
	}


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
    }
	auto bullet_list_1 = GameManager::getInstance()->getBulletList();
    auto Ebullet_list_1 = GameManager::getInstance()->getEBulletList();
	auto plane_list_1 = GameManager::getInstance()->getPlaneList();
	auto supply_list_1 = GameManager::getInstance()->getSupplyList();
	for (int i = bullet_list_1.size() - 1; i >= 0; i--)
	{
		bullet_list_1.at(i)->unscheduleUpdate();
	}
    for (int i = Ebullet_list_1.size() - 1; i >= 0; i--)
    {
        if (Ebullet_list_1.at(i)->getType()==2)
        {
            Ebullet_list_1.at(i)->unscheduleUpdate();
        }
        else if (Ebullet_list_1.at(i)->getType() == 3)
        {
            Ebullet_list_1.at(i)->pause();
        }
        
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
	pause = Label::createWithTTF("游戏暂停", "fonts/simhei.ttf", 40);
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
	SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
	_scheduler->resumeTarget(this);
	if (cd1==1)
	{
		CD1->resume();
	}
	if (cd2==1)
	{
		CD2->resume();
	}
	
	
	this->resume();
	this->scheduleUpdate();
	this->schedule(schedule_selector(FightLayer::addSupply),5.0f);
	this->schedule(schedule_selector(FightLayer::is_crash));
	this->schedule(schedule_selector(FightLayer::timeSche),1.0f);
	this->schedule(schedule_selector(FightLayer::addEnemy),2.0f);
	this->schedule(schedule_selector(FightLayer::backMove));
	if (bossExist==1)
	{
        this->schedule(schedule_selector(FightLayer::bossSkill), 5.0);
        boss->schedule(SEL_SCHEDULE(&Enemy::enemyBossMove));
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
    
	//this->schedule(SEL_SCHEDULE(&FightLayer::addEnemyPlane), 2.0f);
	auto bullet_list_1 = GameManager::getInstance()->getBulletList();
    auto Ebullet_list_1 = GameManager::getInstance()->getEBulletList();
	auto plane_list_1 = GameManager::getInstance()->getPlaneList();
	auto supply_list_1 = GameManager::getInstance()->getSupplyList();
	for (int i = bullet_list_1.size() - 1; i >= 0; i--)
	{
		bullet_list_1.at(i)->scheduleUpdate();
	}
    for (int i = Ebullet_list_1.size() - 1; i >= 0; i--)
    {
        if (Ebullet_list_1.at(i)->getType()==2)
        {
            Ebullet_list_1.at(i)->scheduleUpdate();
        }
        else if (Ebullet_list_1.at(i)->getType() == 3)
        {
            Ebullet_list_1.at(i)->resume();
        }
        
    }

	for (int i = plane_list_1.size() - 1; i >= 0; i--)
	{
		plane_list_1.at(i)->resume();
	}
	for (int i = supply_list_1.size() - 1; i >= 0; i--)
	{
		supply_list_1.at(i)->scheduleUpdate();
	}
    if (SetLayer::effectState == 1) {
        SimpleAudioEngine::getInstance()->playEffect("music/trans1.wav");
        SimpleAudioEngine::sharedEngine()->playEffect("music/click8.wav");
    }

}

void FightLayer::goToHelp(Ref * psender)
{
    if (SetLayer::effectState == 1) {
        SimpleAudioEngine::getInstance()->playEffect("music/trans1.wav");
        SimpleAudioEngine::sharedEngine()->playEffect("music/click8.wav");
    }
	SceneManager::goHelpLayer(1);
}

void FightLayer::goToOption(Ref * psender)
{
	SceneManager::goSetLayer(1);
}

void FightLayer::exitGame(Ref * psender)
{
    if (SetLayer::effectState == 1) {
        SimpleAudioEngine::getInstance()->playEffect("music/trans1.wav");
        SimpleAudioEngine::sharedEngine()->playEffect("music/click8.wav");
    }
	SimpleAudioEngine::getInstance()->stopBackgroundMusic();
	SceneManager::goMenuLayer(2);
}

//代码优化 补给、陨石和敌机合并；
void FightLayer::openSkillU()
{
	switch (player_1->getType())
	{
	case 1:
        skill1_1 = true;
        shield = Sprite::create("res/shield1.png");
        shield->setAnchorPoint(Vec2(0.1, 0));
        shield->setPosition(player_1->getAnchorPoint());
        player_1->addChild(shield, 3);
		if (SetLayer::effectState == 1) {
			SimpleAudioEngine::getInstance()->playEffect("music/hiding1.mp3");
		}//技能音效
		
        this->scheduleOnce(schedule_selector(FightLayer::closeSkillU), 3.0f);
        break;

	case 2:
        skill2_1 = true;
        player_1->changeSpd(2 );
        this->scheduleOnce(schedule_selector(FightLayer::closeSkillU), 5.0f);
        break;
    
    case 3:
		skill3_1 = true;
		if (SetLayer::effectState == 1) {
			SimpleAudioEngine::getInstance()->playEffect("music/skill5.wav");
		}
		player_1->setCascadeOpacityEnabled(true);
		player_1->setOpacity(50);
		this->scheduleOnce(schedule_selector(FightLayer::closeSkillU), 3.0f);
		break;
	}
    Size visibleSize = Director::getInstance()->getVisibleSize();
    CD1 = Sprite::create("res/skillCD10.png");
    CD1->setScale(0.8);
    CD1->setAnchorPoint(Vec2(0,0));
    this->addChild(CD1, 3);
    CD1->setPosition(visibleSize.width*0.12, visibleSize.height*0.05);
    auto animation = Animation::create();
    
    char str[20] = { 0 };
    for (int i = 10; i >= 1; i--)
    {
        sprintf(str, "res/skillCD%d.png", i);
        animation->addSpriteFrameWithFile(str);
    }
    animation->setDelayPerUnit(1.0f);
    animation->setLoops(1);
    animation->setRestoreOriginalFrame(false);
    auto action = Animate::create(animation);
    CD1->runAction(action);
	cd1 = 1;
	this->scheduleOnce(schedule_selector(FightLayer::showSkillCD1), 10.0f);
}

//关闭U键触发的技能
void FightLayer::closeSkillU(float dt)
{
	switch (player_1->getType())
	{
	case 1:
        skill1_1 = false;
        shield->removeFromParentAndCleanup(true);
        break;
	case 2:
		
        skill2_1 = false;
        player_1->changeSpd(-2);
        break;
	case 3:
		skill3_1 = false;
		player_1->setOpacity(255);
		break;
	}
}

//I键触发的技能
void FightLayer::openSkillI()
{
	switch (player_1->getType())
	{
	case 1:
        {
            white = Sprite::create("res/white.png");
            white->setVisible(true);
            white->setScale(10);
            this->addChild(white,4);
			if (SetLayer::effectState == 1) {
				SimpleAudioEngine::getInstance()->playEffect("music/bomb3.wav");
			}
            this->scheduleOnce(schedule_selector(FightLayer::closeWhite), 0.01f);
            auto Ebullet_list_1 = GameManager::getInstance()->getEBulletList();
            for (int i = Ebullet_list_1.size() - 1; i >= 0; i--)
            {
                auto Ebullet = Ebullet_list_1.at(i);
                Ebullet->removeBullet();
            }
            break;
        }

		
	case 2:
		if (SetLayer::effectState == 1) {
			SimpleAudioEngine::getInstance()->playEffect("music/skill2.wav");
		}
        addSkill(1);

        break;
    case 3:
		
		player_1->changeAtk(player_1->getAtk());
		player_1->changeSpd(3);
		this->schedule(schedule_selector(FightLayer::addHp), 1.0f);
		this->scheduleOnce(schedule_selector(FightLayer::closeSkillI), 8.0f);
		break;
	}
    auto barSize = skill_11->getContentSize();
    Size visibleSize = Director::getInstance()->getVisibleSize();
    CD2 = Sprite::create("res/skillCD15.png");
    CD2->setScale(0.8);
    CD2->setAnchorPoint(Vec2(0,0));
    this->addChild(CD2, 3);
    CD2->setPosition(barSize.width+visibleSize.width*0.12, visibleSize.height*0.05);
    auto animation = Animation::create();
    
    char str[20] = { 0 };
    for (int i = 15; i >= 1; i--)
    {
        sprintf(str, "res/skillCD%d.png", i);
        animation->addSpriteFrameWithFile(str);
    }
    animation->setDelayPerUnit(1.0f);
    animation->setLoops(1);
    animation->setRestoreOriginalFrame(false);
    auto action = Animate::create(animation);
    CD2->runAction(action);
	cd2 = 1;
	this->scheduleOnce(schedule_selector(FightLayer::showSkillCD2), 15.0f);
}

//关闭I键触发的技能
void FightLayer::closeSkillI(float dt)
{
	switch (player_1->getType())
	{
	case 3:
		player_1->changeAtk(-player_1->getAtk() / 2);
		player_1->changeSpd(-3);
		this->unschedule(schedule_selector(FightLayer::addHp));
		break;
	default:
		break;
	}
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
	if (SetLayer::effectState == 1) {
		SimpleAudioEngine::getInstance()->playEffect("music/skill4.wav");
	}
	if (player_1->getHp() + 5 <= player_1->getMaxHp())
	{
		player_1->changeHp(5);
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
	scheduleOnce(schedule_selector(FightLayer::drawEquip),2.0f);
	if (player_1->equip_list.size()==0)
	{
		player_1->setEquip(equip_1);
	}else{
	int temp = 0;
    for (int i =player_1->equip_list.size()-1; i >=0; i--)
    {
        if (player_1->equip_list.at(i)->getEquipType() == equip_1->getEquipType()) {	
			player_1->setEquip_2(equip_1);
			break;
        }
        else
        {
			temp++;
        }
    }
	if (temp==player_1->equip_list.size())
	{
		player_1->setEquip(equip_1);
	}
	}
}

void FightLayer::drawEquip(float dt)
{
	
	for (int i=player_1->equip_list.size()-1;i>=0;i-- )
	{
		
		player_1->equip_list.at(i)->removeFromParent();
    }
    for (int i = player_1->equip_list_2.size() - 1; i >= 0; i--)
    {
		
        player_1->equip_list_2.at(i)->removeFromParentAndCleanup(true);
	}
}

void  FightLayer::closeWhite(float dt)
{
	white->setVisible(false);
}
//敌机生成方式
void FightLayer::addEnemy(float dt)
{
	int playerLevel = player_1->getGrade();
	//随玩家等级改变生成频率
	if (playerLevel <= 2) {
		this->schedule(SEL_SCHEDULE(&FightLayer::addEnemy), 1.0f);
	}
	else if (playerLevel <= 4) {
		this->schedule(SEL_SCHEDULE(&FightLayer::addEnemy), 0.8f);
	}
	else if (playerLevel <= 7) {
		this->schedule(SEL_SCHEDULE(&FightLayer::addEnemy), 0.5f);
	}
	else if (playerLevel <= 9) {
		this->schedule(SEL_SCHEDULE(&FightLayer::addEnemy), 0.4f);
	}
	else if (playerLevel <= 12) {
		this->schedule(SEL_SCHEDULE(&FightLayer::addEnemy), 0.3f);
	}
	else if (playerLevel <= 14) {
		this->schedule(SEL_SCHEDULE(&FightLayer::addEnemy), 0.2f);
	}


	//随机判断飞行方式
	Enemy * enemy_1 = Enemy::create();
	enemy_1->setType(4);
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
	//判断等级，是否生成boss
	if (bossExist==0)
	{
		if (minTime == 1) {
			this->addBoss();
		}
	}
}
//boss生成方式
void FightLayer::addBoss()
{
		//初始化属性
	boss = Enemy::create();
	int lv = player_1->getGrade();
	boss->setAttri(5*gameLevel, 200*gameLevel, 5, 1);
	boss->setImg("res/SpaceShooterRedux/PNG/Enemies/enemyRed5.png");
	boss->setScale(2);
	boss->setIs_boss(1);
	boss->bossMove();
	this->addChild(boss, 3);	
	bossMaxHp = 200*gameLevel;
	GameManager::getInstance()->setPlane(boss);
	bossExist = 1;
	
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Sprite * bossBar = Sprite::create("res/EnemyEmptyBar1.png");
	bossBar->setAnchorPoint(Point::ZERO);
	bossBar->setPosition(10, visibleSize.height - 20);
	this->addChild(bossBar, 3);

	bossHp = Sprite::create("res/EnemyRedBar1.png");
	bossHp->setAnchorPoint(Point::ZERO);
	bossHp->setPosition(Vec2(10, visibleSize.height - 20));
	this->addChild(bossHp, 4);
	//计时器调用boss技能
	this->schedule(schedule_selector(FightLayer::bossSkill),5.0f);
}

void FightLayer::plane_death(Enemy * enemy)
{
	Sprite * Anim2 = Sprite::create("res/crash1.png");
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
	ani.pushBack(Anim2);
	scheduleOnce(schedule_selector(FightLayer::removeAnimation2), 0.4f);
	GameManager::getInstance()->removePlane(enemy);
	enemy->removePlane();
}

void FightLayer::showSkillCD1(float dt)
{
	cd1 = 0;
    CD1->removeFromParentAndCleanup(true);
}

void FightLayer::showSkillCD2(float dt)
{
	cd2 = 0;
	CD2->removeFromParentAndCleanup(true);
}
                           

void FightLayer::showDamage(Supply * spy)
{
     metors = Sprite::create("res/SpaceShooterRedux/PNG/Damage/playerShip3_damage3.png");
     metors->setPosition(spy->getPosition());
     this->addChild(metors,3);
     this->scheduleOnce(schedule_selector(FightLayer::removeMetor), 0.5f);
}
                           


void FightLayer::removeMetor(float)

{
	metors->removeFromParentAndCleanup(true);
}

void FightLayer::onEnter()

{
	Layer::onEnter();
	SpriteBatchNode *batchNode;
	if (gameLevel == 1)
	{
		batchNode = SpriteBatchNode::create("res/UI/a3Game/01.png");
		if (SetLayer::backState == 1) {
			SimpleAudioEngine::getInstance()->playBackgroundMusic("music/fight05.mp3", true);
		}
	}
	else if (gameLevel == 2)
	{
		batchNode = SpriteBatchNode::create("res/UI/a3Game/11.png");
		if (SetLayer::backState == 1) {
			SimpleAudioEngine::getInstance()->playBackgroundMusic("music/fight04.mp3", true);
		}
	}
	else
	{
		batchNode = SpriteBatchNode::create("res/UI/a3Game/081.png");
		if (SetLayer::backState == 1) {
			SimpleAudioEngine::getInstance()->playBackgroundMusic("music/fight06.mp3", true);
		}
	}

	if (cd1 == 1)
	{
		CD1->pause();
	}
	if (cd2 == 1)
	{
		CD2->pause();
	}

	this->addChild(batchNode);
	fightImg = Sprite::createWithTexture(batchNode->getTexture());

	fightImg->setAnchorPoint(Point::ZERO);
	fightImg->setPosition(Vec2(Point::ZERO));

	this->addChild(fightImg, 1);
	fightImg2 = Sprite::createWithTexture(batchNode->getTexture());
	fightImg2->setAnchorPoint(Point::ZERO);
	fightImg2->setPosition(Point(fightImg->getPositionX(), fightImg->getPositionY() + fightImg->getContentSize().height));

	this->addChild(fightImg2, 1);
	this->schedule(schedule_selector(FightLayer::backMove));
	auto plane_list_1 = GameManager::getInstance()->getPlaneList();
	auto Ebullet_list_1 = GameManager::getInstance()->getEBulletList();
	for (int i = plane_list_1.size() - 1; i >= 0; i--)
	{
		plane_list_1.at(i)->pause();
	}
	for (int i = Ebullet_list_1.size() - 1; i >= 0; i--)
	{
		if (Ebullet_list_1.at(i)->getType() == 3)
		{
			Ebullet_list_1.at(i)->pause();
		}

	}
}
                           



void FightLayer::getGameLevel(int l)
{
	gameLevel = l;
}

void FightLayer::bossHpChange()
{
	float scalex = ((float)(boss->getHp())) / bossMaxHp;
	if (scalex > 0)
	{
		bossHp->setScaleX(scalex);
	}
	else
	{
		bossHp->setScaleX(0);
	}
}

