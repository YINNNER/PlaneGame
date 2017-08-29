#include "enemyPlane.h"

enemyPlane::enemyPlane()
{
}

enemyPlane::~enemyPlane()
{
}

bool enemyPlane::init() {
	return true;
}

//得到随机数
int enemyPlane::getRandomNumber(int a, int b) {
	return CCRANDOM_0_1()*(b - a) + a;
}

//初始化敌机
void enemyPlane::initEnemy1(std::string name, int level) {
	auto size = Director::getInstance()->getWinSize();
	//用图片名初始化敌机
	std::string str = "res/" + name + ".png";
	this->initWithFile(str);
	//初始化敌机大小，生命值，护甲
	if (name == "enemy1" || name == "enemy4" || name == "enemy7") {
		this->setScale(0.3);
		enemyHP = 400 + 80 * level;
		enemyAttack = 50 + 4 * level;
	}
	else if (name == "enemy2" || name == "enemy5" || name == "enemy8") {
		this->setScale(0.5);
		enemyHP = 2000 + 100 * level;
		enemyAttack = 60 + 8 * level;
	}
	//设置敌机坐标
	auto point = Point(getRandomNumber(this->getContentSize().width / 2, size.width - this->getContentSize().width / 2), size.height);
	this->setPosition(point);

	CCActionInterval * moveBy = MoveBy::create(1.0f, Point(0, -size.height - this->getContentSize().height));
	this->runAction(moveBy);
	this->getPositionY();
	if (this->getPositionY() < -this->getContentSize().height) {
		this->removeFromParentAndCleanup(true);
	}
}

//场景进入战斗场景
void enemyPlane::onEnterTransitionDidFinish() {
	//调用父类
	Sprite::onEnterTransitionDidFinish();
}

//贝赛尔曲线移动
void enemyPlane::initEnemy2(std::string name, int level) {
	auto size = Director::getInstance()->getWinSize();

	//用图片名初始化敌机
	std::string str = "res/" + name + ".png";
	this->initWithFile(str);
	if (name == "enemy1" || name == "enemy4" || name == "enemy7") {
		this->setScale(0.3);
		enemyHP = 400 + 80 * level;
		enemyAttack = 50 + 4 * level;
	}
	else if (name == "enemy2" || name == "enemy5" || name == "enemy8") {
		this->setScale(0.5);
		enemyHP = 2000 + 100 * level;
		enemyAttack = 60 + 8 * level;
	}
	//设置敌机坐标
	auto point = Point(getRandomNumber(this->getContentSize().width / 2, size.width - this->getContentSize().width / 2), size.height);
	this->setPosition(point);

	auto contentsize = this->getContentSize();
	ccBezierConfig bezier;
	bezier.controlPoint_1 = CCPoint(getRandomNumber(contentsize.width / 2, size.width - contentsize.width / 2), getRandomNumber(contentsize.height / 2, size.height - contentsize.height / 2));
	bezier.controlPoint_2 = CCPoint(getRandomNumber(contentsize.width / 2, size.width - contentsize.width / 2), getRandomNumber(contentsize.height / 2, size.height - contentsize.height / 2));
	bezier.endPosition = CCPoint(getRandomNumber(contentsize.width / 2, size.width - contentsize.width / 2), -contentsize.height);
	auto bezierAction = BezierTo::create(4.0f, bezier);
	auto removeAction = RemoveSelf::create();
	auto action = Sequence::create(bezierAction, removeAction, NULL);
	this->runAction(action);
}
//初始化boss
void enemyPlane::initEnemyBoss(std::string name, int level) {
	//初始化敌机位置
	auto size = Director::getInstance()->getWinSize();
	std::string str = "res/" + name + ".png";
	this->initWithFile(str);
	this->setScale(1.0);
	enemyHP = 10000 + 150 * level;
	enemyAttack = 80 + 10 * level;
	auto point = Point(size.width / 2, size.height);
	this->setPosition(point);
	MoveTo * moveTo = MoveTo::create(1.0f, Point(this->getContentSize().width /2, size.height * 5 / 6));
	this->runAction(moveTo);
	schedule(SEL_SCHEDULE(&enemyPlane::enemyBossMove), 8.0f);
}
//boss移动
void enemyPlane::enemyBossMove(float dt) {
	auto size = Director::getInstance()->getWinSize();
	auto content = this->getContentSize();
	CCActionInterval * moveBy = MoveBy::create(4.0f, Point(size.width , 0));
	CCActionInterval * back = moveBy->reverse();
	CCAction * action = CCRepeat::create(dynamic_cast<CCFiniteTimeAction *>(CCSequence::create(moveBy, back, NULL)), 4);
	this->runAction(action);
}
//boss技能
void enemyPlane::initBossSkill_1(std::string name) {
	auto size = Director::getInstance()->getWinSize();

	std::string str = "res/" + name + ".png";
	this->initWithFile(str);
	this->setScale(0.2);

	auto contentsize = this->getContentSize();
	ccBezierConfig bezier;
	bezier.controlPoint_1 = CCPoint(getRandomNumber(contentsize.width / 2, size.width - contentsize.width / 2), getRandomNumber(contentsize.height / 2, size.height - contentsize.height / 2));
	bezier.controlPoint_2 = CCPoint(getRandomNumber(contentsize.width / 2, size.width - contentsize.width / 2), getRandomNumber(contentsize.height / 2, size.height - contentsize.height / 2));
	bezier.endPosition = CCPoint(getRandomNumber(contentsize.width / 2, size.width - contentsize.width / 2), -contentsize.height);
	auto bezierAction = BezierTo::create(2.0f, bezier);
	auto removeAction = RemoveSelf::create();
	auto action = Sequence::create(bezierAction, removeAction, NULL);
	this->runAction(action);
}

