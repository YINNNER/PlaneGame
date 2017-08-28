#include"RepoLayer.h"
using namespace::std;
bool RepoLayer::init() {
	Size winSize = Director::getInstance()->getWinSize();
	auto origin = Director::getInstance()->getVisibleOrigin();



    //RepoLayer::Offset = 0;
	//RepoLayer::Tag= 1;
	//监听键盘事件
	auto listenerKeyboard = EventListenerKeyboard::create();
	listenerKeyboard->onKeyPressed = CC_CALLBACK_2(RepoLayer::onKeyPressed, this);
	listenerKeyboard->onKeyReleased = CC_CALLBACK_2(RepoLayer::onKeyReleased, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listenerKeyboard, this);
	this->schedule(schedule_selector(RepoLayer::equipUpdate), 0.15f);
	//this->schedule(SEL_SCHEDULE selector(RepoLayer::equipUpdate), 2.0f);
	//this->scheduleUpdate();

	_background = Sprite::create("res/UI/0Loading/star.png");
	_background->setPosition(Vec2(origin.x + winSize.width / 2, origin.y + winSize.height / 2));
	this->addChild(_background, 0);

	_background_1 = Sprite::create("res/UI/a6Repo/rect1.png");
	_background_1->setPosition(Vec2(origin.x + winSize.width * 0.3, origin.y + winSize.height * 3 / 4));
	this->addChild(_background_1, 2);

	_background_1_white = Sprite::create("res/UI/a6Repo/rectWhite.png");
	_background_1_white->setPosition(Vec2(origin.x + winSize.width * 0.3, origin.y + winSize.height * 3 / 4));
	this->addChild(_background_1_white, 2);

	_background_2 = Sprite::create("res/UI/a6Repo/rect2.png");
	_background_2->setPosition(Vec2(origin.x + winSize.width * 0.7, origin.y + winSize.height * 3 / 4));
	this->addChild(_background_2, 2);



	_background_3 = Sprite::create("res/UI/a6Repo/rect3.png");
	_background_3->setPosition(Vec2(origin.x + winSize.width * 0.5, origin.y + winSize.height * 0.5 ));
	this->addChild(_background_3, 1);

	auto _background_3_white_1 = MenuItemImage::create("res/UI/a6Repo/rectWhite.png", "res/UI/a6Repo/rectWhite.png", CC_CALLBACK_1(RepoLayer::menuCallBack_1, this, user.getPlaneType()));
	_background_3_white_1->setPosition(Vec2(origin.x + winSize.width * 0.2, origin.y + winSize.height * 0.5 ));
	_background_3_white_1->setScale(0.6);

	_background_3 = Sprite::create("res/UI/a6Repo/rect3.png");
	_background_3->setPosition(Vec2(origin.x + winSize.width * 0.5, origin.y + winSize.height * 0.3 ));
	this->addChild(_background_3, 1);

	auto _background_3_white_2 = MenuItemImage::create("res/UI/a6Repo/rectWhite.png", "res/UI/a6Repo/rectWhite.png", CC_CALLBACK_1(RepoLayer::menuCallBack_2, this, user.getPlaneType()));
   _background_3_white_2->setPosition(Vec2(origin.x + winSize.width * 0.2, origin.y + winSize.height * 0.3 ));
   _background_3_white_2->setScale(0.6);//缩放0.5倍

	_background_3 = Sprite::create("res/UI/a6Repo/rect3.png");
	_background_3->setPosition(Vec2(origin.x + winSize.width * 0.5, origin.y + winSize.height * 0.1 ));
	this->addChild(_background_3, 1);

	auto _background_3_white_3 = MenuItemImage::create("res/UI/a6Repo/rectWhite.png", "res/UI/a6Repo/rectWhite.png", CC_CALLBACK_1(RepoLayer::menuCallBack_3, this, user.getPlaneType()));
	_background_3_white_3->setPosition(Vec2(origin.x + winSize.width * 0.2, origin.y + winSize.height * 0.1 ));
	_background_3_white_3->setScale(0.6);//缩放0.5倍



	//设置飞机图片
	CCLOG("%f \n" ,user.getPlaneType());
	setPlaneImg(user.getPlaneType());

	//设置装备列表9个
	setEquipImg(user.getPlaneType());



	//返回按钮
	auto back = MenuItemImage::create("res/UI/a2SelectLevel/back.png", "res/UI/a2SelectLevel/backB.png", CC_CALLBACK_1(RepoLayer::CallMenu, this,user));
	back->setPosition(Vec2(winSize.width*0.15, winSize.height*0.9));
	back->setScale(0.55);
	back->setTag(2);

	//保存装备
	auto save = MenuItemImage::create("res/UI/a6Repo/saveEquip.png", "res/UI/a6Repo/saveEquipS.png", CC_CALLBACK_1(RepoLayer::CallMenu, this,user));
	save->setPosition(Vec2(winSize.width*0.8, winSize.height*0.9));
	save->setScale(0.55);
	save->setTag(2);

	auto menu = Menu::create(_background_3_white_1, _background_3_white_2, _background_3_white_3, back, save, NULL);
	menu->setPosition(Vec2(Point::ZERO));
	this->addChild(menu, 1);



	//传入战机名
	Label * planeName = Label::createWithTTF("plane1", "fonts/simhei.ttf", 28);
	planeName->setPosition(Vec2(origin.x + winSize.width * 0.6, origin.y + winSize.height * 0.84));
	this->addChild(planeName, 2);

	//传入等级值
	Label * level = Label::createWithTTF("lv.", "fonts/simhei.ttf", 28);
	level->setPosition(Vec2(origin.x + winSize.width * 0.8, origin.y + winSize.height * 0.84));
	this->addChild(level, 2);
	//飞机属性栏
	Label * life = Label::createWithTTF("生命", "fonts/simhei.ttf", 15);
	life->setPosition(Vec2(origin.x + winSize.width * 0.57, origin.y + winSize.height * 0.8));
	this->addChild(life, 2);

	Label *  energy = Label::createWithTTF("能量", "fonts/simhei.ttf", 15);
	energy->setPosition(Vec2(origin.x + winSize.width * 0.57, origin.y + winSize.height * 0.76));
	this->addChild(energy, 2);

	Label *  attack = Label::createWithTTF("攻击", "fonts/simhei.ttf", 15);
	attack->setPosition(Vec2(origin.x + winSize.width * 0.57, origin.y + winSize.height * 0.72));
	this->addChild(attack, 2);

	Label *  speed = Label::createWithTTF("速度", "fonts/simhei.ttf", 15);
	speed->setPosition(Vec2(origin.x + winSize.width * 0.57, origin.y + winSize.height * 0.68));
	this->addChild(speed, 2);
	//装备栏
   //机身
	_equip_head = Equip::create();
	_equip_head->setType(1);
	std::stringstream hp;
	hp << (_equip_head->getEHp());

	_equip_head_b = Equip::create();
	_equip_head_b->setType(2);
	std::stringstream hp_b;
	hp_b << (_equip_head_b->getEHp());

	 _equip_head_c = Equip::create();
	 _equip_head_c->setType(3);
	std::stringstream hp_c;
	hp_c << (_equip_head_c->getEHp());

	Label * equipName_1 = Label::createWithTTF("部件名称    机身", "fonts/simhei.ttf", 15);
	equipName_1->setPosition(Vec2(origin.x + winSize.width * 0.5, origin.y + winSize.height * 0.55 ));
	this->addChild(equipName_1, 1);

	Label * equipName_1_1 = Label::createWithTTF("hp", "fonts/simhei.ttf", 15);
	equipName_1_1->setPosition(Vec2(origin.x + winSize.width * 0.41, origin.y + winSize.height * 0.5 ));
	this->addChild(equipName_1_1, 1);

	equipNum_1_1 = Label::createWithTTF(hp.str().c_str(), "fonts/simhei.ttf", 15);
	equipNum_1_1->setPosition(Vec2(origin.x + winSize.width * 0.5, origin.y + winSize.height * 0.5 ));
	this->addChild(equipNum_1_1, 1);

	equipNum_1_2 = Label::createWithTTF(hp_b.str().c_str(), "fonts/simhei.ttf", 15);
	equipNum_1_2->setPosition(Vec2(origin.x + winSize.width * 1.5 , origin.y + winSize.height * 0.5));
	this->addChild(equipNum_1_2, 1);

	equipNum_1_3 = Label::createWithTTF(hp_c.str().c_str(), "fonts/simhei.ttf", 15);
	equipNum_1_3->setPosition(Vec2(origin.x + winSize.width * 2.5, origin.y + winSize.height * 0.5));
	this->addChild(equipNum_1_3, 1);

	/*Label * equipName_1_2 = Label::createWithTTF("数量", "fonts/simhei.ttf", 15);
	equipName_1_2->setPosition(Vec2(origin.x + winSize.width * 0.7, origin.y + winSize.height * 0.5 ));
	this->addChild(equipName_1_2, 1);

	Label * equipNum_1_2 = Label::createWithTTF(b.str().c_str(), "fonts/simhei.ttf", 15);
	equipNum_1_2->setPosition(Vec2(origin.x + winSize.width * 0.8, origin.y + winSize.height * 0.5 ));
	this->addChild(equipNum_1_2, 1);*/

	//机翼
	_equip_arm = Equip::create();
	_equip_arm->setType(4);
	std::stringstream atk;
	atk << (_equip_arm->getEAtk());

	_equip_arm_b = Equip::create();
	_equip_arm_b->setType(5);
	std::stringstream atk_b;
	atk_b << (_equip_arm_b->getEAtk());

	_equip_arm_c = Equip::create();
	_equip_arm_c->setType(6);
	std::stringstream atk_c;
	atk_c << (_equip_arm_c->getEAtk());
	//d << (_equip_2->getEquipNum());

	Label * equipName_2 = Label::createWithTTF("部件名称    机翼", "fonts/simhei.ttf", 15);
	equipName_2->setPosition(Vec2(origin.x + winSize.width * 0.5, origin.y + winSize.height * 0.35 ));
	this->addChild(equipName_2, 1);

	Label * equipName_2_1 = Label::createWithTTF("攻击", "fonts/simhei.ttf", 15);
	equipName_2_1->setPosition(Vec2(origin.x + winSize.width * 0.41, origin.y + winSize.height * 0.3 ));
	this->addChild(equipName_2_1, 1);

	equipNum_2_1 = Label::createWithTTF(atk.str().c_str(), "fonts/simhei.ttf", 15);
	equipNum_2_1->setPosition(Vec2(origin.x + winSize.width * 0.5, origin.y + winSize.height * 0.3));
	this->addChild(equipNum_2_1, 1);

	equipNum_2_2 = Label::createWithTTF(atk_b.str().c_str(), "fonts/simhei.ttf", 15);
	equipNum_2_2->setPosition(Vec2(origin.x + winSize.width * 1.5, origin.y + winSize.height * 0.3));
	this->addChild(equipNum_2_2, 1);

	equipNum_2_3 = Label::createWithTTF(atk_c.str().c_str(), "fonts/simhei.ttf", 15);
	equipNum_2_3->setPosition(Vec2(origin.x + winSize.width * 2.5, origin.y + winSize.height * 0.3));
	this->addChild(equipNum_2_3, 1);

	/*Label * equipName_2_2 = Label::createWithTTF("数量", "fonts/simhei.ttf", 15);
	equipName_2_2->setPosition(Vec2(origin.x + winSize.width * 0.7, origin.y + winSize.height * 0.3 ));
	this->addChild(equipName_2_2, 1);

	Label * equipNum_2_2 = Label::createWithTTF(d.str().c_str(), "fonts/simhei.ttf", 15);
	equipNum_2_2->setPosition(Vec2(origin.x + winSize.width * 0.8, origin.y + winSize.height * 0.3 ));
	this->addChild(equipNum_2_2, 1);*/

	//机尾
	_equip_tail = Equip::create();
	_equip_tail->setType(7);
	std::stringstream spd;
	spd << (_equip_tail->getESpd());

	_equip_tail_b = Equip::create();
	_equip_tail_b->setType(8);
	std::stringstream spd_b;
	spd_b << (_equip_tail_b->getESpd());

	_equip_tail_c = Equip::create();
	_equip_tail_c->setType(9);
	std::stringstream spd_c;
	spd_c << (_equip_tail_c->getESpd());
	//f << (_equip_3->getEquipNum());

	Label * equipName_3 = Label::createWithTTF("部件名称    机尾", "fonts/simhei.ttf", 15);
	equipName_3->setPosition(Vec2(origin.x + winSize.width * 0.5, origin.y + winSize.height * 0.15 ));
	this->addChild(equipName_3, 1);


	Label * equipName_3_1 = Label::createWithTTF("速度", "fonts/simhei.ttf", 15);
	equipName_3_1->setPosition(Vec2(origin.x + winSize.width * 0.41, origin.y + winSize.height * 0.1 ));
	this->addChild(equipName_3_1, 1);

	equipNum_3_1 = Label::createWithTTF(spd.str().c_str(), "fonts/simhei.ttf", 15);
	equipNum_3_1->setPosition(Vec2(origin.x + winSize.width * 0.5, origin.y + winSize.height * 0.1));
	this->addChild(equipNum_3_1, 1);

	equipNum_3_2 = Label::createWithTTF(spd_b.str().c_str(), "fonts/simhei.ttf", 15);
	equipNum_3_2->setPosition(Vec2(origin.x + winSize.width * 1.5, origin.y + winSize.height * 0.1));
	this->addChild(equipNum_3_2, 1);

	equipNum_3_3 = Label::createWithTTF(spd_c.str().c_str(), "fonts/simhei.ttf", 15);
	equipNum_3_3->setPosition(Vec2(origin.x + winSize.width * 2.5, origin.y + winSize.height * 0.1));
	this->addChild(equipNum_3_3, 1);

	/*Label * equipName_3_2 = Label::createWithTTF("数量", "fonts/simhei.ttf", 15);
	equipName_3_2->setPosition(Vec2(origin.x + winSize.width * 0.7, origin.y + winSize.height * 0.1 ));
	this->addChild(equipName_3_2, 1);

	Label * equipNum_3_2 = Label::createWithTTF(f.str().c_str(), "fonts/simhei.ttf", 15);
	equipNum_3_2->setPosition(Vec2(origin.x + winSize.width * 0.8, origin.y + winSize.height * 0.1 ));
	this->addChild(equipNum_3_2, 1);*/

	//飞机进度条
	BaseBarHp = Sprite::create("res/UI/0Loading/loadingBarEmpty.png");
	BaseBarHp->setPosition(Vec2(origin.x + winSize.width *0.71, origin.y + winSize.height *0.8));
	BaseBarHp->setScale(0.25, 0.5);
	this->addChild(BaseBarHp, 2);

	BaseBarEn = Sprite::create("res/UI/0Loading/loadingBarEmpty.png");
	BaseBarEn->setPosition(Vec2(origin.x + winSize.width *0.71, origin.y + winSize.height *0.76));
	BaseBarEn->setScale(0.25, 0.5);
	this->addChild(BaseBarEn, 2);

	BaseBarAtk = Sprite::create("res/UI/0Loading/loadingBarEmpty.png");
	BaseBarAtk->setPosition(Vec2(origin.x + winSize.width *0.71, origin.y + winSize.height *0.72));
	BaseBarAtk->setScale(0.25, 0.5);
	this->addChild(BaseBarAtk, 2);

	BaseBarSpd = Sprite::create("res/UI/0Loading/loadingBarEmpty.png");
	BaseBarSpd->setPosition(Vec2(origin.x + winSize.width *0.71, origin.y + winSize.height *0.68));
	BaseBarSpd->setScale(0.25, 0.5);
	this->addChild(BaseBarSpd, 2);

	HpBar = Sprite::create("res/UI/0Loading/loadingBarFull.png");
	HpBar->setPosition(Vec2(origin.x + winSize.width *0.641, origin.y + winSize.height *0.798));
	HpBar->setScale(0.25*(_equip_head->getEHp()) / 1000, 0.5);
	HpBar->setAnchorPoint(Vec2(0, 0));
	this->addChild(HpBar, 2);
	/*
	EnBar = Sprite::create("res/UI/0Loading/loadingBarFull.png");
	EnBar->setPosition(Vec2(origin.x+winSize.width *0.665, origin.y+winSize.height *0.76));
	EnBar->setScale(0.25*(_equip_2->getImpAtk()) / 1000, 0.5);
	EnBar->setAnchorPoint(Vec2(0, 0));
	this->addChild(EnBar);
*/
	AtkBar = Sprite::create("res/UI/0Loading/loadingBarFull.png");
	AtkBar->setPosition(Vec2(origin.x + winSize.width *0.64, origin.y + winSize.height *0.718));
	AtkBar->setScale(0.25*(_equip_arm->getEAtk()) / 1000, 0.5);
	AtkBar->setAnchorPoint(Vec2(0, 0));
	this->addChild(AtkBar, 2);

	SpdBar = Sprite::create("res/UI/0Loading/loadingBarFull.png");
	SpdBar->setPosition(Vec2(origin.x + winSize.width *0.641, origin.y + winSize.height *0.678));
	SpdBar->setScale(0.25*(_equip_tail->getESpd()) / 1000, 0.5);
	SpdBar->setAnchorPoint(Vec2(0, 0));
	this->addChild(SpdBar, 2);

	return true;



}
void RepoLayer::menuCallBack_1(Ref * pSender,int type) {

	Size winSize = Director::getInstance()->getWinSize();
	auto origin = Director::getInstance()->getVisibleOrigin();
	stringstream filename1;
	stringstream filename2;
	stringstream filename3;
	filename1 << "res/UI/plane_parts/playerShip" << type << "_blue_02.png";
	filename2 << "res/UI/plane_parts/playerShip" << type << "_orange_02.png";
	filename3 << "res/UI/plane_parts/playerShip" << type << "_red_02.png";
	//加那个图片
	if (_equip_1->getPositionX()==120 && user.get_equip_head().x==1) {
		_body_1 = Sprite::create(filename1.str().c_str());
		_body_1->setPosition(Vec2(winSize.width*0.3, origin.y + winSize.height * 0.757));
		this->addChild(_body_1, 2);
	}
	else if (_equip_1_b->getPositionX()==120 && user.get_equip_head_b().x == 1) {
		_body_1_b = Sprite::create(filename2.str().c_str());
		_body_1_b->setPosition(Vec2(winSize.width*0.3, winSize.height * 0.757));
		this->addChild(_body_1_b, 2);
	}
	else if (_equip_1_c->getPositionX()==120 && user.get_equip_head_c().x == 1) {
		_body_1_c = Sprite::create(filename3.str().c_str());
		_body_1_c->setPosition(Vec2(winSize.width*0.3, origin.y + winSize.height * 0.757));
		this->addChild(_body_1_c, 2);
	}

	

	//void setEHP(存档中 + getImpHp(type（哪个等级的装备）));

}

