#include"RepoLayer.h"
#include "SetLayer.h"
#include "SimpleAudioEngine.h"
using namespace CocosDenshion;
using namespace::std;


bool RepoLayer::init() {
	Size winSize = Director::getInstance()->getWinSize();
	auto origin = Director::getInstance()->getVisibleOrigin();

	//监听键盘事件
	auto listenerKeyboard = EventListenerKeyboard::create();
	listenerKeyboard->onKeyPressed = CC_CALLBACK_2(RepoLayer::onKeyPressed, this);
	listenerKeyboard->onKeyReleased = CC_CALLBACK_2(RepoLayer::onKeyReleased, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listenerKeyboard, this);
	this->schedule(schedule_selector(RepoLayer::equipUpdate), 0.15f);
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
	_background_3->setPosition(Vec2(origin.x + winSize.width * 0.5, origin.y + winSize.height * 0.5));
	this->addChild(_background_3, 1);
	//白色装备按钮1
	_background_3_white_1 = MenuItemImage::create("res/UI/a6Repo/rectWhite.png", "res/UI/a6Repo/rectWhiteS.png", "res/UI/a6Repo/block.png", CC_CALLBACK_1(RepoLayer::menuCallBack_1, this, user.getPlaneType()));
	_background_3_white_1->setPosition(Vec2(origin.x + winSize.width * 0.2, origin.y + winSize.height * 0.5));
	_background_3_white_1->setScale(0.6);
	//背景3
	_background_3 = Sprite::create("res/UI/a6Repo/rect3.png");
	_background_3->setPosition(Vec2(origin.x + winSize.width * 0.5, origin.y + winSize.height * 0.3));
	this->addChild(_background_3, 1);
	//白色装备按钮2
	_background_3_white_2 = MenuItemImage::create("res/UI/a6Repo/rectWhite.png", "res/UI/a6Repo/rectWhiteS.png", "res/UI/a6Repo/block.png", CC_CALLBACK_1(RepoLayer::menuCallBack_2, this, user.getPlaneType()));
	_background_3_white_2->setPosition(Vec2(origin.x + winSize.width * 0.2, origin.y + winSize.height * 0.3));
	_background_3_white_2->setScale(0.6);//缩放0.5倍
	//背景3

	_background_3 = Sprite::create("res/UI/a6Repo/rect3.png");
	_background_3->setPosition(Vec2(origin.x + winSize.width * 0.5, origin.y + winSize.height * 0.1));
	this->addChild(_background_3, 1);
	//白色装备按钮3
	_background_3_white_3 = MenuItemImage::create("res/UI/a6Repo/rectWhite.png", "res/UI/a6Repo/rectWhiteS.png", "res/UI/a6Repo/block.png", CC_CALLBACK_1(RepoLayer::menuCallBack_3, this, user.getPlaneType()));
	_background_3_white_3->setPosition(Vec2(origin.x + winSize.width * 0.2, origin.y + winSize.height * 0.1));
	_background_3_white_3->setScale(0.6);//缩放0.5倍


	//设置装备列表9个
	setEquipImg(user.getPlaneType());
	//飞机进度条
	BaseBarHp = Sprite::create("res/UI/0Loading/loadingBarEmpty.png");
	BaseBarHp->setPosition(Vec2(origin.x + winSize.width *0.73, origin.y + winSize.height *0.8));
	BaseBarHp->setScale(0.35, 0.5);
	this->addChild(BaseBarHp, 2);

	BaseBarEn = Sprite::create("res/UI/0Loading/loadingBarEmpty.png");
	BaseBarEn->setPosition(Vec2(origin.x + winSize.width *0.73, origin.y + winSize.height *0.76));
	BaseBarEn->setScale(0.35, 0.5);
	this->addChild(BaseBarEn, 2);

	BaseBarAtk = Sprite::create("res/UI/0Loading/loadingBarEmpty.png");
	BaseBarAtk->setPosition(Vec2(origin.x + winSize.width *0.73, origin.y + winSize.height *0.72));
	BaseBarAtk->setScale(0.35, 0.5);
	this->addChild(BaseBarAtk, 2);

	BaseBarSpd = Sprite::create("res/UI/0Loading/loadingBarEmpty.png");
	BaseBarSpd->setPosition(Vec2(origin.x + winSize.width *0.73, origin.y + winSize.height *0.68));
	BaseBarSpd->setScale(0.35, 0.5);
	this->addChild(BaseBarSpd, 2);

	HpBar = Sprite::create("res/UI/0Loading/loadingBarFull.png");
	HpBar->setPosition(Vec2(origin.x + winSize.width *0.6335, origin.y + winSize.height *0.798));
	HpBar->setScale(0.35*(user.getHp()) / 50, 0.5);
	HpBar->setAnchorPoint(Vec2(0, 0));
	this->addChild(HpBar, 2);

	EnBar = Sprite::create("res/UI/0Loading/loadingBarFull.png");
	EnBar->setPosition(Vec2(origin.x + winSize.width *0.6335, origin.y + winSize.height *0.758));
	EnBar->setScale(0.35*(user.getMp())/20, 0.5);
	EnBar->setAnchorPoint(Vec2(0, 0));
	this->addChild(EnBar, 2);

	AtkBar = Sprite::create("res/UI/0Loading/loadingBarFull.png");
	AtkBar->setPosition(Vec2(origin.x + winSize.width *0.6335, origin.y + winSize.height *0.718));
	AtkBar->setScale(0.35*(user.getAtk()) / 30, 0.5);
	AtkBar->setAnchorPoint(Vec2(0, 0));
	this->addChild(AtkBar, 2);

	SpdBar = Sprite::create("res/UI/0Loading/loadingBarFull.png");
	SpdBar->setPosition(Vec2(origin.x + winSize.width *0.6335, origin.y + winSize.height *0.678));
	SpdBar->setScale(0.35*(user.getSpd()) / 20, 0.5);
	SpdBar->setAnchorPoint(Vec2(0, 0));
	this->addChild(SpdBar, 2);

	//设置飞机图片

	CCLOG("%d \n", user.getPlaneType());
	setPlaneImg(user.getPlaneType());


	//返回按钮
	auto back = MenuItemImage::create("res/UI/a2SelectLevel/back.png", "res/UI/a2SelectLevel/backB.png", CC_CALLBACK_1(RepoLayer::CallMenu, this,user));
	back->setPosition(Vec2(winSize.width*0.15, winSize.height*0.93));
	back->setScale(0.55);
	back->setTag(2);

	//保存装备
	auto save = MenuItemImage::create("res/UI/a6Repo/saveEquip.png", "res/UI/a6Repo/saveEquipS.png", CC_CALLBACK_1(RepoLayer::SaveEquip, this,user));
	save->setPosition(Vec2(winSize.width*0.8, winSize.height*0.93));
	save->setScale(0.55);
	save->setTag(2);

	//menu
	auto menu = Menu::create(_background_3_white_1, _background_3_white_2, _background_3_white_3, back, save, NULL);
	menu->setPosition(Vec2(Point::ZERO));
	this->addChild(menu, 1);

	//传入战机名
	Label * planeName = Label::createWithTTF(user.getUserName(), "fonts/simhei.ttf", 25);
	planeName->setPosition(Vec2(origin.x + winSize.width * 0.57, origin.y + winSize.height * 0.84));
	this->addChild(planeName, 2);


	//传入等级值将int转换为char*
	std::stringstream Level;
	Level << "Lv."<<user.getPlaneLevel();
	Label * level = Label::createWithTTF(Level.str().c_str(), "fonts/simhei.ttf", 25);
	level->setPosition(Vec2(origin.x + winSize.width * 0.77, origin.y + winSize.height * 0.84));
	this->addChild(level, 2);

	//飞机属性栏
	Label * life = Label::createWithTTF("生命", "fonts/simhei.ttf", 18);
	life->setPosition(Vec2(origin.x + winSize.width * 0.57, origin.y + winSize.height * 0.8));
	this->addChild(life, 2);

	Label *  energy = Label::createWithTTF("能量", "fonts/simhei.ttf", 18);
	energy->setPosition(Vec2(origin.x + winSize.width * 0.57, origin.y + winSize.height * 0.76));
	this->addChild(energy, 2);

	Label *  attack = Label::createWithTTF("攻击", "fonts/simhei.ttf", 18);
	attack->setPosition(Vec2(origin.x + winSize.width * 0.57, origin.y + winSize.height * 0.72));
	this->addChild(attack, 2);

	Label *  speed = Label::createWithTTF("速度", "fonts/simhei.ttf", 18);
	speed->setPosition(Vec2(origin.x + winSize.width * 0.57, origin.y + winSize.height * 0.68));
	this->addChild(speed, 2);
	//装备栏
    //机身
	_equip_head = Equip::create();
	_equip_head->setType(1);
	std::stringstream hp;
	hp << (_equip_head->getEHp()*10);

	_equip_head_b = Equip::create();
	_equip_head_b->setType(2);
	std::stringstream hp_b;
	hp_b << (_equip_head_b->getEHp()*10);

	 _equip_head_c = Equip::create();
	 _equip_head_c->setType(3);
	std::stringstream hp_c;
	hp_c << (_equip_head_c->getEHp()*10);

	Label * equipName_1 = Label::createWithTTF("部件名称    机身", "fonts/simhei.ttf", 18);
	equipName_1->setPosition(Vec2(origin.x + winSize.width * 0.5, origin.y + winSize.height * 0.55 ));
	this->addChild(equipName_1, 1);

	Label * equipName_1_1 = Label::createWithTTF("生命 +", "fonts/simhei.ttf", 18);
	equipName_1_1->setPosition(Vec2(origin.x + winSize.width * 0.41, origin.y + winSize.height * 0.5 ));
	this->addChild(equipName_1_1, 1);
	//普通
	equipNum_1_1 = Label::createWithTTF(hp.str().c_str(), "fonts/simhei.ttf", 18);
	equipNum_1_1->setPosition(Vec2(origin.x + winSize.width * 0.5, origin.y + winSize.height * 0.5 ));
	this->addChild(equipNum_1_1, 1);
	//精英
	equipNum_1_2 = Label::createWithTTF(hp_b.str().c_str(), "fonts/simhei.ttf", 18);
	equipNum_1_2->setPosition(Vec2(origin.x + winSize.width * 1.5 , origin.y + winSize.height * 0.5));
	this->addChild(equipNum_1_2, 1);
	//传说
	equipNum_1_3 = Label::createWithTTF(hp_c.str().c_str(), "fonts/simhei.ttf", 18);
	equipNum_1_3->setPosition(Vec2(origin.x + winSize.width * 2.5, origin.y + winSize.height * 0.5));
	this->addChild(equipNum_1_3, 1);

	//机翼
	_equip_arm = Equip::create();
	_equip_arm->setType(4);
	std::stringstream atk;
	atk << (_equip_arm->getEAtk()*10);

	_equip_arm_b = Equip::create();
	_equip_arm_b->setType(5);
	std::stringstream atk_b;
	atk_b << (_equip_arm_b->getEAtk()*10);

	_equip_arm_c = Equip::create();
	_equip_arm_c->setType(6);
	std::stringstream atk_c;
	atk_c << (_equip_arm_c->getEAtk()*10);
	//d << (_equip_2->getEquipNum());

	Label * equipName_2 = Label::createWithTTF("部件名称    机翼", "fonts/simhei.ttf", 18);
	equipName_2->setPosition(Vec2(origin.x + winSize.width * 0.5, origin.y + winSize.height * 0.35 ));
	this->addChild(equipName_2, 1);

	Label * equipName_2_1 = Label::createWithTTF("攻击 +", "fonts/simhei.ttf", 18);
	equipName_2_1->setPosition(Vec2(origin.x + winSize.width * 0.41, origin.y + winSize.height * 0.3 ));
	this->addChild(equipName_2_1, 1);
	//普通
	equipNum_2_1 = Label::createWithTTF(atk.str().c_str(), "fonts/simhei.ttf", 18);
	equipNum_2_1->setPosition(Vec2(origin.x + winSize.width * 0.5, origin.y + winSize.height * 0.3));
	this->addChild(equipNum_2_1, 1);
	//精英
	equipNum_2_2 = Label::createWithTTF(atk_b.str().c_str(), "fonts/simhei.ttf", 18);
	equipNum_2_2->setPosition(Vec2(origin.x + winSize.width * 1.5, origin.y + winSize.height * 0.3));
	this->addChild(equipNum_2_2, 1);
	//传说
	equipNum_2_3 = Label::createWithTTF(atk_c.str().c_str(), "fonts/simhei.ttf", 18);
	equipNum_2_3->setPosition(Vec2(origin.x + winSize.width * 2.5, origin.y + winSize.height * 0.3));
	this->addChild(equipNum_2_3, 1);

	//机尾
	_equip_tail = Equip::create();
	_equip_tail->setType(7);
	std::stringstream spd;
	spd << (_equip_tail->getESpd()*10);

	_equip_tail_b = Equip::create();
	_equip_tail_b->setType(8);
	std::stringstream spd_b;
	spd_b << (_equip_tail_b->getESpd()*10);

	_equip_tail_c = Equip::create();
	_equip_tail_c->setType(9);
	std::stringstream spd_c;
	spd_c << (_equip_tail_c->getESpd()*10);
	//num << (_equip_3->getEquipNum());

	Label * equipName_3 = Label::createWithTTF("部件名称    机尾", "fonts/simhei.ttf", 18);
	equipName_3->setPosition(Vec2(origin.x + winSize.width * 0.5, origin.y + winSize.height * 0.15 ));
	this->addChild(equipName_3, 1);

	Label * equipName_3_1 = Label::createWithTTF("速度 +", "fonts/simhei.ttf", 18);
	equipName_3_1->setPosition(Vec2(origin.x + winSize.width * 0.41, origin.y + winSize.height * 0.1 ));
	this->addChild(equipName_3_1, 1);
    //普通
	equipNum_3_1 = Label::createWithTTF(spd.str().c_str(), "fonts/simhei.ttf", 18);
	equipNum_3_1->setPosition(Vec2(origin.x + winSize.width * 0.5, origin.y + winSize.height * 0.1));
	this->addChild(equipNum_3_1, 1);
	//精英
	equipNum_3_2 = Label::createWithTTF(spd_b.str().c_str(), "fonts/simhei.ttf", 18);
	equipNum_3_2->setPosition(Vec2(origin.x + winSize.width * 1.5, origin.y + winSize.height * 0.1));
	this->addChild(equipNum_3_2, 1);
	//传说
	equipNum_3_3 = Label::createWithTTF(spd_c.str().c_str(), "fonts/simhei.ttf", 18);
	equipNum_3_3->setPosition(Vec2(origin.x + winSize.width * 2.5, origin.y + winSize.height * 0.1));
	this->addChild(equipNum_3_3, 1);

	return true;

}

