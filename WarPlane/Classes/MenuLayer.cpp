#include "MenuLayer.h"
#include "SimpleAudioEngine.h"
using namespace CocosDenshion;


bool MenuLayer::init(){
	
	auto winSize = Director::getInstance()->getWinSize();
	auto origin = Director::getInstance()->getVisibleOrigin();

	
	_background = Sprite::create("res/UI/1Menu/background.png");
	_background->setPosition(Vec2(origin.x + winSize.width / 2, origin.y + winSize.height / 2));
	auto scale = winSize.width / _background->getContentSize().width;
	_background->setScale(scale);
	this->addChild(_background);
	
	Sprite *title = Sprite::create("res/UI/1Menu/title.png");
	title->setPosition(Vec2(winSize.width / 2, winSize.height*0.8));
	title->setScale(1.2);
	this->addChild(title);

	auto menuItem_1 = MenuItemImage::create("res/UI/1Menu/new.png","res/UI/1Menu/newS.png",CC_CALLBACK_1(MenuLayer::CallMenu,this));
	menuItem_1->setTag(1);
	menuItem_1->setPosition(Vec2(origin.x+winSize.width / 2, origin.y+winSize.height*0.6));

	auto menuItem_2 = MenuItemImage::create("res/UI/1Menu/load.png", "res/UI/1Menu/loadS.png", CC_CALLBACK_1(MenuLayer::CallMenu, this));
	menuItem_2->setTag(2);
	menuItem_2->setPosition(Vec2(origin.x+winSize.width / 2, origin.y + winSize.height*0.45));

	auto menuItem_3 = MenuItemImage::create("res/UI/1Menu/option.png", "res/UI/1Menu/optionS.png", CC_CALLBACK_1(MenuLayer::CallMenu, this));
	menuItem_3->setTag(3);
	menuItem_3->setPosition(Vec2(origin.x + winSize.width / 2, origin.y + winSize.height*0.3));

	auto menuItem_4 = MenuItemImage::create("res/UI/1Menu/exit.png", "res/UI/1Menu/exitS.png", CC_CALLBACK_1(MenuLayer::CallMenu, this));
	menuItem_4->setTag(4);
	menuItem_4->setPosition(Vec2(origin.x + winSize.width / 2, origin.y + winSize.height*0.15));

	auto menu = Menu::create(menuItem_1,menuItem_2,menuItem_3,menuItem_4,NULL);
	menu->setPosition(Point::ZERO);
	this->addChild(menu);


	


	return true;
}
void  MenuLayer::CallMenu(Ref* pSender) {
	int tag = 1;
	switch (((MenuItem *)pSender)->getTag()) {
	case 1:
	{
		SimpleAudioEngine::sharedEngine()->playEffect("music/click4.wav");
		SimpleAudioEngine::sharedEngine()->playEffect("music/trans1.wav");
		SceneManager::goCreateLayer(tag);

	}
	break;
	case 2:
		SimpleAudioEngine::sharedEngine()->playEffect("music/click4.wav");
		SimpleAudioEngine::sharedEngine()->playEffect("music/trans1.wav");
		SceneManager::goSaveLayer(tag);
	
	break;
	case 3:
	{
		SimpleAudioEngine::sharedEngine()->playEffect("music/click4.wav");
		int tag = 1;
		SceneManager::goSetLayer(tag);
		SimpleAudioEngine::sharedEngine()->playEffect("music/trans1.wav");
	}
	break;
	case 4:
	{
		SimpleAudioEngine::sharedEngine()->playEffect("music/click4.wav");
		Director::getInstance()->end();
		exit(0);
	}
	}
}
