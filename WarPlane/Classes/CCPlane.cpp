#include"CCPlane.h"
#include"GameManager.h"
bool CCPlane::init() {
	attack = 0;
	hp = 0;
	exp = 0;
	speed = 0;
	grade = 1;
	type = 0;
	return true;
}
void CCPlane::setImg(const char * filename) {
	planeImg=Sprite::create(filename);
	planeImg->setAnchorPoint(Vec2(0, 0));	
	this->setContentSize(planeImg->getContentSize());
	this->addChild(planeImg);
	this->setAnchorPoint(Vec2(0.5, 0.5));
}

void CCPlane::setAttri(int attack, int hp,  int speed,int grade) {
	this->attack = attack;
	this->hp = hp;
	this->speed = speed;
	this->grade = grade;
}
void CCPlane::changeAttri()
{
	switch (this->getType()) {
	case 1:							//·À
		this->attack += 30;
		this->hp += 120;
		break;
	case 2:							//¹¥
		this->attack += 50;
		this->hp += 80;
		break;
	case 3:
		this->attack += 40;
		this->hp += 100;
		break;
	}
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
		this->changeAttri();
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

void CCPlane::setGrade(int grade)
{
	this->grade = grade;
}

void CCPlane::setExp(int exp)
{
	this->exp = exp;
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

void CCPlane::setEquip(Equip * _equip)
{
	if (_equip->getEquipType()>6)
	{
		this->speed += _equip->getESpd();
		
	}
	else if (_equip->getEquipType()>3)
	{
		this->attack += _equip->getEAtk();
	}
	else {
		this->hp += _equip->getEHp();
	}
	equip_list.pushBack(_equip);
}

void CCPlane::removeEquip(Equip * _equip)
{
	if (_equip->getEquipType()>6)
	{
		this->speed -= _equip->getESpd();

	}
	else if (_equip->getEquipType()>3)
	{
		this->attack -= _equip->getEAtk();
	}
	else {
		this->hp -= _equip->getEHp();
	}
	equip_list.eraseObject(_equip);
}

void CCPlane::setEquip_2(Equip * _equip)
{
	equip_list_2.pushBack(_equip);
}

void CCPlane::removeEquip_2(Equip * _equip)
{
	equip_list_2.eraseObject(_equip);
}