//第一栏装备按钮
void RepoLayer::menuCallBack_1(Ref * pSender,int type) {
	//音效
	if (SetLayer::getEffectState() == 1) {
		
		SimpleAudioEngine::sharedEngine()->playEffect("music/click8.wav");
	}
	Size winSize = Director::getInstance()->getWinSize();
	auto origin = Director::getInstance()->getVisibleOrigin();
	stringstream filename1;
	stringstream filename2;
	stringstream filename3;
	filename1 << "res/UI/plane_parts/playerShip" << type << "_blue_02.png";
	filename2 << "res/UI/plane_parts/playerShip" << type << "_orange_02.png";
	filename3 << "res/UI/plane_parts/playerShip" << type << "_red_02.png";
	//判断用户选择的是那个装备，当前装备位置为120
	if (_equip_1->getPositionX()==120 && user.get_equip_head_have()==1) {
		//一个部位的装备只允许穿一件，因此卸下其余装备
		if (user.get_equip_head_b_load() == 1) {
			_body_1_b->removeFromParent();
			user.set_equip_head_b_load(0);
		}
		if (user.get_equip_head_c_load() == 1) {
			_body_1_c->removeFromParent();
			user.set_equip_head_c_load(0);
		}
		//添加该位置装备
		_body_1 = MenuItemImage::create(filename1.str().c_str(), filename1.str().c_str(), CC_CALLBACK_1(RepoLayer::UnBody_1, this, user)); 
		_body_1->setPosition(Vec2(winSize.width*0.3, origin.y + winSize.height * 0.757));
		//this->addChild(_body_1, 2);
		auto menu = Menu::create(_body_1, NULL);
		menu->setPosition(Vec2(Point::ZERO));
		this->addChild(menu, 3);
		HpBar->setScale(0.35*(user.getHp()+10) / 500, 0.5);
		user. set_equip_head_load(1); 
		user.set_equip_head_have(0);
		user.setHp(user.getHp() + 1);
		
		
	}
	
	else if (_equip_1_b->getPositionX()==120 && user.get_equip_head_b_have() == 1) {
		if (user.get_equip_head_load() == 1) {
			_body_1->removeFromParent();
			user.set_equip_head_load(0);
		}
		if (user.get_equip_head_c_load() == 1) {
			_body_1_c->removeFromParent();
			user.set_equip_head_c_load(0);
		}
		_body_1_b = MenuItemImage::create(filename2.str().c_str(), filename2.str().c_str(), CC_CALLBACK_1(RepoLayer::UnBody_1_b, this, user));
		_body_1_b->setPosition(Vec2(winSize.width*0.3, winSize.height * 0.757));
		//this->addChild(_body_1_b, 2);
		auto menu = Menu::create(_body_1_b, NULL);
		menu->setPosition(Vec2(Point::ZERO));
		this->addChild(menu, 3);
		HpBar->setScale(0.35*(user.getHp() + 50) / 500, 0.5);
		user.set_equip_head_b_load(1);
		user.set_equip_head_b_have(0);
		user.setHp(user.getHp() + 3);
		
	}
	else if (_equip_1_c->getPositionX()==120 && user.get_equip_head_c_have() == 1) {
		if (user.get_equip_head_load() == 1) {
			_body_1->removeFromParent();
			user.set_equip_head_load(0);
		}
		if (user.get_equip_head_b_load() == 1) {
			_body_1_b->removeFromParent();
			user.set_equip_head_b_load(0);
		}
		_body_1_c = MenuItemImage::create(filename3.str().c_str(), filename3.str().c_str(), CC_CALLBACK_1(RepoLayer::UnBody_1_c, this, user));
		_body_1_c->setPosition(Vec2(winSize.width*0.3, origin.y + winSize.height * 0.757));
		//this->addChild(_body_1_c, 2);
		auto menu = Menu::create(_body_1_c, NULL);
		menu->setPosition(Vec2(Point::ZERO));
		this->addChild(menu, 3);
		HpBar->setScale(0.35*(user.getHp() + 100) / 500, 0.5);
		user.set_equip_head_c_load(1);
		user.set_equip_head_c_have(0);
		user.setHp(user.getHp() + 5);
	}


}

