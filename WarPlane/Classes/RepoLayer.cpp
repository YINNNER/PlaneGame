#include"RepoLayer.h"
bool RepoLayer::init() {
	
	Size winSize = Director::getInstance()->getWinSize();
	auto origin = Director::getInstance()->getVisibleOrigin();
	float offset = winSize.height*0;


	_background = Sprite::create("res/UI/0Loading/star.png");
	_background->setPosition(Vec2(origin.x+winSize.width / 2, origin.y+winSize.height / 2));
	//_background->setScale(0.5);//缩放0.5倍
	this->addChild(_background);

	_background_1 = Sprite::create("res/UI/a6Repo/rect1.png");
	_background_1->setPosition(Vec2(origin.x+winSize.width * 0.3, origin.y+winSize.height * 3 / 4));
	//_background_1->setScale(0.8);//缩放0.5倍
	this->addChild(_background_1,2);

	_background_1_white = Sprite::create("res/UI/a6Repo/rectWhite.png");
	_background_1_white->setPosition(Vec2(origin.x+winSize.width * 0.3, origin.y+winSize.height * 3 / 4));
	//_background_1_white->setScale(0.8);//缩放0.5倍
	this->addChild(_background_1_white,2);

	_background_2 = Sprite::create("res/UI/a6Repo/rect2.png");
	_background_2->setPosition(Vec2(origin.x+winSize.width * 0.7, origin.y+winSize.height* 3/ 4));
	//_background_2->setScale(0.8);//缩放0.5倍
	this->addChild(_background_2,2);



	_background_3 = Sprite::create("res/UI/a6Repo/rect3.png");
	_background_3->setPosition(Vec2(origin.x+winSize.width * 0.5, origin.y+winSize.height * 0.5+offset));
	//_background_3->setScale(0.8);//缩放0.5倍
	this->addChild(_background_3,1);

	_background_3_white = Sprite::create("res/UI/a6Repo/rectWhite.png");
	_background_3_white->setPosition(Vec2(origin.x+winSize.width * 0.2, origin.y+winSize.height * 0.5+offset));
	_background_3_white->setScale(0.6);//缩放0.5倍
	this->addChild(_background_3_white,1);

	_background_3 = Sprite::create("res/UI/a6Repo/rect3.png");
	_background_3->setPosition(Vec2(origin.x+winSize.width * 0.5, origin.y+winSize.height * 0.3 + offset));
	//_background_3->setScale(0.8);//缩放0.5倍
	this->addChild(_background_3,1);

	_background_3_white = Sprite::create("res/UI/a6Repo/rectWhite.png");
	_background_3_white->setPosition(Vec2(origin.x+winSize.width * 0.2, origin.y+winSize.height * 0.3 + offset));
	_background_3_white->setScale(0.6);//缩放0.5倍
	this->addChild(_background_3_white,1);

	_background_3 = Sprite::create("res/UI/a6Repo/rect3.png");
	_background_3->setPosition(Vec2(origin.x+winSize.width * 0.5, origin.y+winSize.height * 0.1 + offset));
	//->setScale(0.8);//缩放0.5倍
	this->addChild(_background_3,1);

	_background_3_white = Sprite::create("res/UI/a6Repo/rectWhite.png");
	_background_3_white->setPosition(Vec2(origin.x+winSize.width * 0.2, origin.y+winSize.height * 0.1 + offset));
	_background_3_white->setScale(0.6);//缩放0.5倍
	this->addChild(_background_3_white,1);

	_background_3 = Sprite::create("res/UI/a6Repo/rect3.png");
	_background_3->setPosition(Vec2(origin.x + winSize.width * 0.5, origin.y - winSize.height * 0.1 + offset));
	//->setScale(0.8);//缩放0.5倍
	this->addChild(_background_3,1);

	_background_3_white = Sprite::create("res/UI/a6Repo/rectWhite.png");
	_background_3_white->setPosition(Vec2(origin.x + winSize.width * 0.2, origin.y - winSize.height * 0.1 + offset));
	_background_3_white->setScale(0.6);//缩放0.5倍
	this->addChild(_background_3_white,1);

	_background_3 = Sprite::create("res/UI/a6Repo/rect3.png");
	_background_3->setPosition(Vec2(origin.x + winSize.width * 0.5, origin.y - winSize.height * 0.3 + offset));
	//->setScale(0.8);//缩放0.5倍
	this->addChild(_background_3,1);

	_background_3_white = Sprite::create("res/UI/a6Repo/rectWhite.png");
	_background_3_white->setPosition(Vec2(origin.x + winSize.width * 0.2, origin.y - winSize.height * 0.3 + offset));
	_background_3_white->setScale(0.6);//缩放0.5倍
	this->addChild(_background_3_white,1);

	_background_3 = Sprite::create("res/UI/a6Repo/rect3.png");
	_background_3->setPosition(Vec2(origin.x + winSize.width * 0.5, origin.y - winSize.height * 0.5 + offset));
	//->setScale(0.8);//缩放0.5倍
	this->addChild(_background_3,1);

	_background_3_white = Sprite::create("res/UI/a6Repo/rectWhite.png");
	_background_3_white->setPosition(Vec2(origin.x + winSize.width * 0.2, origin.y - winSize.height * 0.5 + offset));
	_background_3_white->setScale(0.6);//缩放0.5倍
	this->addChild(_background_3_white,1);

	/*auto eventTouchListener = EventListenerTouchOneByOne::create();
	eventTouchListener->onTouchBegan = CC_CALLBACK_2(RepoLayer::onTouchBegan, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(eventTouchListener, this);*/


	_plane = Sprite::create("res/UI/plane_parts/planeType1/playerShip1_green.png");
	_plane->setPosition(Vec2(origin.x+winSize.width*0.3, origin.y+winSize.height *3/ 4));
	//_plane->setScale(0.9);
	this->addChild(_plane,2);

	//判断是否拥有装备选择不同的图片

	auto changeEquip_1 = MenuItemImage::create("res/UI/plane_parts/planeType1/playerShip1_blue_02.png", "res/UI/plane_parts/planeType1/playerShip1_blue_02.png", CC_CALLBACK_1(RepoLayer::menuCallBack_1, this));
	changeEquip_1->setPosition(Vec2(origin.x+winSize.width *0.2, origin.y+winSize.height *0.5 + offset));
	changeEquip_1->setScale(0.95);
	


	  _equip_1Img = Sprite::create("res/UI/plane_parts/planeType1/playerShip1_blue_02.png");
		_equip_1Img->setPosition(Vec2(origin.x+winSize.width *0.2, origin.y+winSize.height *0.5 + offset));
		//_equip_1Img->setScale(0.95);//缩放0.5倍
		this->addChild(_equip_1Img, 1);


	
	

	

	/*bool ::onTouchBegan(Touch * touch, Event*unused_event) {
		auto _equip_1 = static_cast </span> <Sprite*> (this->getChildByTay(1));
		auto pos = this->convertTouchToNodeSpace(touch);
		if (_equip_1->getBoundingBox().containsPoint(pos))
		{
			log("sp1 click");
			_equip_1->setColor(Color3B::RED)；
		}
	}*/

	auto changeEquip_2 = MenuItemImage::create("res/UI/plane_parts/planeType1/playerShip1_blue_01.png", "res/UI/plane_parts/planeType1/playerShip1_blue_01.png", CC_CALLBACK_1(RepoLayer::menuCallBack_2, this));
	changeEquip_2->setPosition(Vec2(origin.x+winSize.width *0.2, origin.y+winSize.height *0.3 + offset));
	//changeEquip_2->setScale(0.95);


	_equip_2 = Sprite::create("res/UI/plane_parts/planeType1/playerShip1_blue_01.png");
	_equip_2->setPosition(Vec2(origin.x+winSize.width *0.2, origin.y+winSize.height *0.3 + offset));
	//_equip_2->setScale(0.95);
	this->addChild(_equip_2,1);

	auto changeEquip_3 = MenuItemImage::create("res/UI/plane_parts/planeType1/playerShip1_blue_04.png", "res/UI/plane_parts/planeType1/playerShip1_blue_04.png", CC_CALLBACK_1(RepoLayer::menuCallBack_3, this));
	changeEquip_3->setPosition(Vec2(origin.x+winSize.width *0.2, origin.y+winSize.height *0.1 + offset));

	/*auto change = MenuItemImage::create("res/UI/plane_parts/planeType1/playerShip1_blue_01.png", "res/UI/plane_parts/planeType1/playerShip1_blue_01.png", CC_CALLBACK_1(RepoLayer::menuCallBack_4, this));
	change->setPosition(Vec2(origin.x + winSize.width *0.9, origin.y + winSize.height *0.1));*/


	//返回按钮
	auto back = MenuItemImage::create("res/UI/a2SelectLevel/back.png", "res/UI/a2SelectLevel/backB.png", CC_CALLBACK_1(RepoLayer::CallMenu, this));
	back->setPosition(Vec2(winSize.width*0.15, winSize.height*0.9));
	back->setScale(0.55);
	back->setTag(2);

	auto menu = Menu::create(changeEquip_1,changeEquip_2,changeEquip_3,back, NULL);
	menu->setPosition(Vec2(Point::ZERO));
	this->addChild(menu,1);

	_equip_3 = Sprite::create("res/UI/plane_parts/planeType1/playerShip1_blue_04.png");
	_equip_3->setPosition(Vec2(origin.x+winSize.width *0.2, origin.y+winSize.height *0.1 + offset));
	//_equip_3->setScale(0.95);
	this->addChild(_equip_3,1);

	//传入战机名
	Label * planeName = Label::createWithTTF("plane1", "fonts/simhei.ttf", 28);
	planeName->setPosition(Vec2(origin.x+winSize.width * 0.6, origin.y+winSize.height * 0.84));
	this->addChild(planeName,2);

	//传入等级值
	Label * level = Label::createWithTTF("lv.","fonts/simhei.ttf", 28);
	level->setPosition(Vec2(origin.x+winSize.width * 0.8, origin.y+winSize.height * 0.84));
	this->addChild(level,2);
	//飞机属性栏
	Label * life = Label::createWithTTF("生命","fonts/simhei.ttf", 15);
	life->setPosition(Vec2(origin.x+winSize.width * 0.57, origin.y+winSize.height * 0.8));
	this->addChild(life,2);



	Label *  energy = Label::createWithTTF("能量", "fonts/simhei.ttf", 15);
	energy->setPosition(Vec2(origin.x+winSize.width * 0.57, origin.y+winSize.height * 0.76));
	this->addChild(energy,2);

	Label *  attack = Label::createWithTTF("攻击", "fonts/simhei.ttf", 15);
	attack->setPosition(Vec2(origin.x+winSize.width * 0.57, origin.y+winSize.height * 0.72));
	this->addChild(attack,2);

	Label *  speed = Label::createWithTTF("速度", "fonts/simhei.ttf", 15);
	speed->setPosition(Vec2(origin.x+winSize.width * 0.57, origin.y+winSize.height * 0.68));
	this->addChild(speed,2);
	//装备栏
	Label * equipName_1 = Label::createWithTTF("部件名称    机身", "fonts/simhei.ttf", 15);
	equipName_1->setPosition(Vec2(origin.x+winSize.width * 0.5, origin.y+winSize.height * 0.55 + offset));
	this->addChild(equipName_1,1);

	Equip * _equip_1 = Equip::create();
	_equip_1->setType(1);
	std::stringstream a;
	std::stringstream b;
	a << (_equip_1->getImpHp());
	b << (_equip_1->getEquipNum());

	Label * equipName_1_1 = Label::createWithTTF("hp", "fonts/simhei.ttf", 15);
	equipName_1_1->setPosition(Vec2(origin.x+winSize.width * 0.41, origin.y+winSize.height * 0.5 + offset));
	this->addChild(equipName_1_1,1);

	Label * equipNum_1_1 = Label::createWithTTF(a.str().c_str(), "fonts/simhei.ttf", 15);
	equipNum_1_1->setPosition(Vec2(origin.x+winSize.width * 0.5, origin.y+winSize.height * 0.5 + offset));
	this->addChild(equipNum_1_1,1);

	Label * equipName_1_2 = Label::createWithTTF("数量", "fonts/simhei.ttf", 15);
	equipName_1_2->setPosition(Vec2(origin.x+winSize.width * 0.7, origin.y+winSize.height * 0.5 + offset));
	this->addChild(equipName_1_2,1);

	Label * equipNum_1_2 = Label::createWithTTF(b.str().c_str(), "fonts/simhei.ttf", 15);
	equipNum_1_2->setPosition(Vec2(origin.x+winSize.width * 0.8, origin.y+winSize.height * 0.5 + offset));
	this->addChild(equipNum_1_2,1);

	Label * equipName_2 = Label::createWithTTF("部件名称    机翼", "fonts/simhei.ttf", 15);
	equipName_2->setPosition(Vec2(origin.x+winSize.width * 0.5, origin.y+winSize.height * 0.35 + offset));
	this->addChild(equipName_2,1);

	Equip * _equip_2 = Equip::create();
	_equip_2->setType(2);
	std::stringstream c;
	std::stringstream d;
	c << (_equip_2->getImpAtk());
	d << (_equip_2->getEquipNum());

	Label * equipName_2_1 = Label::createWithTTF("攻击", "fonts/simhei.ttf", 15);
	equipName_2_1->setPosition(Vec2(origin.x+winSize.width * 0.41, origin.y+winSize.height * 0.3 + offset));
	this->addChild(equipName_2_1,1);

	Label * equipNum_2_1 = Label::createWithTTF(c.str().c_str(), "fonts/simhei.ttf", 15);
	equipNum_2_1->setPosition(Vec2(origin.x+winSize.width * 0.5, origin.y+winSize.height * 0.3 + offset));
	this->addChild(equipNum_2_1,1);

	Label * equipName_2_2 = Label::createWithTTF("数量", "fonts/simhei.ttf", 15);
	equipName_2_2->setPosition(Vec2(origin.x+winSize.width * 0.7, origin.y+winSize.height * 0.3 + offset));
	this->addChild(equipName_2_2,1);

	Label * equipNum_2_2 = Label::createWithTTF(b.str().c_str(), "fonts/simhei.ttf", 15);
	equipNum_2_2->setPosition(Vec2(origin.x+winSize.width * 0.8, origin.y+winSize.height * 0.3 + offset));
	this->addChild(equipNum_2_2,1);

	Label * equipName_3 = Label::createWithTTF("部件名称    机尾", "fonts/simhei.ttf", 15);
	equipName_3->setPosition(Vec2(origin.x+winSize.width * 0.5, origin.y+winSize.height * 0.15 + offset));
	this->addChild(equipName_3,1);

	Equip * _equip_3 = Equip::create();
	_equip_3->setType(3);
	std::stringstream e;
	std::stringstream f;
	e << (_equip_3->getImpSpd());
	f << (_equip_3->getEquipNum());

	Label * equipName_3_1 = Label::createWithTTF("速度", "fonts/simhei.ttf", 15);
	equipName_3_1->setPosition(Vec2(origin.x+winSize.width * 0.41, origin.y+winSize.height * 0.1 + offset));
	this->addChild(equipName_3_1,1);

	Label * equipNum_3_1 = Label::createWithTTF(e.str().c_str(), "fonts/simhei.ttf", 15);
	equipNum_3_1->setPosition(Vec2(origin.x+winSize.width * 0.5, origin.y+winSize.height * 0.1 + offset));
	this->addChild(equipNum_3_1,1);

	Label * equipName_3_2 = Label::createWithTTF("数量", "fonts/simhei.ttf", 15);
	equipName_3_2->setPosition(Vec2(origin.x+winSize.width * 0.7, origin.y+winSize.height * 0.1 + offset));
	this->addChild(equipName_3_2,1);

	Label * equipNum_3_2 = Label::createWithTTF(f.str().c_str(), "fonts/simhei.ttf", 15);
	equipNum_3_2->setPosition(Vec2(origin.x+winSize.width * 0.8, origin.y+winSize.height * 0.1 + offset));
	this->addChild(equipNum_3_2,1);

	
	BaseBarHp = Sprite::create("res/UI/0Loading/loadingBarEmpty.png");
	BaseBarHp->setPosition(Vec2(origin.x+winSize.width *0.71, origin.y+winSize.height *0.8));
	BaseBarHp->setScale(0.25, 0.5);
	this->addChild(BaseBarHp,2);

	BaseBarEn = Sprite::create("res/UI/0Loading/loadingBarEmpty.png");
	BaseBarEn->setPosition(Vec2(origin.x+winSize.width *0.71, origin.y+winSize.height *0.76));
	BaseBarEn->setScale(0.25, 0.5);
	this->addChild(BaseBarEn,2);

	BaseBarAtk = Sprite::create("res/UI/0Loading/loadingBarEmpty.png");
	BaseBarAtk->setPosition(Vec2(origin.x+winSize.width *0.71, origin.y+winSize.height *0.72));
	BaseBarAtk->setScale(0.25, 0.5);
	this->addChild(BaseBarAtk,2);

	BaseBarSpd = Sprite::create("res/UI/0Loading/loadingBarEmpty.png");
	BaseBarSpd->setPosition(Vec2(origin.x+winSize.width *0.71, origin.y+winSize.height *0.68));
	BaseBarSpd->setScale(0.25, 0.5);
	this->addChild(BaseBarSpd,2);

	HpBar = Sprite::create("res/UI/0Loading/loadingBarFull.png");
	HpBar->setPosition(Vec2(origin.x+winSize.width *0.641, origin.y+winSize.height *0.798));
	HpBar->setScale(0.25*(_equip_1->getImpHp())/1000, 0.5);
	HpBar->setAnchorPoint(Vec2(0,0));
	this->addChild(HpBar,2);
	/*
	EnBar = Sprite::create("res/UI/0Loading/loadingBarFull.png");
	EnBar->setPosition(Vec2(origin.x+winSize.width *0.665, origin.y+winSize.height *0.76));
	EnBar->setScale(0.25*(_equip_2->getImpAtk()) / 1000, 0.5);
	EnBar->setAnchorPoint(Vec2(0, 0));
	this->addChild(EnBar);
*/
	AtkBar = Sprite::create("res/UI/0Loading/loadingBarFull.png");
	AtkBar->setPosition(Vec2(origin.x+winSize.width *0.64, origin.y+winSize.height *0.718));
	AtkBar->setScale(0.25*(_equip_2->getImpAtk()) / 1000, 0.5);
	AtkBar->setAnchorPoint(Vec2(0, 0));
	this->addChild(AtkBar,2);

	SpdBar = Sprite::create("res/UI/0Loading/loadingBarFull.png");
	SpdBar->setPosition(Vec2(origin.x+winSize.width *0.641, origin.y+winSize.height *0.678));
	SpdBar->setScale(0.25*(_equip_3->getImpSpd()) / 1000, 0.5);
	SpdBar->setAnchorPoint(Vec2(0, 0));
	this->addChild(SpdBar,2);


	

	return true;

	/*setTouchEnable(true);
	setTouchMode(Touch::DispatchMode::ONE_BY_ONE);
	/*
	auto listener = EventListenerMouse::create();
	listener->onMouseDown = [](Event * event){
	EventMouse * e = (EventMouse * )event;
    }
*/
/*MenuItemLabel * menuItem = MenuItemLabel::create(Label::createWithSystemFont(" / res / SpaceShooterRedux / PNG / Parts / cockpitBlue_1.png", "", ), CC_CALLBACK_1(OpenLayer::menuCallBack, this));
//使用tag进行标记
menuItem->setTag(101);
menuItem->setPosition(Vec2(origin.x+winSize.width / 2, origin.y+winSize.height*0.3));
static MenuItemSprite * create(Node * normalSprite, Node * normalSprite, Node * normalSprite, );
MenuItemImage * equip_1 = MenuItemImage::create("res/SpaceShooterRedux/PNG/Planes/playerShip1_green.png", "res/SpaceShooterRedux/PNG/Planes/playerShip1_green.png");
MenuItemImage * equip_2 = MenuItemImage::create("res/SpaceShooterRedux/PNG/Planes/playerShip1_blue.png", "res/SpaceShooterRedux/PNG/Planes/playerShip1_blue.png");
MenuItemToggle* equip = MenuItemToggle::createWithTarget(this,menu_selector(RepoLayer::changeEquip),equip_1,equip_2,NULL);

Menu * equipMenu = Menu::create(equip,NULL);
equip->setPosition(Vec2(origin.x+winSize.width / 2, origin.y+winSize.height*0.3));
equipMenu->setPosition(Vec2::ZERO);
this->addChild(equip);*/

}

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
	eventDispatcher->addEventListenerWithSceneGraphPriority(listener, getChildByTag(kEquip_1_Tag));
	eventDispatcher->addEventListenerWithSceneGraphPriority(listener->clone(), getChildByTag(kEquip_2_Tag));
	eventDispatcher->addEventListenerWithSceneGraphPriority(listener->clone(), getChildByTag(kEquip_3_Tag));

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
void RepoLayer::menuCallBack_1(Ref * pSender) {

	Size winSize = Director::getInstance()->getWinSize();
	auto origin = Director::getInstance()->getVisibleOrigin();

	_body_1 = Sprite::create("res/UI/plane_parts/planeType1/playerShip1_blue_02.png");
	_body_1->setPosition(Vec2(origin.x + winSize.width*0.3, origin.y + winSize.height * 0.757));
	this->addChild(_body_1,2);

	//void setEHP(存档中 + getImpHp());

}