void RepoLayer::menuCallBack_2(Ref * pSender,int type) {
	Size winSize = Director::getInstance()->getWinSize();
	auto origin = Director::getInstance()->getVisibleOrigin();

	stringstream filename1;
	stringstream filename2;
	stringstream filename3;
	filename1 << "res/UI/plane_parts/playerShip" << type << "_blue_01.png";
	filename2 << "res/UI/plane_parts/playerShip" << type << "_orange_01.png";
	filename3 << "res/UI/plane_parts/playerShip" << type << "_red_01.png";

	if (_equip_1->getPositionX() == 120&&user.get_equip_arm().x == 1) {
		_wing_1 = Sprite::create(filename1.str().c_str());
		_wing_1->setPosition(Vec2(origin.x + winSize.width*0.26, origin.y + winSize.height * 0.75));
		this->addChild(_wing_1, 2);
	}
	else if (_equip_1_b->getPositionX() == 120 && user.get_equip_arm_b().x == 1) {
		_wing_1_b = Sprite::create(filename2.str().c_str());
		_wing_1_b->setPosition(Vec2(origin.x + winSize.width*0.26, origin.y + winSize.height * 0.75));
		this->addChild(_wing_1_b, 2);
	}
	else if (_equip_1_c->getPositionX() == 120 && user.get_equip_arm_c().x == 1) {
		_wing_1_c = Sprite::create(filename3.str().c_str());
		_wing_1_c->setPosition(Vec2(origin.x + winSize.width*0.26, origin.y + winSize.height * 0.75));
		this->addChild(_wing_1_c, 2);
	}

	stringstream filename4;
	stringstream filename5;
	stringstream filename6;
	filename4 << "res/UI/plane_parts/playerShip" << type << "_blue_03.png";
	filename5 << "res/UI/plane_parts/playerShip" << type << "_orange_03.png";
	filename6 << "res/UI/plane_parts/playerShip" << type << "_red_03.png";

	if (_equip_1->getPositionX() == 120 && user.get_equip_arm().x == 1) {
		_wing_2 = Sprite::create(filename4.str().c_str());
		_wing_2->setPosition(Vec2(origin.x + winSize.width*0.34, origin.y + winSize.height * 0.75));
		this->addChild(_wing_2, 2);
	}
	else if (_equip_1_b->getPositionX() == 120 && user.get_equip_arm_b().x == 1) {
		_wing_2_b = Sprite::create(filename5.str().c_str());
		_wing_2_b->setPosition(Vec2(origin.x + winSize.width*0.34, origin.y + winSize.height * 0.75));
		this->addChild(_wing_2_b, 2);
	}
	else if (_equip_1_c->getPositionX() == 120 && user.get_equip_arm_b().x == 1) {
		_wing_2_c = Sprite::create(filename6.str().c_str());
		_wing_2_c->setPosition(Vec2(origin.x + winSize.width*0.34, origin.y + winSize.height * 0.75));
		this->addChild(_wing_2_c, 2);
	}

	
}