//第二栏装备按钮
void RepoLayer::menuCallBack_2(Ref * pSender,int type) {
	Size winSize = Director::getInstance()->getWinSize();
	auto origin = Director::getInstance()->getVisibleOrigin();
	//音效
	if (SetLayer::getEffectState() == 1) {
		SimpleAudioEngine::sharedEngine()->playEffect("music/click8.wav");
	}
	stringstream filename1;
	stringstream filename2;
	stringstream filename3;
	stringstream filename4;
	stringstream filename5;
	stringstream filename6;
	filename1 << "res/UI/plane_parts/playerShip" << type << "_blue_01.png";//atk
	filename2 << "res/UI/plane_parts/playerShip" << type << "_orange_01.png";
	filename3 << "res/UI/plane_parts/playerShip" << type << "_red_01.png";
	filename4 << "res/UI/plane_parts/playerShip" << type << "_blue_03.png";
	filename5 << "res/UI/plane_parts/playerShip" << type << "_orange_03.png";
	filename6 << "res/UI/plane_parts/playerShip" << type << "_red_03.png";

	if (_equip_1->getPositionX() == 120&&user.get_equip_arm_have() == 1) {
		if (user.get_equip_arm_b_load() == 1) {
			_wing_1_b->removeFromParent();
			_wing_2_b->removeFromParent();
			user.set_equip_arm_b_load(0);

		}
		if (user.get_equip_arm_c_load() == 1) {
			_wing_1_c->removeFromParent();
			_wing_2_c->removeFromParent();
			user.set_equip_arm_c_load(0);
		}
		_wing_1 = MenuItemImage::create(filename1.str().c_str(), filename1.str().c_str(), CC_CALLBACK_1(RepoLayer::UnWing_1, this, user));
		_wing_1->setPosition(Vec2(origin.x + winSize.width*0.26, origin.y + winSize.height * 0.75));
		//this->addChild(_wing_1, 2);
		_wing_2 = MenuItemImage::create(filename4.str().c_str(), filename4.str().c_str(), CC_CALLBACK_1(RepoLayer::UnWing_1, this, user));
		_wing_2->setPosition(Vec2(origin.x + winSize.width*0.34, origin.y + winSize.height * 0.75));
		//this->addChild(_wing_2, 2);
		AtkBar->setScale(0.35*(user.getAtk()+10) / 300, 0.5);
		auto menu = Menu::create(_wing_1, _wing_2, NULL);
		menu->setPosition(Vec2(Point::ZERO));
		this->addChild(menu, 3);
		user.set_equip_arm_load(1);
		user.set_equip_arm_have(0);
		user.setAtk(user.getAtk() + 1);
		
		
	}
	else if (_equip_1_b->getPositionX() == 120 && user.get_equip_arm_b_have() == 1) {
		if (user.get_equip_arm_load() == 1) {
			_wing_1->removeFromParent();
			_wing_2->removeFromParent();
			user.set_equip_arm_load(0);
		}
		if (user.get_equip_arm_c_load() == 1) {
			_wing_1_c->removeFromParent();
			_wing_2_c->removeFromParent();
			user.set_equip_arm_c_load(0);
		}
		_wing_1_b = MenuItemImage::create(filename2.str().c_str(), filename2.str().c_str(), CC_CALLBACK_1(RepoLayer::UnWing_1_b, this, user));
		_wing_1_b->setPosition(Vec2(origin.x + winSize.width*0.26, origin.y + winSize.height * 0.75));
		//this->addChild(_wing_1_b, 2);
		_wing_2_b = MenuItemImage::create(filename5.str().c_str(), filename5.str().c_str(), CC_CALLBACK_1(RepoLayer::UnWing_1_b, this, user));
		_wing_2_b->setPosition(Vec2(origin.x + winSize.width*0.34, origin.y + winSize.height * 0.75));
		//this->addChild(_wing_2_b, 2);
		auto menu = Menu::create(_wing_1_b, _wing_2_b, NULL);
		menu->setPosition(Vec2(Point::ZERO));
		this->addChild(menu, 3);
		AtkBar->setScale(0.35*(user.getAtk() + 50) / 300, 0.5);
		user.set_equip_arm_b_load(1);
		user.set_equip_arm_b_have(0);
		user.setAtk(user.getAtk() + 3);
		
	}
	else if (_equip_1_c->getPositionX() == 120 && user.get_equip_arm_c_have() == 1) {
		if (user.get_equip_arm_load() == 1) {
			_wing_1->removeFromParent();
			_wing_2->removeFromParent();
			user.set_equip_arm_load(0);
		}
		if (user.get_equip_arm_b_load() == 1) {
			_wing_1_b->removeFromParent();
			_wing_2_b->removeFromParent();
			user.set_equip_arm_b_load(0);
		}
		_wing_1_c = MenuItemImage::create(filename3.str().c_str(), filename3.str().c_str(), CC_CALLBACK_1(RepoLayer::UnWing_1_c, this, user));
		_wing_1_c->setPosition(Vec2(origin.x + winSize.width*0.26, origin.y + winSize.height * 0.75));
		//this->addChild(_wing_1_c, 2);
		_wing_2_c = MenuItemImage::create(filename6.str().c_str(), filename6.str().c_str(), CC_CALLBACK_1(RepoLayer::UnWing_1_c, this, user));
		_wing_2_c->setPosition(Vec2(origin.x + winSize.width*0.34, origin.y + winSize.height * 0.75));
		//this->addChild(_wing_2_c, 2);
		auto menu = Menu::create(_wing_1_c, _wing_2_c, NULL);
		menu->setPosition(Vec2(Point::ZERO));
		this->addChild(menu, 3);
		AtkBar->setScale(0.35*(user.getAtk() + 100) / 300, 0.5);
		user.set_equip_arm_c_load(1);		
		user.set_equip_arm_c_have(0);
		user.setAtk(user.getAtk() + 5);
	}

}

