#include "MenuLayer.h"
#include "SimpleAudioEngine.h"
using namespace CocosDenshion;


bool MenuLayer::init(){
	
	auto winSize = Director::getInstance()->getWinSize();
	auto origin = Director::getInstance()->getVisibleOrigin();

	
	_background = Sprite::create("res/UI/1Menu/background@3x.png");
	_background->setPosition(Vec2(origin.x + winSize.width / 2, origin.y + winSize.height / 2));
	auto scale = winSize.width / _background->getContentSize().width;
	_background->setScale(scale);
	this->addChild(_background);

	if (SetLayer::backState == 1) {
		if (!SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying()) {
			SimpleAudioEngine::getInstance()->playBackgroundMusic("music/background3.mp3", true);
		}
	}
	
	Sprite *title = Sprite::create("res/UI/1Menu/title@3x.png");
	title->setPosition(Vec2(winSize.width / 2, winSize.height*0.8));
	title->setScale(scale);
	this->addChild(title);

	
	//创建游戏按钮
	auto menuItem_1 = MenuItemImage::create("res/UI/1Menu/new.png","res/UI/1Menu/newS.png",CC_CALLBACK_1(MenuLayer::CallMenu,this));
	menuItem_1->setTag(1);
	menuItem_1->setPosition(Vec2(origin.x+winSize.width / 2, origin.y+winSize.height*0.6));
	
	//载入游戏按钮
	auto menuItem_2 = MenuItemImage::create("res/UI/1Menu/load.png", "res/UI/1Menu/loadS.png", CC_CALLBACK_1(MenuLayer::CallMenu, this));
	menuItem_2->setTag(2);
	menuItem_2->setPosition(Vec2(origin.x+winSize.width / 2, origin.y + winSize.height*0.45));

	//选项按钮
	auto menuItem_3 = MenuItemImage::create("res/UI/1Menu/option.png", "res/UI/1Menu/optionS.png", CC_CALLBACK_1(MenuLayer::CallMenu, this));
	menuItem_3->setTag(3);
	menuItem_3->setPosition(Vec2(origin.x + winSize.width / 2, origin.y + winSize.height*0.3));

	//退出游戏按钮
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
		if (SetLayer::effectState == 1) {
			SimpleAudioEngine::getInstance()->playEffect("music/trans1.wav");
			SimpleAudioEngine::sharedEngine()->playEffect("music/click8.wav");
		}
		
		SceneManager::goCreateLayer(tag);

	}
	break;
	case 2:
		if (SetLayer::effectState == 1) {
			SimpleAudioEngine::getInstance()->playEffect("music/trans1.wav");
			SimpleAudioEngine::sharedEngine()->playEffect("music/click8.wav");
		}
		SceneManager::goSaveLayer(tag);
	
	break;
	case 3:
	{
		if (SetLayer::effectState == 1) {
			SimpleAudioEngine::getInstance()->playEffect("music/trans1.wav");
			SimpleAudioEngine::sharedEngine()->playEffect("music/click8.wav");
		}
		int tag = 1;
		SceneManager::goSetLayer(tag);
	}
	break;
	case 4:
	{
		if (SetLayer::effectState == 1) {
			SimpleAudioEngine::getInstance()->playEffect("music/trans1.wav");
			SimpleAudioEngine::sharedEngine()->playEffect("music/click8.wav");
		}
		Director::getInstance()->end();
		exit(0);
	}
	}
}