void RepoLayer::menuCallBack_3(Ref * pSender,int type) {
	Size winSize = Director::getInstance()->getWinSize();
	auto origin = Director::getInstance()->getVisibleOrigin();

	stringstream filename1;
	stringstream filename2;
	stringstream filename3;
	filename1 << "res/UI/plane_parts/playerShip" << type << "_blue_04.png";
	filename2 << "res/UI/plane_parts/playerShip" << type << "_orange_04.png";
	filename3 << "res/UI/plane_parts/playerShip" << type << "_red_04.png";

	if (_equip_1->getPositionX() == 120 && user.get_equip_tail().x == 1) {
		_tail_1 = Sprite::create(filename1.str().c_str());
		_tail_1->setPosition(Vec2(origin.x + winSize.width*0.3, origin.y + winSize.height * 0.717));
		this->addChild(_tail_1, 2);
	}
	else if (_equip_1_b->getPositionX() == 120 && user.get_equip_tail_b().x == 1) {
		_tail_1_b = Sprite::create(filename2.str().c_str());
		_tail_1_b->setPosition(Vec2(origin.x + winSize.width*0.3, origin.y + winSize.height * 0.717));
		this->addChild(_tail_1_b, 2);
	}
	else if (_equip_1_c->getPositionX() == 120 && user.get_equip_tail_c().x == 1) {
		_tail_1_c = Sprite::create(filename3.str().c_str());
		_tail_1_c->setPosition(Vec2(origin.x + winSize.width*0.3, origin.y + winSize.height * 0.717));
		this->addChild(_tail_1_c, 2);
	}
}


