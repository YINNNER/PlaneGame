#include "Enemy.h"
#include"GameManager.h"
bool Enemy::init()
{
	this->CCPlane::init();
	return true;
}

void Enemy::planeMove_1()
{
	auto size = Director::getInstance()->getWinSize();
	auto point = Point(getRandomNumber(this->getContentSize().width / 2, size.width - this->getContentSize().width / 2), size.height);
	this->setPosition(point);
	CCActionInterval * moveBy = MoveBy::create(5.0f, Point(0, -size.height - this->getContentSize().height));
	this->runAction(moveBy);
	if (this->getPositionY() < -this->getContentSize().height) {
		this->removeFromParentAndCleanup(true);
	}
}

void Enemy::planeMove_2()
{
	auto size = Director::getInstance()->getWinSize();
	auto contentsize = this->getContentSize();
	auto point = Point(getRandomNumber(this->getContentSize().width / 2, size.width - this->getContentSize().width / 2), size.height);
	this->setPosition(point);
	ccBezierConfig bezier;
	bezier.controlPoint_1 = CCPoint(getRandomNumber(contentsize.width / 2, size.width - contentsize.width / 2), getRandomNumber(contentsize.height / 2, size.height - contentsize.height / 2));
	bezier.controlPoint_2 = CCPoint(getRandomNumber(contentsize.width / 2, size.width - contentsize.width / 2), getRandomNumber(contentsize.height / 2, size.height - contentsize.height / 2));
	bezier.endPosition = CCPoint(getRandomNumber(contentsize.width / 2, size.width - contentsize.width / 2), -contentsize.height);
	auto bezierAction = BezierTo::create(5.0f, bezier);
	auto removeAction = RemoveSelf::create();
	auto action = Sequence::create(bezierAction, removeAction, NULL);
	this->runAction(action);
}
int Enemy::getRandomNumber(int a, int b) {
	return CCRANDOM_0_1()*(b - a) + a;
}

void Enemy::setEnemyImg()
{
	int level = this->getGrade();
	if (level<5)
	{
		this->setImg("res/enemy1.png");
	}
	else if (level<10)
	{
		this->setImg("res/enemy3.png");
	}
	else {
		this->setImg("res/enemyBlue5.png");
	}
}
void Enemy::removePlane(float dt)
{

	this->unschedule(schedule_selector(Enemy::removePlane));
	this->removeFromParentAndCleanup(true);
}
Enemy::Enemy()
{
}
Enemy::~Enemy()
{
}
void Enemy::plane_death()
{
	this->setImg("res/playerShip3_damage3.png");
	GameManager::getInstance()->removePlane(this);
	this->scheduleOnce(schedule_selector(Enemy::removePlane), 0.5f);
}
