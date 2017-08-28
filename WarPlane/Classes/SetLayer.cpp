#include "SetLayer.h"
#include "ui/CocosGUI.h"
#include "SimpleAudioEngine.h"
using namespace CocosDenshion;
using namespace cocos2d::ui;

int SetLayer::effectState = 1;

bool SetLayer::init()
{	
	auto winSize = Director::getInstance()->getWinSize();
	auto origin = Director::getInstance()->getVisibleOrigin();

	auto _background = Sprite::create("res/UI/1Menu/background.png");
	_background->setPosition(Vec2(origin.x + winSize.width / 2, origin.y + winSize.height / 2));
	auto scale = winSize.width / _background->getContentSize().width;
	_background->setScale(scale);
	this->addChild(_background);

	auto music = Label::createWithSystemFont("Background", "/fonts/AdobeHeitiStd-Regular.ttf", 30);
	music->setPosition(Vec2(winSize.width*0.4, winSize.height*0.6));
	this->addChild(music);

	auto effect = Label::createWithSystemFont("Effect", "/fonts/AdobeHeitiStd-Regular.ttf", 30);
	effect->setPosition(Vec2(winSize.width*0.45, winSize.height*0.5));
	this->addChild(effect);

	auto openBackCir = MenuItemImage::create("res/UI/2Option/open.png", "res/UI/2Option/close.png");
	openBackCir->setUserData((void *)"on");
	auto closeBackCir = MenuItemImage::create("res/UI/2Option/close.png", "res/UI/2Option/open.png");
	closeBackCir->setUserData((void *)"off");
	auto backToggle = MenuItemToggle::createWithCallback(CC_CALLBACK_1(SetLayer::CallBack, this),
		openBackCir, closeBackCir, NULL);
	backToggle->setPosition(Vec2(winSize.width*0.6, winSize.height*0.6));
	backToggle->setTag(3);

	auto openEffectCir = MenuItemImage::create("res/UI/2Option/open.png", "res/UI/2Option/close.png");
	openEffectCir->setUserData((void *)"on");
	auto closeEffectCir = MenuItemImage::create("res/UI/2Option/close.png", "res/UI/2Option/open.png");
	closeEffectCir->setUserData((void *)"off");

	auto effectToggle = MenuItemToggle::createWithCallback(CC_CALLBACK_1(SetLayer::CallBack, this),
		openEffectCir, closeEffectCir, NULL);
	effectToggle->setPosition(Vec2(winSize.width*0.6, winSize.height*0.5));
	effectToggle->setTag(4);


	auto menuItem_1 = MenuItemImage::create("res/UI/2Option/back.png", "res/UI/2Option/backS.png", CC_CALLBACK_1(SetLayer::CallBack, this));
	menuItem_1->setTag(2);
	menuItem_1->setPosition(Vec2(origin.x + winSize.width *0.15, origin.y + winSize.height*0.9));

	auto menuItem_2 = MenuItemImage::create("res/UI/2Option/help.png", "res/UI/2Option/helpS.png", CC_CALLBACK_1(SetLayer::CallBack, this));
	menuItem_2->setTag(1);
	menuItem_2->setPosition(Vec2(origin.x + winSize.width / 2, origin.y + winSize.height*0.2));

	auto menu = Menu::create(backToggle, effectToggle, menuItem_1, menuItem_2, NULL);
	menu->setPosition(Point::ZERO);
	this->addChild(menu);

	return true;
}

int SetLayer::getEffectState() {
	return effectState;
}
void SetLayer::CallBack(Ref *pSender) {
	int tag = ((MenuItem*)pSender)->getTag();
	int transiTimes = 2;
	switch (tag)
	{
	case 1:
		if (effectState == 1) {
			SimpleAudioEngine::getInstance()->playEffect("music/trans1.wav");
		}
		
		SceneManager::goHelpLayer(tag);
           
		break;
	case 2:
		
		if (effectState == 1) {
			SimpleAudioEngine::getInstance()->playEffect("music/trans1.wav");
		}
		
		SceneManager::goMenuLayer(tag,transiTimes);
		break;
	case 3:
		if (SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying())
			SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
		else
			SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
		break;
	case 4:
		MenuItemFont *item = (MenuItemFont*)((MenuItemToggle *)pSender)->getSelectedItem();
		char* musicState = (char*)item->getUserData();
		if (musicState == "off")
			
			effectState = 0;
		else {
			
			effectState = 1;
		}
		break;
	}
}