//返回关卡选择
void RepoLayer::CallMenu(Ref * pSender,UserInfo & userInfo)
{
	SceneManager::goMapLayer(2,user);
}

void RepoLayer::SaveEquip(Ref * pSender, UserInfo & userInfo)
{
	SceneManager::goMapLayer(2, user);
}

//设置装备栏的图片
void RepoLayer::setEquipImg(int type) {
	Size winSize = Director::getInstance()->getWinSize();
	auto origin = Director::getInstance()->getVisibleOrigin();
	stringstream filename1;
	stringstream filename2;
	stringstream filename3;
	stringstream filename4;
	stringstream filename5;
	stringstream filename6;
	stringstream filename7;
	stringstream filename8;
	stringstream filename9;
	filename1 << "res/UI/plane_parts/playerShip" << type << "_blue_02.png";
	filename2 << "res/UI/plane_parts/playerShip" << type << "_orange_02.png";
	filename3 << "res/UI/plane_parts/playerShip" << type << "_red_02.png";
	filename4 << "res/UI/plane_parts/playerShip" << type << "_blue_01.png";
	filename5 << "res/UI/plane_parts/playerShip" << type << "_orange_01.png";
	filename6 << "res/UI/plane_parts/playerShip" << type << "_red_01.png";
	filename7 << "res/UI/plane_parts/playerShip" << type << "_blue_04.png";
	filename8 << "res/UI/plane_parts/playerShip" << type << "_orange_04.png";
	filename9 << "res/UI/plane_parts/playerShip" << type << "_red_04.png";

	_equip_1 = Sprite::create(filename1.str().c_str());
	_equip_1->setPosition(Vec2(winSize.width *0.2, winSize.height *0.5));
	this->addChild(_equip_1, 3);

	_equip_1_b = Sprite::create(filename2.str().c_str());
	_equip_1_b->setPosition(Vec2(winSize.width *1.2, winSize.height *0.5));
	this->addChild(_equip_1_b, 2);
	//CCLOG("%f \n", Vec2(_equip_1_b->getPosition()).x);

	_equip_1_c = Sprite::create(filename3.str().c_str());
	_equip_1_c->setPosition(Vec2(winSize.width *2.2, origin.y + winSize.height *0.5));
	this->addChild(_equip_1_c, 2);

	_equip_2 = Sprite::create(filename4.str().c_str());
	_equip_2->setPosition(Vec2(winSize.width *0.2, winSize.height *0.3));
	this->addChild(_equip_2, 2);

	_equip_2_b = Sprite::create(filename5.str().c_str());
	_equip_2_b->setPosition(Vec2(winSize.width *1.2, winSize.height *0.3));
	this->addChild(_equip_2_b, 2);

	_equip_2_c = Sprite::create(filename6.str().c_str());
	_equip_2_c->setPosition(Vec2(winSize.width *2.2, winSize.height *0.3));
	this->addChild(_equip_2_c, 2);

	_equip_3 = Sprite::create(filename7.str().c_str());
	_equip_3->setPosition(Vec2(winSize.width *0.2, winSize.height *0.1));
	this->addChild(_equip_3, 2);

	_equip_3_b = Sprite::create(filename8.str().c_str());
	_equip_3_b->setPosition(Vec2(winSize.width *1.2, winSize.height *0.1));
	this->addChild(_equip_3_b, 2);

	_equip_3_c = Sprite::create(filename9.str().c_str());
	_equip_3_c->setPosition(Vec2(winSize.width *2.2, winSize.height *0.1));
	this->addChild(_equip_3_c, 2);

}