//第三栏装备按钮
void RepoLayer::menuCallBack_3(Ref * pSender,int type) {
	Size winSize = Director::getInstance()->getWinSize();
	auto origin = Director::getInstance()->getVisibleOrigin();

	if (SetLayer::getEffectState() == 1) {
		SimpleAudioEngine::sharedEngine()->playEffect("music/click8.wav");
	}
	stringstream filename1;
	stringstream filename2;
	stringstream filename3;
	filename1 << "res/UI/plane_parts/playerShip" << type << "_blue_04.png";//spd
	filename2 << "res/UI/plane_parts/playerShip" << type << "_orange_04.png";
	filename3 << "res/UI/plane_parts/playerShip" << type << "_red_04.png";

	if (_equip_1->getPositionX() == 120 && user.get_equip_tail_have() == 1) {
		if (user.get_equip_tail_b_load() == 1) {
			_tail_1_b->removeFromParent();
			user.set_equip_tail_b_load(0);
		}
		if (user.get_equip_tail_c_load() == 1) {
			_tail_1_c->removeFromParent();
			user.set_equip_tail_c_load(0);
		}
		_tail_1 = MenuItemImage::create(filename1.str().c_str(), filename1.str().c_str(), CC_CALLBACK_1(RepoLayer::UnTail_1, this, user));
		_tail_1->setPosition(Vec2(origin.x + winSize.width*0.3, origin.y + winSize.height * 0.717));
		//this->addChild(_tail_1, 2);
		auto menu = Menu::create(_tail_1, NULL);
		menu->setPosition(Vec2(Point::ZERO));
		this->addChild(menu, 3);
		SpdBar->setScale(0.35*(user.getSpd() + 10) / 200, 0.5);
		user.set_equip_tail_load(1);
		user.set_equip_tail_have(0);
		user.setSpd(user.getSpd() + 1);

	}
	else if (_equip_1_b->getPositionX() == 120 && user.get_equip_tail_b_have() == 1) {
		if (user.get_equip_tail_load() == 1) {
			_tail_1->removeFromParent();
			user.set_equip_tail_load(0);
		}
		if (user.get_equip_tail_c_load() == 1) {
			_tail_1_c->removeFromParent();
			user.set_equip_tail_c_load(0);
		}
		_tail_1_b = MenuItemImage::create(filename2.str().c_str(), filename2.str().c_str(), CC_CALLBACK_1(RepoLayer::UnTail_1_b, this, user));
		_tail_1_b->setPosition(Vec2(origin.x + winSize.width*0.3, origin.y + winSize.height * 0.717));
		//this->addChild(_tail_1_b, 2);
		auto menu = Menu::create(_tail_1_b, NULL);
		menu->setPosition(Vec2(Point::ZERO));
		this->addChild(menu, 3);
		SpdBar->setScale(0.35*(user.getSpd() + 50) / 200, 0.5);
		user.set_equip_tail_b_load(1);
		user.set_equip_tail_b_have(0);
		user.setSpd(user.getSpd() + 2);
	}
	else if (_equip_1_c->getPositionX() == 120 && user.get_equip_tail_c_have() == 1) {
		if (user.get_equip_tail_load() == 1) {
			_tail_1->removeFromParent();
			user.set_equip_tail_load(0);
		}
		if (user.get_equip_tail_b_load() == 1) {
			_tail_1_b->removeFromParent();
			user.set_equip_tail_b_load(0);
		}
		_tail_1_c = MenuItemImage::create(filename3.str().c_str(), filename3.str().c_str(), CC_CALLBACK_1(RepoLayer::UnTail_1_c, this, user));
		_tail_1_c->setPosition(Vec2(origin.x + winSize.width*0.3, origin.y + winSize.height * 0.717));
		//this->addChild(_tail_1_c, 2);
		auto menu = Menu::create(_tail_1_c, NULL);
		menu->setPosition(Vec2(Point::ZERO));
		this->addChild(menu, 3);
		SpdBar->setScale(0.35*(user.getSpd() + 100) / 200, 0.5);
		user.set_equip_tail_c_load(1);
		user.set_equip_tail_c_have(0);
		user.setSpd(user.getSpd() + 3);
		
	}
}