void RepoLayer::menuCallBack_2(Ref * pSender) {
	Size winSize = Director::getInstance()->getWinSize();
	auto origin = Director::getInstance()->getVisibleOrigin();

	

	_wing_1 = Sprite::create("res/UI/plane_parts/planeType1/playerShip1_blue_01.png");
	_wing_1->setPosition(Vec2(origin.x + winSize.width*0.26, origin.y + winSize.height * 0.75));
	//_plane->setScale(0.9);
	this->addChild(_wing_1, 2);

	_wing_2 = Sprite::create("res/UI/plane_parts/planeType1/playerShip1_blue_03.png");
	_wing_2->setPosition(Vec2(origin.x + winSize.width*0.34, origin.y + winSize.height * 0.75));
	//_plane->setScale(0.9);
	this->addChild(_wing_2, 2);
}

void RepoLayer::menuCallBack_3(Ref * pSender) {
	Size winSize = Director::getInstance()->getWinSize();
	auto origin = Director::getInstance()->getVisibleOrigin();

	_tail_1 = Sprite::create("res/UI/plane_parts/planeType1/playerShip1_blue_04.png");
	_tail_1->setPosition(Vec2(origin.x + winSize.width*0.3, origin.y + winSize.height * 0.717));
	//_plane->setScale(0.9);
	this->addChild(_tail_1, 2);

	
}


//返回关卡选择
void RepoLayer::CallMenu(Ref * pSender)
{
	int gameLevel = 1;
	//SceneManager::goMapLayer(2,gameLevel);
}

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
	auto _equip_1 = this->getChildByTage(equip_1_Tag);
	if (this->isTap(_equip_1, touch)) {
		//更换飞机图片
		_plane
	}
	return true；
}
*/