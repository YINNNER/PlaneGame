#include"CCPlane.h"
#include"GameManager.h"
bool CCPlane::init() {
	attack = 0;
	hp = 0;
	exp = 0;
	speed = 0;
	grade = 1;
	type = 0;
	planeEquip = Equip::create();
	return true;
}
void CCPlane::setImg(const char * filename) {
	planeImg=Sprite::create(filename);
	planeImg->setAnchorPoint(Vec2(0, 0));	
	this->addChild(planeImg);
	this->setContentSize(planeImg->getContentSize());
	this->setAnchorPoint(Vec2(0.5, 0.5));
}
void CCPlane::setAttri(int attack, int hp, int armor, int speed,int grade) {
	this->attack = attack + planeEquip->getEAtk();
	this->hp = hp + planeEquip->getEHp();
	this->speed = speed + planeEquip->getESpd();
	this->grade = grade;
}
void CCPlane::changeAtk(int atk) {
	this->attack += atk;
}
void CCPlane::changeHp(int hp) {
	this->hp += hp;
}
void CCPlane::changeSpd(int spd) {
	this->speed += spd;
}
void CCPlane::changeExp(int exp)
{
	this->exp += exp;
	if (this->exp>(10*grade))
	{
		grade++;
		this->exp = 0;
	}
}
int CCPlane::getMaxHp()
{
	switch (type)
	{
	case 1:
		return 160 * grade;
		break;
	case 2:
		return 200 * grade;
		break;
	case 3:
		return 240 * grade;
		break;
	default:
		return 0;
		break;
	}
}
int CCPlane::getAtk() {
	
	return attack;
}
int CCPlane::getHp() {

	return hp;
}
int CCPlane::getSpd() {

	return speed;
}
int CCPlane::getExp() {

	return exp;
}
int CCPlane::getGrade() {

	return grade;
}

int CCPlane::getType()
{
	return type;
}

void CCPlane::setType(int type)
{
	this->type = type;
}

void CCPlane::hero_death()
{
	this->setImg("res/playerShip3_damage3.png");
	this->scheduleOnce(schedule_selector(CCPlane::removeHero), 1.0f);
}

void CCPlane::removeHero(float dt)
{
	this->unschedule(schedule_selector(CCPlane::removeHero));
	this->removeFromParentAndCleanup(true);
}