void RepoLayer::setPlaneImg(int type) {
	Size winSize = Director::getInstance()->getWinSize();
	auto origin = Director::getInstance()->getVisibleOrigin();
	stringstream filename;

	filename << "res/UI/plane_parts/playerShip" << type << "_green.png";
	_plane = Sprite::create(filename.str().c_str());
	_plane->setPosition(Vec2(origin.x + winSize.width*0.3, origin.y + winSize.height * 3 / 4));
	this->addChild(_plane, 2);
	if (user.get_equip_head().y == 1) {
		stringstream filename1;
		filename1 << "res/UI/plane_parts/playerShip" << type << "_blue_02.png";
		_body_1 = Sprite::create(filename1.str().c_str());
		_body_1->setPosition(Vec2(winSize.width*0.3, origin.y + winSize.height * 0.757));
		this->addChild(_body_1, 2);
	}
	else if (user.get_equip_head_b().y == 1) {
		stringstream filename2;
		filename2 << "res/UI/plane_parts/playerShip" << type << "_orange_02.png";
		_body_1_b = Sprite::create(filename2.str().c_str());
		_body_1_b->setPosition(Vec2(winSize.width*0.3, winSize.height * 0.757));
		this->addChild(_body_1_b, 2);
	}
	else if (user.get_equip_head_c().y == 1) {
		stringstream filename3;
		filename3 << "res/UI/plane_parts/playerShip" << type << "_red_02.png";
		_body_1_c = Sprite::create(filename3.str().c_str());
		_body_1_c->setPosition(Vec2(winSize.width*0.3, origin.y + winSize.height * 0.757));
		this->addChild(_body_1_c, 2);
	}

	else if (user.get_equip_arm().y == 1) {
		stringstream filename4;
		stringstream filename7;
		filename4 << "res/UI/plane_parts/playerShip" << type << "_blue_01.png";
		filename7 << "res/UI/plane_parts/playerShip" << type << "_blue_03.png";
		_wing_1 = Sprite::create(filename4.str().c_str());
		_wing_1->setPosition(Vec2(origin.x + winSize.width*0.26, origin.y + winSize.height * 0.75));
		this->addChild(_wing_1, 2);
		_wing_2 = Sprite::create(filename7.str().c_str());
		_wing_2->setPosition(Vec2(origin.x + winSize.width*0.34, origin.y + winSize.height * 0.75));
		this->addChild(_wing_2, 2);
	}
	else if (user.get_equip_arm_b().y == 1) {
		stringstream filename5;
		stringstream filename8;
		filename5 << "res/UI/plane_parts/playerShip" << type << "_orange_01.png";
		filename8 << "res/UI/plane_parts/playerShip" << type << "_orange_03.png";
		_wing_1_b = Sprite::create(filename5.str().c_str());
		_wing_1_b->setPosition(Vec2(origin.x + winSize.width*0.26, origin.y + winSize.height * 0.75));
		this->addChild(_wing_1_b, 2);
		_wing_2_b = Sprite::create(filename8.str().c_str());
		_wing_2_b->setPosition(Vec2(origin.x + winSize.width*0.34, origin.y + winSize.height * 0.75));
		this->addChild(_wing_2_b, 2);
	}
	else if (user.get_equip_arm_c().y == 1) {
		stringstream filename6;
		stringstream filename9;
		filename6 << "res/UI/plane_parts/playerShip" << type << "_red_01.png";
		filename9 << "res/UI/plane_parts/playerShip" << type << "_red_03.png";
		_wing_1_c = Sprite::create(filename6.str().c_str());
		_wing_1_c->setPosition(Vec2(origin.x + winSize.width*0.26, origin.y + winSize.height * 0.75));
		this->addChild(_wing_1_c, 2);
		_wing_2_c = Sprite::create(filename9.str().c_str());
		_wing_2_c->setPosition(Vec2(origin.x + winSize.width*0.34, origin.y + winSize.height * 0.75));
		this->addChild(_wing_2_c, 2);
	}
	else if (user.get_equip_tail().y == 1) {
		stringstream filename1;
		filename1 << "res/UI/plane_parts/playerShip" << type << "_blue_04.png";
		_tail_1 = Sprite::create(filename1.str().c_str());
		_tail_1->setPosition(Vec2(origin.x + winSize.width*0.3, origin.y + winSize.height * 0.717));
		this->addChild(_tail_1, 2);
	}
	else if (user.get_equip_tail_b().y == 1) {
		stringstream filename2;
		filename2 << "res/UI/plane_parts/playerShip" << type << "_orange_04.png";
		_tail_1_b = Sprite::create(filename2.str().c_str());
		_tail_1_b->setPosition(Vec2(origin.x + winSize.width*0.3, origin.y + winSize.height * 0.717));
		this->addChild(_tail_1_b, 2);
	}
	else if (user.get_equip_tail_c().y == 1) {
		stringstream filename3;
		filename3 << "res/UI/plane_parts/playerShip" << type << "_red_04.png";
		_tail_1_c = Sprite::create(filename3.str().c_str());
		_tail_1_c->setPosition(Vec2(origin.x + winSize.width*0.3, origin.y + winSize.height * 0.717));
		this->addChild(_tail_1_c, 2);
	}
}


