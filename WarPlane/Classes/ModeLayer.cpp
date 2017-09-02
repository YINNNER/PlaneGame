#include "ModeLayer.h"
#include "SimpleAudioEngine.h"
#include"FightLayer.h"
#include "SetLayer.h"
using namespace CocosDenshion;

bool ModeLayer::init() {

	auto winSize = Director::getInstance()->getWinSize();
	auto origin = Director::getInstance()->getVisibleOrigin();
	auto _background = Sprite::createWithSpriteFrameName("background.png");
	_background->setPosition(Vec2(origin.x + winSize.width / 2, origin.y + winSize.height / 2));
	auto scale = winSize.width / _background->getContentSize().width;
	_background->setScale(scale);
	this->addChild(_background);

	auto menuItem_1 = MenuItemImage::create("res/UI/1Menu/new.png", "res/UI/1Menu/newS.png", CC_CALLBACK_1(ModeLayer::CallBack, this));
	menuItem_1->setTag(31);
	menuItem_1->setPosition(Vec2(origin.x + winSize.width / 2, origin.y + winSize.height*0.6));

	auto menuItem_2 = MenuItemImage::create("res/UI/1Menu/load.png", "res/UI/1Menu/loadS.png", CC_CALLBACK_1(ModeLayer::CallBack, this));
	menuItem_2->setTag(32);
	menuItem_2->setPosition(Vec2(origin.x + winSize.width / 2, origin.y + winSize.height*0.45));

	//ÌøÈë²Ö¿â
	auto repo = MenuItemImage::create("res/UI/a2SelectLevel/repo.png", "res/UI/a2SelectLevel/repoS.png", CC_CALLBACK_1(ModeLayer::CallBack, this));
	repo->setPosition(Vec2(winSize.width*0.9, winSize.height*0.92));
	repo->setScale(0.25);
	repo->setTag(1);
	//·µ»Ø²Ëµ¥
	auto back = MenuItemImage::create("res/UI/a2SelectLevel/back.png", "res/UI/a2SelectLevel/backB.png", CC_CALLBACK_1(ModeLayer::CallBack, this));
	back->setPosition(Vec2(winSize.width*0.1, winSize.height*0.92));
	back->setScale(0.4);
	back->setTag(2);
	//´æ´¢ÓÎÏ·
	auto save = MenuItemImage::create("res/UI/a2SelectLevel/save.png", "res/UI/a2SelectLevel/saveS.png", CC_CALLBACK_1(ModeLayer::CallBack, this));
	save->setPosition(Vec2(winSize.width*0.78, winSize.height*0.92));
	save->setScale(0.25);
	save->setTag(4);

	auto menu = Menu::create(menuItem_1, menuItem_2, NULL);
	menu->setPosition(Point::ZERO);
	this->addChild(menu);
	return true;
}

void ModeLayer::CallBack(Ref * pSender)
{
	int tag = 1;
	int mode = 2;
	switch (((MenuItem *)pSender)->getTag()) {
	case 1:

		if (SetLayer::effectState == 1) {
			SimpleAudioEngine::getInstance()->playEffect("music/trans1.wav");
			SimpleAudioEngine::getInstance()->playEffect("music/click8.wav");
		}
		SceneManager::goRepoLayer(tag, user);

		break;
	case 2:
		if (SetLayer::effectState == 1) {
			SimpleAudioEngine::getInstance()->playEffect("music/trans1.wav");
			SimpleAudioEngine::getInstance()->playEffect("music/click8.wav");
		}

		SceneManager::goMenuLayer(tag);
		break;

	case 31:
	{
		if (SetLayer::effectState == 31) {
			SimpleAudioEngine::getInstance()->playEffect("music/trans1.wav");
			SimpleAudioEngine::sharedEngine()->playEffect("music/click8.wav");
		}
		SceneManager::goMapLayer(tag, user);
	}
	break;
	case 32:
		if (SetLayer::effectState == 32) {
			SimpleAudioEngine::getInstance()->playEffect("music/trans1.wav");
			SimpleAudioEngine::sharedEngine()->playEffect("music/click8.wav");
		}

		SceneManager::goFightLayer(1, user, mode);

		break;
	case 4:
	{
		if (SetLayer::effectState == 1) {
			SimpleAudioEngine::getInstance()->playEffect("music/trans1.wav");
			SimpleAudioEngine::getInstance()->playEffect("music/click8.wav");
		}
		SceneManager::goSaveLayer(2, user);
	}


	}
}