//卸机身装备
void RepoLayer::UnBody_1(Ref * pSender, UserInfo & userInfo)
{
	_body_1->removeFromParent();
	//恢复原始属性值
	HpBar->setScale(0.35*(user.getHp())/ 500, 0.5);
	//恢复装备load状态
	user.set_equip_head_load(0);
	user.set_equip_head_have(1);
}

void RepoLayer::UnBody_1_b(Ref * pSender, UserInfo & userInfo)
{
	_body_1_b->removeFromParent();
	HpBar->setScale(0.35*(user.getHp()) / 500, 0.5);
	user.set_equip_head_b_load(0);
	user.set_equip_head_b_have(1);
}
void RepoLayer::UnBody_1_c(Ref * pSender, UserInfo & userInfo)
{
	_body_1_c->removeFromParent();
	HpBar->setScale(0.35*(user.getHp()) / 500, 0.5);
	user.set_equip_head_c_load(0);
	user.set_equip_head_c_have(1);
}
//卸载机翼装备
void RepoLayer::UnWing_1(Ref * pSender, UserInfo & userInfo)
{
	_wing_1->removeFromParent();
	_wing_2->removeFromParent();
	AtkBar->setScale(0.35*(user.getAtk()) / 300, 0.5);
	user.set_equip_arm_load(0);
	user.set_equip_arm_have(1);
}
void RepoLayer::UnWing_1_b(Ref * pSender, UserInfo & userInfo)
{
	_wing_1_b->removeFromParent();
	_wing_2_b->removeFromParent();
	AtkBar->setScale(0.35*(user.getAtk()) / 300, 0.5);
	user.set_equip_arm_b_load(0);
	user.set_equip_arm_b_have(1);
}
void RepoLayer::UnWing_1_c(Ref * pSender, UserInfo & userInfo)
{
	_wing_1_c->removeFromParent();
	_wing_2_c->removeFromParent();
	AtkBar->setScale(0.35*(user.getAtk()) / 300, 0.5);
	user.set_equip_arm_c_load(0);
	user.set_equip_arm_c_have(1);
}
//卸载机尾装备
void RepoLayer::UnTail_1(Ref * pSender, UserInfo & userInfo)
{
	_tail_1->removeFromParent();
	SpdBar->setScale(0.35*(user.getSpd()) / 300, 0.5);
	user.set_equip_tail_load(0);
	user.set_equip_tail_have(1);
}
void RepoLayer::UnTail_1_b(Ref * pSender, UserInfo & userInfo)
{
	_tail_1_b->removeFromParent();
	SpdBar->setScale(0.35*(user.getSpd()) / 300, 0.5);
	user.set_equip_tail_b_load(0);
	user.set_equip_tail_b_have(1);
}
void RepoLayer::UnTail_1_c(Ref * pSender, UserInfo & userInfo)
{
	_tail_1_c->removeFromParent();
	SpdBar->setScale(0.35*(user.getSpd()) / 300, 0.5);
	user.set_equip_tail_c_load(0);
	user.set_equip_tail_c_have(1);
}


//返回关卡选择
void RepoLayer::CallMenu(Ref * pSender,UserInfo & userInfo)
{
	if (SetLayer::getEffectState() == 1) {
		SimpleAudioEngine::getInstance()->playEffect("music/trans1.wav");
		SimpleAudioEngine::sharedEngine()->playEffect("music/click8.wav");
	}
	SceneManager::goMapLayer(2,user);
}
//保存装备
void RepoLayer::SaveEquip(Ref * pSender, UserInfo & userInfo)
{
	if (SetLayer::getEffectState() == 1) {
		SimpleAudioEngine::getInstance()->playEffect("music/trans1.wav");
		SimpleAudioEngine::sharedEngine()->playEffect("music/click8.wav");
	}
	SceneManager::goSaveLayer(2, user);
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
	//机身
	filename1 << "playerShip" << type << "_blue_02.png";
	filename2 << "playerShip" << type << "_orange_02.png";
	filename3 << "playerShip" << type << "_red_02.png";
	//机翼
	filename4 << "playerShip" << type << "_blue_01.png";
	filename5 << "playerShip" << type << "_orange_01.png";
	filename6 << "playerShip" << type << "_red_01.png";
	//机尾
	filename7 << "playerShip" << type << "_blue_04.png";
	filename8 << "playerShip" << type << "_orange_04.png";
	filename9 << "playerShip" << type << "_red_04.png";

	//机身
	_equip_1 = Sprite::createWithSpriteFrameName(filename1.str().c_str());
	_equip_1->setPosition(Vec2(winSize.width *0.2, winSize.height *0.5));
	this->addChild(_equip_1, 2);

	_equip_1_b = Sprite::createWithSpriteFrameName(filename2.str().c_str());
	_equip_1_b->setPosition(Vec2(winSize.width *1.2, winSize.height *0.5));
	this->addChild(_equip_1_b, 2);
	//CCLOG("%f \n", Vec2(_equip_1_b->getPosition()).x);

	_equip_1_c = Sprite::createWithSpriteFrameName(filename3.str().c_str());
	_equip_1_c->setPosition(Vec2(winSize.width *2.2, origin.y + winSize.height *0.5));
	this->addChild(_equip_1_c, 2);

	//机翼
	_equip_2 = Sprite::createWithSpriteFrameName(filename4.str().c_str());
	_equip_2->setPosition(Vec2(winSize.width *0.2, winSize.height *0.3));
	this->addChild(_equip_2, 2);

	_equip_2_b = Sprite::createWithSpriteFrameName(filename5.str().c_str());
	_equip_2_b->setPosition(Vec2(winSize.width *1.2, winSize.height *0.3));
	this->addChild(_equip_2_b, 2);

	_equip_2_c = Sprite::createWithSpriteFrameName(filename6.str().c_str());
	_equip_2_c->setPosition(Vec2(winSize.width *2.2, winSize.height *0.3));
	this->addChild(_equip_2_c, 2);

	//机尾
	_equip_3 = Sprite::createWithSpriteFrameName(filename7.str().c_str());
	_equip_3->setPosition(Vec2(winSize.width *0.2, winSize.height *0.1));
	this->addChild(_equip_3, 2);

	_equip_3_b = Sprite::createWithSpriteFrameName(filename8.str().c_str());
	_equip_3_b->setPosition(Vec2(winSize.width *1.2, winSize.height *0.1));
	this->addChild(_equip_3_b, 2);

	_equip_3_c = Sprite::createWithSpriteFrameName(filename9.str().c_str());
	_equip_3_c->setPosition(Vec2(winSize.width *2.2, winSize.height *0.1));
	this->addChild(_equip_3_c, 2);

	//判断初始装备黑白框
	if (user.get_equip_head_have() == 0) {
		_background_3_white_1->setEnabled(false);
		//reorderChild(_background_3_white_1,4);
		_background_3_white_1->setOpacity(255 * 0.75);
	}
	if (user.get_equip_arm_have() == 0) {
		_background_3_white_2->setEnabled(false);
		//reorderChild(_background_3_white_2, 4);
		_background_3_white_2->setOpacity(255 * 0.75);
	}
	if (user.get_equip_tail_have() == 0) {
		_background_3_white_3->setEnabled(false);
		//reorderChild(_background_3_white_3, 4);
		_background_3_white_3->setOpacity(255 * 0.75);
	}

}

