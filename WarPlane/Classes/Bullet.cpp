#include "Bullet.h"
#include"GameManager.h"


Bullet::Bullet()
{
}


Bullet::~Bullet()
{
}
bool Bullet::init() {
	
	return true;
}
void Bullet::setBulletImg(const char * filename) {
	bulletImg = Sprite::create(filename);
	this->addChild(bulletImg);
	scheduleUpdate();
	
}
void Bullet::update(float dt) {
	Size visibleSize = Director::getInstance()->getVisibleSize();
 	this->setPositionY(this->getPositionY() + 5);
	if (this->getPositionY()>visibleSize.height)
	{
		this->removeAllChildrenWithCleanup(true);
		removeBullet();
	}
}

void Bullet::removeBullet()
{
	GameManager::getInstance()->removeBullet(this);
	this->removeAllChildrenWithCleanup(true);
}

