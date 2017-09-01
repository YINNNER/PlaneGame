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
	case 1:							//��
		this->attack += 3;
		this->hp += 12;
		break;
	case 2:							//��
		this->attack += 5;
		this->hp += 8;
		break;
	case 3:
		this->attack += 4;
		this->hp += 10;
		break;
	case 4:
		this->attack += 3;
		this->hp += 8;
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
		if (grade<15)
		{
			grade++;
			this->changeAttri();
			this->exp = 0;
		}
	}
}
int CCPlane::getMaxHp()
{
	switch (type)
	{
	case 1:
		return 16 * grade;
		break;
	case 2:
		return 20 * grade;
		break;
	case 3:
		return 24 * grade;
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

void CCPlane::setHp(int hp)
{
	this->hp = hp;
}

void CCPlane::onEquip(Equip * _equip)
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

void CCPlane::putOnEquip_1(int type)//123����
{
	if (this->type==1)
	{
		if (type==3)
		{
			equip_1 = Sprite::create("res/UI/plane_parts/playerShip1_orange_01.png");
			equip_1_1 = Sprite::create("res/UI/plane_parts/playerShip1_orange_03.png");
			equip_1->setAnchorPoint(Vec2(0, 0));
			equip_1->setPosition(Vec2(0, 0));
			equip_1_1->setAnchorPoint(Vec2(1, 0));
			equip_1_1->setPosition(Vec2(this->getContentSize().width, 0));
			this->addChild(equip_1_1);
			this->addChild(equip_1);
		}
		else if (type==2)
		{
			equip_1 = Sprite::create("res/UI/plane_parts/playerShip1_red_01.png");
			equip_1_1 = Sprite::create("res/UI/plane_parts/playerShip1_red_03.png");
			equip_1->setAnchorPoint(Vec2(0, 0));
			equip_1->setPosition(Vec2(0, 0));
			equip_1_1->setAnchorPoint(Vec2(1, 0));
			equip_1_1->setPosition(Vec2(this->getContentSize().width, 0));
			this->addChild(equip_1_1);
			this->addChild(equip_1);
		}
		else if (type==1)
		{
			equip_1 = Sprite::create("res/UI/plane_parts/playerShip1_blue_01.png");
			equip_1_1 = Sprite::create("res/UI/plane_parts/playerShip1_blue_03.png");
			equip_1->setAnchorPoint(Vec2(0, 0));
			equip_1->setPosition(Vec2(0, 0));
			equip_1_1->setAnchorPoint(Vec2(1, 0));
			equip_1_1->setPosition(Vec2(this->getContentSize().width, 0));
			this->addChild(equip_1_1);
			this->addChild(equip_1);
		}

	}
	else if (this->type==2)
	{
		if (type==3)
		{
			equip_1 = Sprite::create("res/UI/plane_parts/playerShip2_orange_01.png");
			equip_1_1 = Sprite::create("res/UI/plane_parts/playerShip2_orange_03.png");
			equip_1->setAnchorPoint(Vec2(0, 0));
			equip_1->setPosition(Vec2(0, 0));
			equip_1_1->setAnchorPoint(Vec2(1, 0));
			equip_1_1->setPosition(Vec2(this->getContentSize().width, 0));
			this->addChild(equip_1_1);
			this->addChild(equip_1);
		}
		else if (type==2)
		{
			equip_1 = Sprite::create("res/UI/plane_parts/playerShip2_red_01.png");
			equip_1_1 = Sprite::create("res/UI/plane_parts/playerShip2_red_03.png");
			equip_1->setAnchorPoint(Vec2(0, 0));
			equip_1->setPosition(Vec2(0, 0));
			equip_1_1->setAnchorPoint(Vec2(1, 0));
			equip_1_1->setPosition(Vec2(this->getContentSize().width, 0));
			this->addChild(equip_1_1);
			this->addChild(equip_1);
		}
		else if (type==1)
		{
			equip_1 = Sprite::create("res/UI/plane_parts/playerShip2_blue_01.png");
			equip_1_1 = Sprite::create("res/UI/plane_parts/playerShip2_blue_03.png");
			equip_1->setAnchorPoint(Vec2(0, 0));
			equip_1->setPosition(Vec2(0, 0));
			equip_1_1->setAnchorPoint(Vec2(1, 0));
			equip_1_1->setPosition(Vec2(this->getContentSize().width, 0));
			this->addChild(equip_1_1);
			this->addChild(equip_1);
		}

	}
	else if (this->type==3)
	{
		if (type==3)
		{
			equip_1 = Sprite::create("res/UI/plane_parts/playerShip3_orange_01.png");
			equip_1_1 = Sprite::create("res/UI/plane_parts/playerShip3_orange_03.png");
			equip_1->setAnchorPoint(Vec2(0, 0));
			equip_1->setPosition(Vec2(0, 0));
			equip_1_1->setAnchorPoint(Vec2(1, 0));
			equip_1_1->setPosition(Vec2(this->getContentSize().width, 0));
			this->addChild(equip_1_1);
			this->addChild(equip_1);
		}
		else if (type==2)
		{
			equip_1 = Sprite::create("res/UI/plane_parts/playerShip3_red_01.png");
			equip_1_1 = Sprite::create("res/UI/plane_parts/playerShip3_red_03.png");
			equip_1->setAnchorPoint(Vec2(0, 0));
			equip_1->setPosition(Vec2(0, 0));
			equip_1_1->setAnchorPoint(Vec2(1, 0));
			equip_1_1->setPosition(Vec2(this->getContentSize().width, 0));
			this->addChild(equip_1_1);
			this->addChild(equip_1);
		}
		else if (type==1)
		{
			equip_1 = Sprite::create("res/UI/plane_parts/playerShip3_blue_01.png");
			equip_1_1 = Sprite::create("res/UI/plane_parts/playerShip3_blue_03.png");
			equip_1->setAnchorPoint(Vec2(0, 0));
			equip_1->setPosition(Vec2(0, 0));
			equip_1_1->setAnchorPoint(Vec2(1, 0));
			equip_1_1->setPosition(Vec2(this->getContentSize().width, 0));
			this->addChild(equip_1_1);
			this->addChild(equip_1);
		}

	}
}
void CCPlane::putOnEquip_2(int type)//456����
{
	if (this->type==3)
	{
		if (type == 3) {
			equip_2 = Sprite::create("res/UI/plane_parts/playerShip3_orange_02.png");
			equip_2->setAnchorPoint(Vec2(0.5, 1));
			equip_2->setPosition(Vec2(this->getContentSize().width / 2, this->getContentSize().height));
			this->addChild(equip_2);
		}
		else if (type==2)
		{
			equip_2 = Sprite::create("res/UI/plane_parts/playerShip3_red_02.png");
			equip_2->setAnchorPoint(Vec2(0.5, 1));
			equip_2->setPosition(Vec2(this->getContentSize().width / 2, this->getContentSize().height));
			this->addChild(equip_2);
		}
		else if (type==1)
		{
			equip_2 = Sprite::create("res/UI/plane_parts/playerShip3_blue_02.png");
			equip_2->setAnchorPoint(Vec2(0.5, 1));
			equip_2->setPosition(Vec2(this->getContentSize().width / 2, this->getContentSize().height));
			this->addChild(equip_2);
		}
	}
	else if (this->type==2)
	{
		if (type==3)
		{
			equip_2 = Sprite::create("res/UI/plane_parts/playerShip2_orange_02.png");
			equip_2->setAnchorPoint(Vec2(0.5, 1));
			equip_2->setPosition(Vec2(this->getContentSize().width / 2, this->getContentSize().height));
			this->addChild(equip_2);
		}
		else if (type==2)
		{
			equip_2 = Sprite::create("res/UI/plane_parts/playerShip2_red_02.png");
			equip_2->setAnchorPoint(Vec2(0.5, 1));
			equip_2->setPosition(Vec2(this->getContentSize().width / 2, this->getContentSize().height));
			this->addChild(equip_2);
		}
		else if (type==1)
		{
			equip_2 = Sprite::create("res/UI/plane_parts/playerShip2_blue_02.png");
			equip_2->setAnchorPoint(Vec2(0.5, 1));
			equip_2->setPosition(Vec2(this->getContentSize().width / 2, this->getContentSize().height));
			this->addChild(equip_2);
		}

	}
	else if (this->type==1)
	{
		if (type==3)
		{
			equip_2 = Sprite::create("res/UI/plane_parts/playerShip1_orange_02.png");
			equip_2->setAnchorPoint(Vec2(0.5, 1));
			equip_2->setPosition(Vec2(this->getContentSize().width / 2, this->getContentSize().height));
			this->addChild(equip_2);
		}
		else if (type==2)
		{
			equip_2 = Sprite::create("res/UI/plane_parts/playerShip1_red_02.png");
			equip_2->setAnchorPoint(Vec2(0.5, 1));
			equip_2->setPosition(Vec2(this->getContentSize().width / 2, this->getContentSize().height));
			this->addChild(equip_2);
		}
		else if (type==1)
		{
			equip_2 = Sprite::create("res/UI/plane_parts/playerShip1_blue_02.png");
			equip_2->setAnchorPoint(Vec2(0.5, 1));
			equip_2->setPosition(Vec2(this->getContentSize().width / 2, this->getContentSize().height));
			this->addChild(equip_2);
		}

	}
}
void CCPlane::putOnEquip_3(int type)//789����
{
	if (this->type==3)
	{
		if (type==3) {
			equip_3 = Sprite::create("res/UI/plane_parts/playerShip3_orange_04.png");
			equip_3->setAnchorPoint(Vec2(0.5, 0));
			equip_3->setPosition(Vec2(this->getContentSize().width / 2, 0));
			this->addChild(equip_3);
		}
		else if (type==2)
		{
			equip_3 = Sprite::create("res/UI/plane_parts/playerShip3_red_04.png");
			equip_3->setAnchorPoint(Vec2(0.5, 0));
			equip_3->setPosition(Vec2(this->getContentSize().width / 2, 0));
			this->addChild(equip_3);
		}
		else if (type==1)
		{
			equip_3 = Sprite::create("res/UI/plane_parts/playerShip3_blue_04.png");
			equip_3->setAnchorPoint(Vec2(0.5, 0));
			equip_3->setPosition(Vec2(this->getContentSize().width / 2, 0));
			this->addChild(equip_3);
		}
	}
	else if (this->type==2)
	{
		if (type == 3) {
			equip_3 = Sprite::create("res/UI/plane_parts/playerShip2_orange_04.png");
			equip_3->setAnchorPoint(Vec2(0.5, 0));
			equip_3->setPosition(Vec2(this->getContentSize().width / 2, 0));
			this->addChild(equip_3);
		}
		else if (type==2)
		{
			equip_3 = Sprite::create("res/UI/plane_parts/playerShip2_red_04.png");
			equip_3->setAnchorPoint(Vec2(0.5, 0));
			equip_3->setPosition(Vec2(this->getContentSize().width / 2, 0));
			this->addChild(equip_3);
		}
		else if (type==1)
		{
			equip_3 = Sprite::create("res/UI/plane_parts/playerShip2_blue_04.png");
			equip_3->setAnchorPoint(Vec2(0.5, 0));
			equip_3->setPosition(Vec2(this->getContentSize().width / 2, 0));
			this->addChild(equip_3);
		}
	}
	else if (this->type==1)
	{
		if (type == 3) {
			equip_3 = Sprite::create("res/UI/plane_parts/playerShip1_orange_04.png");
			equip_3->setAnchorPoint(Vec2(0.5, 0));
			equip_3->setPosition(Vec2(this->getContentSize().width / 2, 0));
			this->addChild(equip_3);
		}
		else if (type==2)
		{
			equip_3 = Sprite::create("res/UI/plane_parts/playerShip1_red_04.png");
			equip_3->setAnchorPoint(Vec2(0.5, 0));
			equip_3->setPosition(Vec2(this->getContentSize().width / 2, 0));
			this->addChild(equip_3);
		}
		else if (type==1)
		{
			equip_3 = Sprite::create("res/UI/plane_parts/playerShip1_blue_04.png");
			equip_3->setAnchorPoint(Vec2(0.5, 0));
			equip_3->setPosition(Vec2(this->getContentSize().width / 2, 0));
			this->addChild(equip_3);

		}
	}
}
