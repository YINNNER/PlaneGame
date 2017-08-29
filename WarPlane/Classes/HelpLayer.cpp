#include "HelpLayer.h"
#include "SimpleAudioEngine.h"
#include "SetLayer.h"
using namespace CocosDenshion;

bool HelpLayer::init() {
	auto winSize = Director::getInstance()->getWinSize();
	auto origin = Director::getInstance()->getVisibleOrigin();

	auto _background = Sprite::create("res/UI/a1CreatePlayer/background.png");
	_background->setPosition(Vec2(origin.x + winSize.width / 2, origin.y + winSize.height / 2));
	auto scale = winSize.width / _background->getContentSize().width;
	_background->setScale(scale);
	this->addChild(_background);

	auto textarea = Sprite::create("res/UI/b1Help/textarea.png");
	textarea->setPosition(Vec2(winSize.width/2,winSize.height/2));
	this->addChild(textarea);
	
	
	auto back = MenuItemImage::create("res/UI/b1Help/back.png", "res/UI/b1Help/backS.png", CC_CALLBACK_1(HelpLayer::CallBack,this));
	back->setPosition(Vec2(winSize.width*0.15, winSize.height*0.9));

	Menu*mu = Menu::create(back, NULL);
	mu->setPosition(Point::ZERO);
	this->addChild(mu);


	return true;
}
void HelpLayer::CallBack(Ref *pSender) {
	int tag = 1;
	if (SetLayer::getEffectState() == 1) {
		SimpleAudioEngine::getInstance()->playEffect("music/trans1.wav");
		SimpleAudioEngine::sharedEngine()->playEffect("music/click8.wav");
	}
	SceneManager::goSetLayer(tag);
	//Director::getInstance()->popScene();
}