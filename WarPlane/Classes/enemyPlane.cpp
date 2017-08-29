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

//�õ������
int enemyPlane::getRandomNumber(int a, int b) {
	return CCRANDOM_0_1()*(b - a) + a;
}

//��ʼ���л�
void enemyPlane::initEnemy1(std::string name, int level) {
	auto size = Director::getInstance()->getWinSize();
	//��ͼƬ����ʼ���л�
	std::string str = "res/" + name + ".png";
	this->initWithFile(str);
	//��ʼ���л���С������ֵ������
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
	//���õл�����
	auto point = Point(getRandomNumber(this->getContentSize().width / 2, size.width - this->getContentSize().width / 2), size.height);
	this->setPosition(point);

	CCActionInterval * moveBy = MoveBy::create(1.0f, Point(0, -size.height - this->getContentSize().height));
	this->runAction(moveBy);
	this->getPositionY();
	if (this->getPositionY() < -this->getContentSize().height) {
		this->removeFromParentAndCleanup(true);
	}
}

//��������ս������
void enemyPlane::onEnterTransitionDidFinish() {
	//���ø���
	Sprite::onEnterTransitionDidFinish();
}

//�����������ƶ�
void enemyPlane::initEnemy2(std::string name, int level) {
	auto size = Director::getInstance()->getWinSize();

	//��ͼƬ����ʼ���л�
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
	//���õл�����
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
//��ʼ��boss
void enemyPlane::initEnemyBoss(std::string name, int level) {
	//��ʼ���л�λ��
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
//boss�ƶ�
void enemyPlane::enemyBossMove(float dt) {
	auto size = Director::getInstance()->getWinSize();
	auto content = this->getContentSize();
	CCActionInterval * moveBy = MoveBy::create(4.0f, Point(size.width , 0));
	CCActionInterval * back = moveBy->reverse();
	CCAction * action = CCRepeat::create(dynamic_cast<CCFiniteTimeAction *>(CCSequence::create(moveBy, back, NULL)), 4);
	this->runAction(action);
}
//boss����
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

