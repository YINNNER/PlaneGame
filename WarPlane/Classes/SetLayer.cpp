#include "SetLayer.h"



bool SetLayer::init()
{	
	auto winSize = Director::getInstance()->getWinSize();
	auto origin = Director::getInstance()->getVisibleOrigin();

	auto _background = Sprite::create("/res/UI/a2SelectLevel/background.png");
	_background->setPosition(Vec2(origin.x + winSize.width / 2, origin.y + winSize.height / 2));
	auto scale = winSize.width / _background->getContentSize().width;
	_background->setScale(scale);
	this->addChild(_background);

	auto menuItem_1 = MenuItemImage::create("/res/UI/2Option/back.png", "/res/UI/2Option/backS.png", CC_CALLBACK_1(SetLayer::CallBack, this));
	menuItem_1->setTag(2);
	menuItem_1->setPosition(Vec2(origin.x + winSize.width *0.15, origin.y + winSize.height*0.9));

	auto menuItem_2 = MenuItemImage::create("/res/UI/2Option/help.png", "/res/UI/2Option/helpS.png", CC_CALLBACK_1(SetLayer::CallBack, this));
	menuItem_2->setTag(1);
	menuItem_2->setPosition(Vec2(origin.x + winSize.width / 2, origin.y + winSize.height*0.2));

	auto menu = Menu::create(menuItem_1, menuItem_2,  NULL);
	menu->setPosition(Point::ZERO);
	this->addChild(menu);



	return true;
}


void SetLayer::CallBack(Ref *pSender) {
	int tag = ((MenuItem*)pSender)->getTag();
	switch (tag)
	{
	case 1:
		SceneManager::goHelpLayer(tag);
		break;
	case 2:
		SceneManager::goMenuLayer(tag);
		break;
	default:
		break;
	}
}
