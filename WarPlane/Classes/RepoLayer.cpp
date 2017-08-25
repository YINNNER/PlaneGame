#include"RepoLayer.h"
bool RepoLayer::init() {

	Size winSize = Director::getInstance()->getWinSize();

	_background = Sprite::create("/res/UI/0Loading/star.png");
	_background->setPosition(Vec2(winSize.width / 2, winSize.height / 2));
	//_background->setScale(0.5);//缩放0.5倍
	this->addChild(_background);

	_background_1 = Sprite::create("/res/UI/a6Repo/rect1.png");
	_background_1->setPosition(Vec2(winSize.width * 0.3, winSize.height * 3 / 4));
	_background_1->setScale(0.8);//缩放0.5倍
	this->addChild(_background_1);

	_background_1_white = Sprite::create("/res/UI/a6Repo/rectWhite.png");
	_background_1_white->setPosition(Vec2(winSize.width * 0.3, winSize.height * 3 / 4));
	_background_1_white->setScale(0.8);//缩放0.5倍
	this->addChild(_background_1_white);

	_background_2 = Sprite::create("/res/UI/a6Repo/rect2.png");
	_background_2->setPosition(Vec2(winSize.width * 0.7, winSize.height* 3/ 4));
	_background_2->setScale(0.8);//缩放0.5倍
	this->addChild(_background_2);



	_background_3 = Sprite::create("/res/UI/a6Repo/rect3.png");
	_background_3->setPosition(Vec2(winSize.width * 0.5, winSize.height * 0.5));
	_background_3->setScale(0.8);//缩放0.5倍
	this->addChild(_background_3);

	_background_3_white = Sprite::create("/res/UI/a6Repo/rectWhite.png");
	_background_3_white->setPosition(Vec2(winSize.width * 0.2, winSize.height * 0.5));
	_background_3_white->setScale(0.45);//缩放0.5倍
	this->addChild(_background_3_white);

	_background_3 = Sprite::create("/res/UI/a6Repo/rect3.png");
	_background_3->setPosition(Vec2(winSize.width * 0.5, winSize.height * 0.3));
	_background_3->setScale(0.8);//缩放0.5倍
	this->addChild(_background_3);

	_background_3_white = Sprite::create("/res/UI/a6Repo/rectWhite.png");
	_background_3_white->setPosition(Vec2(winSize.width * 0.2, winSize.height * 0.3));
	_background_3_white->setScale(0.45);//缩放0.5倍
	this->addChild(_background_3_white);

	_background_3 = Sprite::create("/res/UI/a6Repo/rect3.png");
	_background_3->setPosition(Vec2(winSize.width * 0.5, winSize.height * 0.1));
	_background_3->setScale(0.8);//缩放0.5倍
	this->addChild(_background_3);

	_background_3_white = Sprite::create("/res/UI/a6Repo/rectWhite.png");
	_background_3_white->setPosition(Vec2(winSize.width * 0.2, winSize.height * 0.1));
	_background_3_white->setScale(0.45);//缩放0.5倍
	this->addChild(_background_3_white);


	/*auto eventTouchListener = EventListenerTouchOneByOne::create();
	eventTouchListener->onTouchBegan = CC_CALLBACK_2(RepoLayer::onTouchBegan, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(eventTouchListener, this);*/


	_plane = Sprite::create("/res/SpaceShooterRedux/PNG/Planes/playerShip1_blue.png");
	_plane->setPosition(Vec2(winSize.width*0.3, winSize.height*3/ 4));
	//_plane->setScale(0.9);
	this->addChild(_plane);

	//判断是否拥有装备选择不同的图片

	auto changeEquip_1 = MenuItemImage::create("/res/SpaceShooterRedux/PNG/Parts/cockpitRed_1.png", "/res/SpaceShooterRedux/PNG/Parts/cockpitRed_1.png", CC_CALLBACK_1(RepoLayer::menuCallBack_1, this));
	changeEquip_1->setPosition(Vec2(winSize.width *0.2, winSize.height *0.5));
	changeEquip_1->setScale(0.95);
	


	    _equip_1Img = Sprite::create("/res/SpaceShooterRedux/PNG/Parts/cockpitRed_1.png");
		_equip_1Img->setPosition(Vec2(winSize.width *0.2, winSize.height *0.5));
		_equip_1Img->setScale(0.95);//缩放0.5倍
		this->addChild(_equip_1Img, 0, 1);


	
	

	

	/*bool ::onTouchBegan(Touch * touch, Event*unused_event) {
		auto _equip_1 = static_cast </span> <Sprite*> (this->getChildByTay(1));
		auto pos = this->convertTouchToNodeSpace(touch);
		if (_equip_1->getBoundingBox().containsPoint(pos))
		{
			log("sp1 click");
			_equip_1->setColor(Color3B::RED)；
		}
	}*/

	auto changeEquip_2 = MenuItemImage::create("/res/SpaceShooterRedux/PNG/Parts/wingRed_1.png", "/res/SpaceShooterRedux/PNG/Parts/wingRed_1.png", CC_CALLBACK_1(RepoLayer::menuCallBack_2, this));
	changeEquip_2->setPosition(Vec2(winSize.width *0.2, winSize.height *0.3));
	changeEquip_2->setScale(0.95);


	_equip_2 = Sprite::create("/res/SpaceShooterRedux/PNG/Parts/wingRed_1.png");
	_equip_2->setPosition(Vec2(winSize.width *0.2, winSize.height *0.3));
	_equip_2->setScale(0.95);
	this->addChild(_equip_2);

	auto changeEquip_3 = MenuItemImage::create("/res/SpaceShooterRedux/PNG/Parts/cockpitRed_2.png", "/res/SpaceShooterRedux/PNG/Parts/cockpitRed_2.png", CC_CALLBACK_1(RepoLayer::menuCallBack_1, this));
	changeEquip_3->setPosition(Vec2(winSize.width *0.2, winSize.height *0.1));
	changeEquip_3->setScale(0.95);
	auto menu = Menu::create(changeEquip_1,changeEquip_2,changeEquip_3, NULL);
	menu->setPosition(Vec2(Point::ZERO));
	this->addChild(menu);

	_equip_3 = Sprite::create("/res/SpaceShooterRedux/PNG/Parts/cockpitRed_2.png");
	_equip_3->setPosition(Vec2(winSize.width *0.2, winSize.height *0.1));
	_equip_3->setScale(0.95);
	this->addChild(_equip_3);

	//传入战机名
	Label * planeName = Label::createWithTTF("plane1", "fonts/simhei.ttf", 28);
	planeName->setPosition(Vec2(winSize.width * 0.6, winSize.height * 0.84));
	this->addChild(planeName);

	//传入等级值
	Label * level = Label::createWithTTF("lv:","fonts/simhei.ttf", 28);
	level->setPosition(Vec2(winSize.width * 0.8, winSize.height * 0.84));
	this->addChild(level);

	Label * life = Label::createWithTTF("生命","fonts/simhei.ttf", 15);
	life->setPosition(Vec2(winSize.width * 0.6, winSize.height * 0.8));
	this->addChild(life);

	Label *  energy = Label::createWithTTF("能量", "fonts/simhei.ttf", 15);
	energy->setPosition(Vec2(winSize.width * 0.6, winSize.height * 0.76));
	this->addChild(energy);

	Label *  attack = Label::createWithTTF("攻击", "fonts/simhei.ttf", 15);
	attack->setPosition(Vec2(winSize.width * 0.6, winSize.height * 0.72));
	this->addChild(attack);

	Label *  speed = Label::createWithTTF("速度", "fonts/simhei.ttf", 15);
	speed->setPosition(Vec2(winSize.width * 0.6, winSize.height * 0.68));
	this->addChild(speed);

	Label * equipName_1 = Label::createWithTTF("部件名称", "fonts/simhei.ttf", 15);
	equipName_1->setPosition(Vec2(winSize.width * 0.5, winSize.height * 0.55));
	this->addChild(equipName_1);

	Label * equipName_1_1 = Label::createWithTTF("攻击", "fonts/simhei.ttf", 15);
	equipName_1_1->setPosition(Vec2(winSize.width * 0.5, winSize.height * 0.5));
	this->addChild(equipName_1_1);

	Label * equipName_1_2 = Label::createWithTTF("数量", "fonts/simhei.ttf", 15);
	equipName_1_2->setPosition(Vec2(winSize.width * 0.7, winSize.height * 0.5));
	this->addChild(equipName_1_2);

	Label * equipName_2 = Label::createWithTTF("部件名称", "fonts/simhei.ttf", 15);
	equipName_2->setPosition(Vec2(winSize.width * 0.5, winSize.height * 0.35));
	this->addChild(equipName_2);


	Label * equipName_3 = Label::createWithTTF("部件名称", "fonts/simhei.ttf", 15);
	equipName_3->setPosition(Vec2(winSize.width * 0.5, winSize.height * 0.15));
	this->addChild(equipName_3);




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
menuItem->setPosition(Vec2(winSize.width / 2, winSize.height*0.3));
static MenuItemSprite * create(Node * normalSprite, Node * normalSprite, Node * normalSprite, );
MenuItemImage * equip_1 = MenuItemImage::create("/res/SpaceShooterRedux/PNG/Planes/playerShip1_green.png", "/res/SpaceShooterRedux/PNG/Planes/playerShip1_green.png");
MenuItemImage * equip_2 = MenuItemImage::create("/res/SpaceShooterRedux/PNG/Planes/playerShip1_blue.png", "/res/SpaceShooterRedux/PNG/Planes/playerShip1_blue.png");
MenuItemToggle* equip = MenuItemToggle::createWithTarget(this,menu_selector(RepoLayer::changeEquip),equip_1,equip_2,NULL);

Menu * equipMenu = Menu::create(equip,NULL);
equip->setPosition(Vec2(winSize.width / 2, winSize.height*0.3));
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


bool RepoLayer::onTouchBegan(Touch * touch, Event * event) {
	//获得事件绑定的target
	auto target = static_cast<Sprite *>(event->getCurrentTarget());//强制转换为sprite对象
	Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());//获取触摸点相对于target对象的模型坐标
	Size s = target->getContentSize();//获得target对象尺寸
	Rect rect = Rect(0, 0, s.width, s.height);//放大target对象

	//单击范围判断检测
	if (rect.containsPoint(locationInNode)) {
		target->runAction(ScaleBy::create(0.06f, 1.06f));
		Size winSize = Director::getInstance()->getWinSize();
		_plane_2 = Sprite::create("/res/SpaceShooterRedux/PNG/Planes/playerShip1_green.png");
		_plane_2->setPosition(Vec2(winSize.width*0.3, winSize.height * 3 / 4));
		//_plane->setScale(0.9);
		this->addChild(_plane_2);
		return true;
	}
	return false;
}
/*
//注销所有监听事件
void RepoLayer::onExit() {
	Layer::onExit();
	Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
}
*/
void RepoLayer::menuCallBack_1(Ref * pSender) {

	Size winSize = Director::getInstance()->getWinSize();
	_plane_2 = Sprite::create("/res/SpaceShooterRedux/PNG/Planes/playerShip1_green.png");
	_plane_2->setPosition(Vec2(winSize.width*0.3, winSize.height * 3 / 4));
	//_plane->setScale(0.9);
	this->addChild(_plane_2);
}

void RepoLayer::menuCallBack_2(Ref * pSender) {
	Size winSize = Director::getInstance()->getWinSize();
	_plane_2 = Sprite::create("/res/SpaceShooterRedux/PNG/Planes/playerShip1_orange.png");
	_plane_2->setPosition(Vec2(winSize.width*0.3, winSize.height * 3 / 4));
	//_plane->setScale(0.9);
	this->addChild(_plane_2);
}

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