//监听键盘修改RepoLayer::Offset
void RepoLayer::onKeyPressed(EventKeyboard::KeyCode keyCode, Event * event)
{
	key = keyCode;


}


void RepoLayer::onKeyReleased(EventKeyboard::KeyCode keyCode, Event * event)
{
	if (key == keyCode)
	{
		key = EventKeyboard::KeyCode::KEY_NONE;
	}
}

void RepoLayer::equipUpdate(float dt)
{
	Size winSize = Director::getInstance()->getWinSize();
	auto origin = Director::getInstance()->getVisibleOrigin();
	//CCLOG("%s \n", "A string");
	switch (key) {
	case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
		if (_equip_1->getPositionX() > -1080) {
			_equip_1->setPositionX(_equip_1->getPositionX() - winSize.width);
			_equip_1_b->setPositionX(_equip_1_b->getPositionX() - winSize.width);
			_equip_1_c->setPositionX(_equip_1_c->getPositionX() - winSize.width);
			equipNum_1_1->setPositionX(equipNum_1_1->getPositionX() - winSize.width);
			equipNum_1_2->setPositionX(equipNum_1_2->getPositionX() - winSize.width);
			equipNum_1_3->setPositionX(equipNum_1_3->getPositionX() - winSize.width);

			_equip_2->setPositionX(_equip_2->getPositionX() - winSize.width);
			_equip_2_b->setPositionX(_equip_2_b->getPositionX() - winSize.width);
			_equip_2_c->setPositionX(_equip_2_c->getPositionX() - winSize.width);
			equipNum_2_1->setPositionX(equipNum_2_1->getPositionX() - winSize.width);
			equipNum_2_2->setPositionX(equipNum_2_2->getPositionX() - winSize.width);
			equipNum_2_3->setPositionX(equipNum_2_3->getPositionX() - winSize.width);

			_equip_3->setPositionX(_equip_3->getPositionX() - winSize.width);
			_equip_3_b->setPositionX(_equip_3_b->getPositionX() - winSize.width);
			_equip_3_c->setPositionX(_equip_3_c->getPositionX() - winSize.width);
			equipNum_3_1->setPositionX(equipNum_3_1->getPositionX() - winSize.width);
			equipNum_3_2->setPositionX(equipNum_3_2->getPositionX() - winSize.width);
			equipNum_3_3->setPositionX(equipNum_3_3->getPositionX() - winSize.width);

			CCLOG("%f \n", Vec2(_equip_1_b->getPosition()).x);
			CCLOG("%f \n", _equip_1_b->getPositionX());
		}
		else {
			_equip_1->setPosition(Vec2(winSize.width *0.2, winSize.height *0.5));
			_equip_1_b->setPosition(Vec2(winSize.width *1.2, winSize.height *0.5));
			_equip_1_c->setPosition(Vec2(winSize.width *2.2, winSize.height *0.5));
			_equip_2->setPosition(Vec2(winSize.width *0.2, winSize.height *0.3));
			_equip_2_b->setPosition(Vec2(winSize.width *1.2, winSize.height *0.3));
			_equip_2_c->setPosition(Vec2(winSize.width *2.2, winSize.height *0.3));
			_equip_3->setPosition(Vec2(winSize.width *0.2, winSize.height *0.1));
			_equip_3_b->setPosition(Vec2(winSize.width *1.2, winSize.height *0.1));
			_equip_3_c->setPosition(Vec2(winSize.width *2.2, winSize.height *0.1));

			equipNum_1_1->setPosition(Vec2(origin.x + winSize.width * 0.5, origin.y + winSize.height * 0.5));
			equipNum_1_2->setPosition(Vec2(origin.x + winSize.width * 1.5, origin.y + winSize.height * 0.5));
			equipNum_1_3->setPosition(Vec2(origin.x + winSize.width * 2.5, origin.y + winSize.height * 0.5));

			equipNum_2_1->setPosition(Vec2(origin.x + winSize.width * 0.5, origin.y + winSize.height * 0.3));
			equipNum_2_2->setPosition(Vec2(origin.x + winSize.width * 1.5, origin.y + winSize.height * 0.3));
			equipNum_2_3->setPosition(Vec2(origin.x + winSize.width * 2.5, origin.y + winSize.height * 0.3));

			equipNum_3_1->setPosition(Vec2(origin.x + winSize.width * 0.5, origin.y + winSize.height * 0.1));
			equipNum_3_2->setPosition(Vec2(origin.x + winSize.width * 1.5, origin.y + winSize.height * 0.1));
			equipNum_3_3->setPosition(Vec2(origin.x + winSize.width * 2.5, origin.y + winSize.height * 0.1));
		}

		break;
		//_equip_1->removeFromParentAndCleanup(true); 
	/*case EventKeyboard::KeyCode::KEY_W:
		if (_equip_3->getPositionX() <= 1320) {
			_equip_1->setPositionX(_equip_1->getPositionX() +winSize.width);
			_equip_1_b->setPositionX(_equip_1_b->getPositionX() + winSize.width);
			_equip_1_c->setPositionX(_equip_1_c->getPositionX() + winSize.width);

			_equip_2->setPositionX(_equip_2->getPositionX() + winSize.width);
			_equip_2_b->setPositionX(_equip_2_b->getPositionX() + winSize.width);
			_equip_2_c->setPositionX(_equip_2_c->getPositionX() + winSize.width);

			_equip_3->setPositionX(_equip_3->getPositionX() + winSize.width);
			_equip_3_b->setPositionX(_equip_3_b->getPositionX() + winSize.width);
			_equip_3_c->setPositionX(_equip_3_c->getPositionX() + winSize.width);
			CCLOG("%f \n", Vec2(_equip_1_b->getPosition()).x);
			CCLOG("%f \n", _equip_1_b->getPositionX());
		}
		else {
			_equip_1->setPosition(Vec2(winSize.width *0.2, winSize.height *0.5));
			_equip_1_b->setPosition(Vec2(winSize.width *1.2, winSize.height *0.5));
			_equip_1_c->setPosition(Vec2(winSize.width *2.2, winSize.height *0.5));
			_equip_2->setPosition(Vec2(winSize.width *0.2, winSize.height *0.3));
			_equip_2_b->setPosition(Vec2(winSize.width *1.2, winSize.height *0.3));
			_equip_2_c->setPosition(Vec2(winSize.width *2.2, winSize.height *0.3));
			_equip_3->setPosition(Vec2(winSize.width *0.2, winSize.height *0.1));
			_equip_3_b->setPosition(Vec2(winSize.width *1.2, winSize.height *0.1));
			_equip_3_c->setPosition(Vec2(winSize.width *2.2, winSize.height *0.1));
		}
		break;*/
	}

}
/*setTouchEnable(true);
setTouchMode(Touch::DispatchMode::ONE_BY_ONE);
/*
auto listener = EventListenerMouse::create();
listener->onMouseDown = [](Event * event){
EventMouse * e = (EventMouse * )event;
}
*/
/*MenuItemLabel * menuItem = MenuItemLabel::create(Label::createWithSystemFont(" / res / SpaceShooterRedux / PNG / Parts / cockpitBlue_1.png", "", ), CC_CALLBACK_1(OpenLayer::menuCallBack, this));
//使用1进行标记
menuItem->set1(101);
menuItem->setPosition(Vec2(origin.x+winSize.width / 2, origin.y+winSize.height*0.3));
static MenuItemSprite * create(Node * normalSprite, Node * normalSprite, Node * normalSprite, );
MenuItemImage * equip_1 = MenuItemImage::create("res/SpaceShooterRedux/PNG/Planes/playerShip1_green.png", "res/SpaceShooterRedux/PNG/Planes/playerShip1_green.png");
MenuItemImage * equip_2 = MenuItemImage::create("res/SpaceShooterRedux/PNG/Planes/playerShip1_blue.png", "res/SpaceShooterRedux/PNG/Planes/playerShip1_blue.png");
MenuItemToggle* equip = MenuItemToggle::createWithTarget(this,menu_selector(RepoLayer::changeEquip),equip_1,equip_2,NULL);

Menu * equipMenu = Menu::create(equip,NULL);
equip->setPosition(Vec2(origin.x+winSize.width / 2, origin.y+winSize.height*0.3));
equipMenu->setPosition(Vec2::ZERO);
this->addChild(equip);*/