//设置飞机栏图片包括已经穿上的装备
void RepoLayer::setPlaneImg(int type) {
	Size winSize = Director::getInstance()->getWinSize();
	auto origin = Director::getInstance()->getVisibleOrigin();
	stringstream filename;
	//显示对应飞机图片
	filename << "playerShip" << type << "_green.png";
	_plane = Sprite::createWithSpriteFrameName(filename.str().c_str());
	_plane->setPosition(Vec2(origin.x + winSize.width*0.3, origin.y + winSize.height * 3 / 4));
	this->addChild(_plane, 2);
	CCLOG("%f /n", user.get_equip_head_load());
	//判断是否有被穿上的部件
	//头部
	if (user.get_equip_head_load() == 1) {
		stringstream filename1;
		filename1 << "res/UI/plane_parts/playerShip" << type << "_blue_02.png";
		_body_1 = MenuItemImage::create(filename1.str().c_str(), filename1.str().c_str(), CC_CALLBACK_1(RepoLayer::UnBody_1, this, user));
		_body_1->setPosition(Vec2(winSize.width*0.3, origin.y + winSize.height * 0.757));
		//this->addChild(_body_1, 2);
		auto menu = Menu::create(_body_1, NULL);
		menu->setPosition(Vec2(Point::ZERO));
		this->addChild(menu, 3);
		CCLOG("%f /n", user.getHp());
		HpBar->setScale(0.35*(user.getHp() + 10) / 500, 0.5);
	}
	else if (user.get_equip_head_b_load() == 1) {
		stringstream filename2;
		filename2 << "res/UI/plane_parts/playerShip" << type << "_orange_02.png";
		_body_1_b = MenuItemImage::create(filename2.str().c_str(), filename2.str().c_str(), CC_CALLBACK_1(RepoLayer::UnBody_1_b, this, user));
		_body_1_b->setPosition(Vec2(winSize.width*0.3, winSize.height * 0.757));
		//this->addChild(_body_1_b, 2);
		auto menu = Menu::create(_body_1_b, NULL);
		menu->setPosition(Vec2(Point::ZERO));
		this->addChild(menu, 3);
		CCLOG("%f /n", user.getHp());
		HpBar->setScale(0.35*(user.getHp() + 50) / 500, 0.5);
	}
	else if (user.get_equip_head_c_load() == 1) {
		stringstream filename3;
		filename3 << "res/UI/plane_parts/playerShip" << type << "_red_02.png";
		_body_1_c = MenuItemImage::create(filename3.str().c_str(), filename3.str().c_str(), CC_CALLBACK_1(RepoLayer::UnBody_1_c, this, user));
		_body_1_c->setPosition(Vec2(winSize.width*0.3, origin.y + winSize.height * 0.757));
		//this->addChild(_body_1_c, 2);
		auto menu = Menu::create(_body_1_c, NULL);
		menu->setPosition(Vec2(Point::ZERO));
		this->addChild(menu, 3);
		HpBar->setScale(0.35*(user.getHp() + 100) / 500, 0.5);
	}
	//机翼
	if (user.get_equip_arm_load() == 1) {
		stringstream filename4;
		stringstream filename7;
		filename4 << "res/UI/plane_parts/playerShip" << type << "_blue_01.png";
		filename7 << "res/UI/plane_parts/playerShip" << type << "_blue_03.png";
		_wing_1 = MenuItemImage::create(filename4.str().c_str(), filename4.str().c_str(), CC_CALLBACK_1(RepoLayer::UnWing_1, this, user));
		_wing_1->setPosition(Vec2(origin.x + winSize.width*0.26, origin.y + winSize.height * 0.75));
		//this->addChild(_wing_1, 2);
		_wing_2 = MenuItemImage::create(filename7.str().c_str(), filename7.str().c_str(), CC_CALLBACK_1(RepoLayer::UnWing_1, this, user));
		_wing_2->setPosition(Vec2(origin.x + winSize.width*0.34, origin.y + winSize.height * 0.75));
		//this->addChild(_wing_2, 2);
		auto menu = Menu::create(_wing_1, _wing_2, NULL);
		menu->setPosition(Vec2(Point::ZERO));
		this->addChild(menu, 3);
		AtkBar->setScale(0.35*(user.getAtk()+10) / 300, 0.5);
	}
	else if (user.get_equip_arm_b_load() == 1) {
		stringstream filename5;
		stringstream filename8;
		filename5 << "res/UI/plane_parts/playerShip" << type << "_orange_01.png";
		filename8 << "res/UI/plane_parts/playerShip" << type << "_orange_03.png";
		_wing_1_b = MenuItemImage::create(filename5.str().c_str(), filename5.str().c_str(), CC_CALLBACK_1(RepoLayer::UnWing_1_b, this, user));
		_wing_1_b->setPosition(Vec2(origin.x + winSize.width*0.26, origin.y + winSize.height * 0.75));
		//this->addChild(_wing_1_b, 2);
		_wing_2_b = MenuItemImage::create(filename8.str().c_str(), filename8.str().c_str(), CC_CALLBACK_1(RepoLayer::UnWing_1_b, this, user));
		_wing_2_b->setPosition(Vec2(origin.x + winSize.width*0.34, origin.y + winSize.height * 0.75));
		//this->addChild(_wing_2_b, 2);
		auto menu = Menu::create(_wing_1_b, _wing_2_b, NULL);
		menu->setPosition(Vec2(Point::ZERO));
		this->addChild(menu, 3);
		AtkBar->setScale(0.35*(user.getAtk()+50) / 300, 0.5);
	}
	else if (user.get_equip_arm_c_load() == 1) {
		stringstream filename6;
		stringstream filename9;
		filename6 << "res/UI/plane_parts/playerShip" << type << "_red_01.png";
		filename9 << "res/UI/plane_parts/playerShip" << type << "_red_03.png";
		_wing_1_c = MenuItemImage::create(filename6.str().c_str(), filename6.str().c_str(), CC_CALLBACK_1(RepoLayer::UnWing_1_c, this, user));
		_wing_1_c->setPosition(Vec2(origin.x + winSize.width*0.26, origin.y + winSize.height * 0.75));
		//this->addChild(_wing_1_c, 2);
		_wing_2_c = MenuItemImage::create(filename9.str().c_str(), filename9.str().c_str(), CC_CALLBACK_1(RepoLayer::UnWing_1_c, this, user));
		_wing_2_c->setPosition(Vec2(origin.x + winSize.width*0.34, origin.y + winSize.height * 0.75));
		//this->addChild(_wing_2_c, 2);
		auto menu = Menu::create(_wing_1_c, _wing_2_c, NULL);
		menu->setPosition(Vec2(Point::ZERO));
		this->addChild(menu, 3);
		AtkBar->setScale(0.35*(user.getAtk()+100) / 300, 0.5);
	}
	//机尾
	if (user.get_equip_tail_load() == 1) {
		stringstream filename1;
		filename1 << "res/UI/plane_parts/playerShip" << type << "_blue_04.png";
		_tail_1 = MenuItemImage::create(filename1.str().c_str(), filename1.str().c_str(), CC_CALLBACK_1(RepoLayer::UnTail_1, this, user));
		_tail_1->setPosition(Vec2(origin.x + winSize.width*0.3, origin.y + winSize.height * 0.717));
		//this->addChild(_tail_1, 2);
		auto menu = Menu::create(_tail_1, NULL);
		menu->setPosition(Vec2(Point::ZERO));
		this->addChild(menu, 3);
		SpdBar->setScale(0.35*(user.getSpd()+10) / 200, 0.5);
	}
	else if (user.get_equip_tail_b_load() == 1) {
		stringstream filename2;
		filename2 << "res/UI/plane_parts/playerShip" << type << "_orange_04.png";
		_tail_1_b = MenuItemImage::create(filename2.str().c_str(), filename2.str().c_str(), CC_CALLBACK_1(RepoLayer::UnTail_1_b, this, user));
		_tail_1_b->setPosition(Vec2(origin.x + winSize.width*0.3, origin.y + winSize.height * 0.717));
		//this->addChild(_tail_1_b, 2);
		auto menu = Menu::create(_tail_1_b,  NULL);
		menu->setPosition(Vec2(Point::ZERO));
		this->addChild(menu, 3);
		SpdBar->setScale(0.35*(user.getSpd()+50) / 200, 0.5);
	}
	else if (user.get_equip_tail_c_load() == 1) {
		stringstream filename3;
		filename3 << "res/UI/plane_parts/playerShip" << type << "_red_04.png";
		_tail_1_c = MenuItemImage::create(filename3.str().c_str(), filename3.str().c_str(), CC_CALLBACK_1(RepoLayer::UnTail_1_c, this, user));
		_tail_1_c->setPosition(Vec2(origin.x + winSize.width*0.3, origin.y + winSize.height * 0.717));
		//this->addChild(_tail_1_c, 2);
		auto menu = Menu::create(_tail_1_c, NULL);
		menu->setPosition(Vec2(Point::ZERO));
		this->addChild(menu, 3);
		SpdBar->setScale(0.35*(user.getSpd()+100) / 200, 0.5);
	}
}


