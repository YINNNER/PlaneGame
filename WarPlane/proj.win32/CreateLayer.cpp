#include "CreateLayer.h"


bool CreateLayer :: init() {
	auto winSize = Director::getInstance()->getWinSize();
	auto origin = Director::getInstance()->getVisibleOrigin();
	
	auto _background = Sprite::create("/res/UI/a1CreatePlayer/background.png");
	_background->setPosition(Vec2(origin.x + winSize.width /2, origin.y + winSize.height / 2));
	auto scale = winSize.width / _background->getContentSize().width;
	_background->setScale(scale);
	this->addChild(_background);

	auto show1 = MenuItemImage::create("/res/UI/a1CreatePlayer/plane1_unselected.png", "/res/UI/a1CreatePlayer/bar1.png");
	show1->setPosition(Vec2(winSize.width *0.18, winSize.height*0.7));
	//show1->setScale(1.1);
	show1->setTag(10);
	
	auto show2 = MenuItemImage::create("/res/UI/a1CreatePlayer/plane3_unselected.png", "/res/UI/a1CreatePlayer/bar2.png");
	show2->setPosition(Vec2(winSize.width *0.5, winSize.height*0.7));
	//show2->setScale(1.2);
	show2->setTag(11);

	auto show3 = MenuItemImage::create("/res/UI/a1CreatePlayer/plane1_unselected.png", "/res/UI/a1CreatePlayer/bar3.png");
	show3->setPosition(Vec2(winSize.width *0.82, winSize.height*0.7));
	//show3->setScale(1.2);
	show3->setTag(12);

	auto menu1 = Menu::create(show1, show2, show3, NULL);
	menu1->setPosition(Point::ZERO);
	this->addChild(menu1);
	
	auto username = Label::createWithSystemFont("战机名:", "simhei.ttf", 40);
	username->setPosition(Vec2(winSize.width*0.3, winSize.height*0.25));
	this->addChild(username);

	auto menuItem_1 = MenuItemImage::create("/res/UI/a1CreatePlayer/createButton.png", "/res/UI/a1CreatePlayer/createButtonS.png", CC_CALLBACK_1(CreateLayer::CreatePlayer, this));
	menuItem_1->setTag(1);
	menuItem_1->setPosition(Vec2(origin.x + winSize.width / 2, origin.y + winSize.height*0.1));

	auto menu2 = Menu::create(menuItem_1, NULL);
	menu2->setPosition(Point::ZERO);
	this->addChild(menu2);


	return true;
}


bool CreateLayer::CreatePlayer(Ref * pSender) {
	
	int tag = ((MenuItem*)pSender)->getTag();
	SceneManager::goMapLayer(tag);

	return true;
}