/*void RepoLayer::onEnter() {
Layer::onEnter();
//创建监听器对象

auto listener = EventListenerTouchOneByOne::create();
//是够吞没事件,true则事件不会传递给下一个对象
listener->setSwallowTouches(true);
//设置回调函数
listener->onTouchBegan = CC_CALLBACK_2(RepoLayer::touchBegan, this);
//注册监听器
auto eventDispatcher = Director::getInstance()->getEventDispatcher();
eventDispatcher->addEventListenerWithSceneGraphPriority(listener, getChildBy1(kEquip_1_1));
eventDispatcher->addEventListenerWithSceneGraphPriority(listener->clone(), getChildBy1(kEquip_2_1));
eventDispatcher->addEventListenerWithSceneGraphPriority(listener->clone(), getChildBy1(kEquip_3_1));

}*/


/*bool RepoLayer::onTouchBegan(Touch * touch, Event * event) {
//获得事件绑定的target
auto target = static_cast<Sprite *>(event->getCurrentTarget());//强制转换为sprite对象
Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());//获取触摸点相对于target对象的模型坐标
Size s = target->getContentSize();//获得target对象尺寸
Rect rect = Rect(0, 0, s.width, s.height);//放大target对象

//单击范围判断检测
if (rect.containsPoint(locationInNode)) {
target->runAction(ScaleBy::create(0.06f, 1.06f));
Size winSize = Director::getInstance()->getWinSize();
_plane_2 = Sprite::create("res/SpaceShooterRedux/PNG/Planes/playerShip1_green.png");
_plane_2->setPosition(Vec2(origin.x+winSize.width*0.3, origin.y+winSize.height * 3 / 4));
//_plane->setScale(0.9);
this->addChild(_plane_2);
return true;
}
return false;
}*/
/*
//注销所有监听事件
void RepoLayer::onExit() {
Layer::onExit();
Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
}
*/


/*void RepoLayer::menuCallBack_4(Ref * pSender) {
	Size winSize = Director::getInstance()->getWinSize();
	auto origin = Director::getInstance()->getVisibleOrigin();

	_equip_1Img = Sprite::create("res/UI/plane_parts/planeType1/playerShip1_blue_01.png");
	_equip_1Img->setPosition(Vec2(origin.x + winSize.width *0.2, origin.y + winSize.height *0.5));
	//_equip_1Img->setScale(0.95);//缩放0.5倍
	this->addChild(_equip_1Img, 0, 1);

}*/
/*int RepoLayer::getHpBarLength(int life)
{
	//获得飞机现在生命值+_EquipNum*(Equip::getImpHp)
	return 0;
}*/

/*
void RepoLayer::hpUpdate(int dt) {

}

bool RepoLayer::onTouchBegan(Touch * touch, Event * event) {
	auto _equip_1 = this->getChildBy1e(equip_1_1);
	if (this->isTap(_equip_1, touch)) {
		//更换飞机图片
		_plane
	}
	return true；
}
*/
