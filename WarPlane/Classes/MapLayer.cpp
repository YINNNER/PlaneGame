#include "MapLayer.h"


bool MapLayer::init() {
	auto winSize = Director::getInstance()->getWinSize();
	auto origin = Director::getInstance()->getVisibleOrigin();
	
	auto _background = Sprite::create("/res/UI/a2SelectLevel/background.png");
	_background->setPosition(Vec2(origin.x + winSize.width / 2, origin.y + winSize.height / 2));
	auto scale = winSize.width / _background->getContentSize().width;
	_background->setScale(scale);
	this->addChild(_background);

	auto back = MenuItemImage::create("/res/UI/a2SelectLevel/back.png", "/res/UI/a2SelectLevel/backB.png", CC_CALLBACK_1(MapLayer::CallMenu, this));
	back->setPosition(Vec2(winSize.width*0.15, winSize.height*0.95));
	back->setScale(0.7);
	back->setTag(2);

	auto repo = MenuItemImage::create("/res/UI/a2SelectLevel/repo.png", "/res/UI/a2SelectLevel/repo.png", CC_CALLBACK_1(MapLayer::CallMenu, this));
	repo->setPosition(Vec2(winSize.width*0.9, winSize.height*0.9));
	repo->setScale(0.3);
	repo->setTag(1);

	Menu*menu = Menu::create(back,repo, NULL);        
	menu->setPosition(Point::ZERO); 
	this->addChild(menu);
	
	return true;
}

void MapLayer::CallMenu(Ref * pSender) {
	int tag = ((MenuItem *)pSender)->getTag();
	switch (tag)
	{
	case 1:
		SceneManager::goRepoLayer(tag);
		break;
	case 2:
		SceneManager::goCreateLayer(tag);
		break;
	
	}
}