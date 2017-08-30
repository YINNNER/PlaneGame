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
void Enemy::removePlane()
{
	this->removeFromParentAndCleanup(true);
}
void Enemy::bossMove()
{
	auto size = Director::getInstance()->getWinSize();
	auto point = Point(size.width / 2, size.height);
	this->setPosition(point);
	schedule(SEL_SCHEDULE(&Enemy::enemyBossMove));
}
void Enemy::enemyBossMove(float dt) {
	this->setPositionX(this->getPositionX() + 3);
	if (this->getPositionX()>600)
	{
		this->unschedule(SEL_SCHEDULE(&Enemy::enemyBossMove));
		this->schedule(SEL_SCHEDULE(&Enemy::enemyBossMove_1));
	}
}
void Enemy::enemyBossMove_1(float dt)
{
	this->setPositionX(this->getPositionX() - 3);
	if (this->getPositionX()<0)
	{
		this->unschedule(SEL_SCHEDULE(&Enemy::enemyBossMove_1));
		this->schedule(SEL_SCHEDULE(&Enemy::enemyBossMove));
	}
}
void Enemy::boss_death()
{
	Sprite * Anim = Sprite::create("res/skill1.png");
	this->addChild(Anim, 3);
	Anim->setPosition(this->getPosition());
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
}
Enemy::Enemy()
{
}
Enemy::~Enemy()
{
}