//监听键盘按下
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

//装备栏翻页刷新
void RepoLayer::equipUpdate(float dt)
{
	Size winSize = Director::getInstance()->getWinSize();
	auto origin = Director::getInstance()->getVisibleOrigin();
	//CCLOG("%s \n", "A string");
	switch (key) {
	case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
		if (_equip_1->getPositionX() > -1080) {
			//机身
			_equip_1->setPositionX(_equip_1->getPositionX() - winSize.width);
			_equip_1_b->setPositionX(_equip_1_b->getPositionX() - winSize.width);
			_equip_1_c->setPositionX(_equip_1_c->getPositionX() - winSize.width);
			//判断第一行黑白框
			if (_equip_1->getPositionX() == 120 && user.get_equip_head_have() == 0) {
				_background_3_white_1->setEnabled(false);
			}
			else if (_equip_1_b->getPositionX() == 120 && user.get_equip_head_b_have() == 0) {
				_background_3_white_1->setEnabled(false);
			}
			else if (_equip_1_c->getPositionX() == 120 && user.get_equip_head_c_have() == 0) {
				_background_3_white_1->setEnabled(false);
			}
			else {
				_background_3_white_1->setEnabled(true);
			}
			//装备血量栏
			equipNum_1_1->setPositionX(equipNum_1_1->getPositionX() - winSize.width);
			equipNum_1_2->setPositionX(equipNum_1_2->getPositionX() - winSize.width);
			equipNum_1_3->setPositionX(equipNum_1_3->getPositionX() - winSize.width);

			//机翼
			_equip_2->setPositionX(_equip_2->getPositionX() - winSize.width);
			_equip_2_b->setPositionX(_equip_2_b->getPositionX() - winSize.width);
			_equip_2_c->setPositionX(_equip_2_c->getPositionX() - winSize.width);
				//判断第二行黑白框
				if (_equip_2->getPositionX() == 120 && user.get_equip_arm_have() == 0) {
					_background_3_white_2->setEnabled(false);
				}
				else if (_equip_2_b->getPositionX() == 120 && user.get_equip_arm_b_have() == 0) {
					_background_3_white_2->setEnabled(false);
				}
				else if (_equip_2_c->getPositionX() == 120 && user.get_equip_arm_c_have() == 0) {
					_background_3_white_2->setEnabled(false);
				}
				else {
					_background_3_white_2->setEnabled(true);
				}
				//装备攻击栏
			equipNum_2_1->setPositionX(equipNum_2_1->getPositionX() - winSize.width);
			equipNum_2_2->setPositionX(equipNum_2_2->getPositionX() - winSize.width);
			equipNum_2_3->setPositionX(equipNum_2_3->getPositionX() - winSize.width);


			//机尾
			_equip_3->setPositionX(_equip_3->getPositionX() - winSize.width);
			_equip_3_b->setPositionX(_equip_3_b->getPositionX() - winSize.width);
			_equip_3_c->setPositionX(_equip_3_c->getPositionX() - winSize.width);
			//判断第三行黑白框
			if (_equip_3->getPositionX() == 120 && user.get_equip_tail_have() == 0) {
				_background_3_white_3->setEnabled(false);
			}
			else if (_equip_3_b->getPositionX() == 120 && user.get_equip_tail_b_have() == 0) {
				_background_3_white_3->setEnabled(false);
			}
			else if (_equip_3_c->getPositionX() == 120 && user.get_equip_tail_c_have() == 0) {
				_background_3_white_3->setEnabled(false);
			}
			else {
				_background_3_white_3->setEnabled(true);
			}
			//装备速度栏
			equipNum_3_1->setPositionX(equipNum_3_1->getPositionX() - winSize.width);
			equipNum_3_2->setPositionX(equipNum_3_2->getPositionX() - winSize.width);
			equipNum_3_3->setPositionX(equipNum_3_3->getPositionX() - winSize.width);

			CCLOG("%f \n", Vec2(_equip_1_b->getPosition()).x);
			CCLOG("%f \n", _equip_1_b->getPositionX());
		}
		else {
			//机身
			_equip_1->setPosition(Vec2(winSize.width *0.2, winSize.height *0.5));
			_equip_1_b->setPosition(Vec2(winSize.width *1.2, winSize.height *0.5));
			_equip_1_c->setPosition(Vec2(winSize.width *2.2, winSize.height *0.5));

			//判断第一行黑白框
			if (_equip_1->getPositionX() == 120 && user.get_equip_head_have() == 0) {
				_background_3_white_1->setEnabled(false);
			}
			else if (_equip_1_b->getPositionX() == 120 && user.get_equip_head_b_have() == 0) {
				_background_3_white_1->setEnabled(false);
			}
			else if (_equip_1_c->getPositionX() == 120 && user.get_equip_head_c_have() == 0) {
				_background_3_white_1->setEnabled(false);
			}
			else {
				_background_3_white_1->setEnabled(true);
			}

			//机翼
			_equip_2->setPosition(Vec2(winSize.width *0.2, winSize.height *0.3));
			_equip_2_b->setPosition(Vec2(winSize.width *1.2, winSize.height *0.3));
			_equip_2_c->setPosition(Vec2(winSize.width *2.2, winSize.height *0.3));

			//判断第二行黑白框
			if (_equip_2->getPositionX() == 120 && user.get_equip_arm_have() == 0) {
				_background_3_white_2->setEnabled(false);
			}
			else if (_equip_2_b->getPositionX() == 120 && user.get_equip_arm_b_have() == 0) {
				_background_3_white_2->setEnabled(false);
			}
			else if (_equip_2_c->getPositionX() == 120 && user.get_equip_arm_c_have() == 0) {
				_background_3_white_2->setEnabled(false);
			}
			else {
				_background_3_white_2->setEnabled(true);
			}

			_equip_3->setPosition(Vec2(winSize.width *0.2, winSize.height *0.1));
			_equip_3_b->setPosition(Vec2(winSize.width *1.2, winSize.height *0.1));
			_equip_3_c->setPosition(Vec2(winSize.width *2.2, winSize.height *0.1));

			//判断第三行黑白框
			if (_equip_3->getPositionX() == 120 && user.get_equip_tail_have() == 0) {
				_background_3_white_3->setEnabled(false);
			}
			else if (_equip_3_b->getPositionX() == 120 && user.get_equip_tail_b_have() == 0) {
				_background_3_white_3->setEnabled(false);
			}
			else if (_equip_3_c->getPositionX() == 120 && user.get_equip_tail_c_have() == 0) {
				_background_3_white_3->setEnabled(false);
			}
			else {
				_background_3_white_3->setEnabled(true);
			}

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
		
	case EventKeyboard::KeyCode::KEY_UP_ARROW:
		if (_equip_1->getPositionX() < 120) {
			//机身
			_equip_1->setPositionX(_equip_1->getPositionX() + winSize.width);
			_equip_1_b->setPositionX(_equip_1_b->getPositionX() + winSize.width);
			_equip_1_c->setPositionX(_equip_1_c->getPositionX() + winSize.width);
			//判断第一行黑白框
			if (_equip_1->getPositionX() == 120 && user.get_equip_head_have() == 0) {
				_background_3_white_1->setEnabled(false);
			}
			else if (_equip_1_b->getPositionX() == 120 && user.get_equip_head_b_have() == 0) {
				_background_3_white_1->setEnabled(false);
			}
			else if (_equip_1_c->getPositionX() == 120 && user.get_equip_head_c_have() == 0) {
				_background_3_white_1->setEnabled(false);
			}
			else {
				_background_3_white_1->setEnabled(true);
			}
			//装备血量栏
			equipNum_1_1->setPositionX(equipNum_1_1->getPositionX() + winSize.width);
			equipNum_1_2->setPositionX(equipNum_1_2->getPositionX() + winSize.width);
			equipNum_1_3->setPositionX(equipNum_1_3->getPositionX() + winSize.width);

			//机翼
			_equip_2->setPositionX(_equip_2->getPositionX() + winSize.width);
			_equip_2_b->setPositionX(_equip_2_b->getPositionX() + winSize.width);
			_equip_2_c->setPositionX(_equip_2_c->getPositionX() + winSize.width);
			//判断第二行黑白框
			if (_equip_2->getPositionX() == 120 && user.get_equip_arm_have() == 0) {
				_background_3_white_2->setEnabled(false);
			}
			else if (_equip_2_b->getPositionX() == 120 && user.get_equip_arm_b_have() == 0) {
				_background_3_white_2->setEnabled(false);
			}
			else if (_equip_2_c->getPositionX() == 120 && user.get_equip_arm_c_have() == 0) {
				_background_3_white_2->setEnabled(false);
			}
			else {
				_background_3_white_2->setEnabled(true);
			}
			//装备攻击栏
			equipNum_2_1->setPositionX(equipNum_2_1->getPositionX() + winSize.width);
			equipNum_2_2->setPositionX(equipNum_2_2->getPositionX() + winSize.width);
			equipNum_2_3->setPositionX(equipNum_2_3->getPositionX() + winSize.width);


			//机尾
			_equip_3->setPositionX(_equip_3->getPositionX() + winSize.width);
			_equip_3_b->setPositionX(_equip_3_b->getPositionX() + winSize.width);
			_equip_3_c->setPositionX(_equip_3_c->getPositionX() + winSize.width);
			//判断第三行黑白框
			if (_equip_3->getPositionX() == 120 && user.get_equip_tail_have() == 0) {
				_background_3_white_3->setEnabled(false);
			}
			else if (_equip_3_b->getPositionX() == 120 && user.get_equip_tail_b_have() == 0) {
				_background_3_white_3->setEnabled(false);
			}
			else if (_equip_3_c->getPositionX() == 120 && user.get_equip_tail_c_have() == 0) {
				_background_3_white_3->setEnabled(false);
			}
			else {
				_background_3_white_3->setEnabled(true);
			}
			//装备速度栏
			equipNum_3_1->setPositionX(equipNum_3_1->getPositionX() + winSize.width);
			equipNum_3_2->setPositionX(equipNum_3_2->getPositionX() +winSize.width);
			equipNum_3_3->setPositionX(equipNum_3_3->getPositionX() + winSize.width);

		
		}
		else {
			//机身
			_equip_1->setPosition(Vec2(winSize.width *0.2, winSize.height *0.5));
			_equip_1_b->setPosition(Vec2(winSize.width *1.2, winSize.height *0.5));
			_equip_1_c->setPosition(Vec2(winSize.width *2.2, winSize.height *0.5));

			//判断第一行黑白框
			if (_equip_1->getPositionX() == 120 && user.get_equip_head_have() == 0) {
				_background_3_white_1->setEnabled(false);
			}
			else if (_equip_1_b->getPositionX() == 120 && user.get_equip_head_b_have() == 0) {
				_background_3_white_1->setEnabled(false);
			}
			else if (_equip_1_c->getPositionX() == 120 && user.get_equip_head_c_have() == 0) {
				_background_3_white_1->setEnabled(false);
			}
			else {
				_background_3_white_1->setEnabled(true);
			}

			//机翼
			_equip_2->setPosition(Vec2(winSize.width *0.2, winSize.height *0.3));
			_equip_2_b->setPosition(Vec2(winSize.width *1.2, winSize.height *0.3));
			_equip_2_c->setPosition(Vec2(winSize.width *2.2, winSize.height *0.3));

			//判断第二行黑白框
			if (_equip_2->getPositionX() == 120 && user.get_equip_arm_have() == 0) {
				_background_3_white_2->setEnabled(false);
			}
			else if (_equip_2_b->getPositionX() == 120 && user.get_equip_arm_b_have() == 0) {
				_background_3_white_2->setEnabled(false);
			}
			else if (_equip_2_c->getPositionX() == 120 && user.get_equip_arm_c_have() == 0) {
				_background_3_white_2->setEnabled(false);
			}
			else {
				_background_3_white_2->setEnabled(true);
			}

			_equip_3->setPosition(Vec2(winSize.width *0.2, winSize.height *0.1));
			_equip_3_b->setPosition(Vec2(winSize.width *1.2, winSize.height *0.1));
			_equip_3_c->setPosition(Vec2(winSize.width *2.2, winSize.height *0.1));

			//判断第三行黑白框
			if (_equip_3->getPositionX() == 120 && user.get_equip_tail_have() == 0) {
				_background_3_white_3->setEnabled(false);
			}
			else if (_equip_3_b->getPositionX() == 120 && user.get_equip_tail_b_have() == 0) {
				_background_3_white_3->setEnabled(false);
			}
			else if (_equip_3_c->getPositionX() == 120 && user.get_equip_tail_c_have() == 0) {
				_background_3_white_3->setEnabled(false);
			}
			else {
				_background_3_white_3->setEnabled(true);
			}

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
		
	}

}
