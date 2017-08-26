#include "enemyPlane.h"
#include"GameManager.h"


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
	//grade = level;

	//��ͼƬ����ʼ���л�
	std::string str = "res/" + name + ".png";
	this->initWithFile(str);
	if (name == "enemy1" || name == "enemy4" || name == "enemy7") {
		this->setScale(0.3);
	}
	else if(name == "enemy2" || name == "enemy5" || name == "enemy8"){
		this->setScale(0.5);
	}
	//���õл�����
	auto point = Point(getRandomNumber(this->getContentSize().width/2,size.width-this->getContentSize().width/2),size.height);
	this->setPosition(point);
}

//��������ս������������movePlane����
void enemyPlane::onEnterTransitionDidFinish() {
	//���ø���
	Sprite::onEnterTransitionDidFinish();
	//�����Զ����schedule��ʵ��ÿһ֡���ƶ��л�
	schedule(CC_SCHEDULE_SELECTOR(enemyPlane::enemyMoveY));
	schedule(CC_SCHEDULE_SELECTOR(enemyPlane::enemyRemove));
}

//���������ƶ�
void enemyPlane::enemyMoveY(float dt) {
	auto point = this->getPositionY() - OFFSET * 2;
	this->setPositionY(point);
	//�������
	if (point < -this->getContentSize().height) {
		GameManager::getInstance()->removePlane(this);
		this->removeFromParentAndCleanup(true);
	}
}

void enemyPlane::enemyRemove(float dt) {
	auto point = this->getPositionX();
	if (point < this->getContentSize().width / 2 || point>600 - getContentSize().width / 2) {
		GameManager::getInstance()->removePlane(this);
		this->removeFromParentAndCleanup(true);
	}
}

void enemyPlane::initEnemy2(std::string name, int level) {
	auto size = Director::getInstance()->getWinSize();
	//grade = level;

	//��ͼƬ����ʼ���л�
	std::string str = "res/" + name + ".png";
	this->initWithFile(str);
	if (name == "enemy1" || name == "enemy4" || name == "enemy7") {
		this->setScale(0.5);
	}
	else if (name == "enemy2" || name == "enemy5" || name == "enemy8") {
		this->setScale(0.8);
	}
	//���õл�����
	auto point = Point(getRandomNumber(this->getContentSize().width / 2, size.width - this->getContentSize().width / 2), size.height);
	this->setPosition(point);

	auto contentsize = this->getContentSize();
	ccBezierConfig bezier;
	bezier.controlPoint_1 = CCPoint(getRandomNumber(contentsize.width / 2, size.width - contentsize.width / 2), getRandomNumber(contentsize.height / 2, size.height - contentsize.height / 2));
	bezier.controlPoint_2 = CCPoint(getRandomNumber(contentsize.width / 2, size.width - contentsize.width / 2), getRandomNumber(contentsize.height / 2, size.height - contentsize.height / 2));
	bezier.endPosition = CCPoint(getRandomNumber(contentsize.width / 2, size.width - contentsize.width / 2), -contentsize.height);
	auto bezierAction = BezierTo::create(5.0f, bezier);
	auto removeAction = RemoveSelf::create();
	auto action = Sequence::create(bezierAction, removeAction, NULL);
	this->runAction(action);
}
void enemyPlane::removePlane(float dt)
{
	
	this->unschedule(schedule_selector(enemyPlane::removePlane));
	this->removeFromParentAndCleanup(true);
}

void enemyPlane::plane_death()
{
	this->setImg("res/playerShip3_damage3.png");
	GameManager::getInstance()->removePlane(this);
	this->scheduleOnce(schedule_selector(enemyPlane::removePlane), 0.5f);
}
