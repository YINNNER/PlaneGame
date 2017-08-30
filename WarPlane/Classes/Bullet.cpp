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
	static VISIBLESIZE;
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

void Bullet::removeBullet()
{
	GameManager::getInstance()->removeBullet(this);
	this->removeAllChildrenWithCleanup(true);
}
void Bullet::skillMove(float dt)
{
	static VISIBLESIZE;
	this->setPositionY(this->getPositionY() + 30);
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
		this->skillImg_1->setScale(0.3);
		break;
	case 2:
		this->skillImg_2 = Sprite::create("res/plii_green.png");
		break;
	case 3:
		break;
	}
	schedule(schedule_selector(Bullet::skillMove), 0.1f);
}

int Bullet::getType()
{
	return type;
}

void Bullet::setType(int t)
{
	this->type = t;
}
