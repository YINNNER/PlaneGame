#include "CreateLayer.h"
#include "SimpleAudioEngine.h"
using namespace CocosDenshion;

bool CreateLayer :: init() {
	auto winSize = Director::getInstance()->getWinSize();
	auto origin = Director::getInstance()->getVisibleOrigin();
	
	auto _background = Sprite::create("res/UI/1Menu/background.png");
	_background->setPosition(Vec2(origin.x + winSize.width /2, origin.y + winSize.height / 2));
	auto scale = winSize.width / _background->getContentSize().width;
	_background->setScale(scale);
	this->addChild(_background);

	auto show1 = MenuItemImage::create("res/UI/a1CreatePlayer/plane1_unselected.png", "res/UI/a1CreatePlayer/plane1_unselected.png",CC_CALLBACK_1(CreateLayer::CallBack,this));
	show1->setPosition(Vec2(winSize.width *0.18, winSize.height*0.6));
	//show1->setScale(1.1);
	show1->setTag(10);
	selected_1 = Sprite::create("res/UI/a1CreatePlayer/bar1.png");
	selected_1->setPosition(Vec2(winSize.width *0.19, winSize.height*0.61));
	selected_1->retain();
	this->addChild(selected_1,1);
	selected_1->setVisible(false);
	
	auto show2 = MenuItemImage::create("res/UI/a1CreatePlayer/plane3_unselected.png", "res/UI/a1CreatePlayer/plane3_unselected.png", CC_CALLBACK_1(CreateLayer::CallBack, this));
	show2->setPosition(Vec2(winSize.width *0.5, winSize.height*0.6));
	//show2->setScale(1.2);
	show2->setTag(11);
	selected_2 = Sprite::create("res/UI/a1CreatePlayer/bar2.png");
	selected_2->setPosition(Vec2(winSize.width *0.51, winSize.height*0.61));
	selected_2->retain();
	this->addChild(selected_2, 1);
	selected_2->setVisible(false);

	auto show3 = MenuItemImage::create("res/UI/a1CreatePlayer/plane1_unselected.png", "res/UI/a1CreatePlayer/plane1_unselected.png", CC_CALLBACK_1(CreateLayer::CallBack, this));
	show3->setPosition(Vec2(winSize.width *0.82, winSize.height*0.6));
	//show3->setScale(1.2);
	show3->setTag(12);
	selected_3 = Sprite::create("res/UI/a1CreatePlayer/bar3.png");
	selected_3->setPosition(Vec2(winSize.width *0.83, winSize.height*0.61));
	selected_3->retain();
	this->addChild(selected_3, 1);
	selected_3->setVisible(false);

	auto menu1 = Menu::create(show1, show2, show3, NULL);
	menu1->setPosition(Point::ZERO);
	this->addChild(menu1,0);
	
	auto username = Label::createWithTTF("姓名", "fonts/simhei.ttf", 40);
	username->setPosition(Vec2(winSize.width*0.3, winSize.height*0.25));
	this->addChild(username);

	auto menuItem_1 = MenuItemImage::create("res/UI/a1CreatePlayer/createButton.png", "res/UI/a1CreatePlayer/createButtonS.png", CC_CALLBACK_1(CreateLayer::CallBack, this));
	menuItem_1->setTag(1);
	menuItem_1->setPosition(Vec2(origin.x + winSize.width / 2, origin.y + winSize.height*0.1));

	auto back = MenuItemImage::create("res/UI/b1Help/back.png", "res/UI/b1Help/backS.png", CC_CALLBACK_1(CreateLayer::CallBack, this));
	back->setTag(2);
	back->setPosition(Vec2(winSize.width*0.15, winSize.height*0.9));

	auto menu2 = Menu::create(menuItem_1,back, NULL);
	menu2->setPosition(Point::ZERO);
	this->addChild(menu2);


	return true;
}



void CreateLayer::CallBack(Ref *pSender) {
	int tag = ((MenuItem*)pSender)->getTag();
	auto winSize = Director::getInstance()->getWinSize();
	auto origin = Director::getInstance()->getVisibleOrigin();

	switch (tag)
	{
	case 1:
	{
		SimpleAudioEngine::sharedEngine()->playEffect("/music/trans1.wav");
        int gameLevel=1;
		SceneManager::goMapLayer(tag,gameLevel);
	}break;
	case 2: {
		SimpleAudioEngine::sharedEngine()->playEffect("/music/trans1.wav");
		int transiTimes = 1;
		SceneManager::goMenuLayer(tag,transiTimes);
	}break;
	case 10: {
		if (selected_2->isVisible())
			selected_2->setVisible(false);
		if (selected_3->isVisible())
			selected_3->setVisible(false);
		selected_1->setVisible(true);
	}break;
	case 11: {
		if(selected_1->isVisible())
			selected_1->setVisible(false);
		if (selected_3->isVisible())
			selected_3->setVisible(false);
		selected_2->setVisible(true);
	}break;
	case 12: {
		if (selected_1->isVisible())
			selected_1->setVisible(false);
		if (selected_2->isVisible())
			selected_2->setVisible(false);
		selected_3->setVisible(true);
	}break;
	}
}
