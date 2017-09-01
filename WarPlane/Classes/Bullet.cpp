#include "Bullet.h"
#include"GameManager.h"


Bullet::Bullet()
{
}


Bullet::~Bullet()
{
}
bool Bullet::init() {
	type = 0;
	return true;
}
void Bullet::setBulletImg(const char * filename) {
	bulletImg = Sprite::create(filename);
	this->addChild(bulletImg);
	scheduleUpdate();
	
}
void Bullet::update(float dt) {
	auto visibleSize = Director::getInstance()->getVisibleSize();
	if (type==1)
	{
		this->setPositionY(this->getPositionY() + 5);
		if (this->getPositionY()>visibleSize.height)
		{
			removeBullet();
		}
	}


	else
	{
		this->setPositionY(this->getPositionY() - 5);
		if (this->getPositionY()<0)
		{
			removeBullet();
		}
	}
 	

}
//boss飞弹运行方法
void Bullet::move_1()
{
		 
			auto size = Director::getInstance()->getWinSize();
			auto contentsize = this->getContentSize();
			ccBezierConfig bezier;
			bezier.controlPoint_1 = CCPoint(getRandomNumber(contentsize.width / 2, size.width - contentsize.width / 2), getRandomNumber(contentsize.height / 2, size.height - contentsize.height / 2));
			bezier.controlPoint_2 = CCPoint(getRandomNumber(contentsize.width / 2, size.width - contentsize.width / 2), getRandomNumber(contentsize.height / 2, size.height - contentsize.height / 2));
			bezier.endPosition = CCPoint(getRandomNumber(contentsize.width / 2, size.width - contentsize.width / 2), -contentsize.height);
			auto bezierAction = BezierTo::create(8.0f, bezier);
			auto removeAction = RemoveSelf::create();
			auto action = Sequence::create(bezierAction, removeAction, NULL);
			this->runAction(action);
		
}

void Bullet::removeBullet()
{
	if (this->type==1)
	{
		GameManager::getInstance()->removeBullet(this);
	}
	else
	{
		GameManager::getInstance()->removeEBullet(this);
	}
	this->removeFromParentAndCleanup(true);
}
void Bullet::skillMove(float dt)
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	this->setPositionY(this->getPositionY() + 8);
	if (this->getPositionY() > visibleSize.height)
	{
		GameManager::getInstance()->removeSkill(this);
		this->removeAllChildrenWithCleanup(true);
	}
}


void Bullet::removeSkill()
{
	GameManager::getInstance()->removeSkill(this);
	this->removeFromParentAndCleanup(true);
}
void Bullet::setSkillImg(int type)
{
	switch (1)
	{
	case 1:
		this->skillImg_1 = Sprite::create("res/shit.png");
		//this->skillImg_1->setScale(1.0);
		break;
	case 2:
		this->skillImg_2 = Sprite::create("res/plii_green.png");
		break;
	case 3:
		break;
	}
	schedule(schedule_selector(Bullet::skillMove));
}

int Bullet::getType()
{
	return type;
}

void Bullet::setType(int t)
{
	this->type = t;
}
int Bullet::getRandomNumber(int a, int b) {
	return CCRANDOM_0_1()*(b - a) + a;
}
