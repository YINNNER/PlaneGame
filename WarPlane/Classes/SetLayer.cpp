#include "SetLayer.h"
#include "ui/CocosGUI.h"
#include "SimpleAudioEngine.h"
using namespace CocosDenshion;
using namespace cocos2d::ui;



bool SetLayer::init()
{	
	auto winSize = Director::getInstance()->getWinSize();
	auto origin = Director::getInstance()->getVisibleOrigin();

	auto _background = Sprite::create("/res/UI/a2SelectLevel/background.png");
	_background->setPosition(Vec2(origin.x + winSize.width / 2, origin.y + winSize.height / 2));
	auto scale = winSize.width / _background->getContentSize().width;
	_background->setScale(scale);
	this->addChild(_background);

	auto music = Label::createWithSystemFont("Background", "/fonts/AdobeHeitiStd-Regular.ttf", 30);
	music->setPosition(Vec2(winSize.width*0.17, winSize.height*0.6));
	this->addChild(music);

	auto effect = Label::createWithSystemFont("Effect", "/fonts/AdobeHeitiStd-Regular.ttf", 30);
	effect->setPosition(Vec2(winSize.width*0.2, winSize.height*0.5));
	this->addChild(effect);

	backBar = Sprite::create("/res/UI/2Option/loadingBar.png");
	backBar->setPosition(Vec2(winSize.width*0.6, winSize.height*0.6));
	this->addChild(backBar);

	


	effectBar = Sprite::create("/res/UI/2Option/loadingBar.png");
	effectBar->setPosition(Vec2(winSize.width*0.6, winSize.height*0.5));
	this->addChild(effectBar);

	backCir = Sprite::create("/res/UI/2Option/circle.png");
	backCir->setPosition(Vec2(winSize.width*0.4, winSize.height*0.6));
	this->addChild(backCir);
	effectCir = Sprite::create("/res/UI/2Option/circle.png");
	effectCir->setPosition(Vec2(winSize.width*0.4, winSize.height*0.5));
	this->addChild(effectCir);

	auto menuItem_1 = MenuItemImage::create("/res/UI/2Option/back.png", "/res/UI/2Option/backS.png", CC_CALLBACK_1(SetLayer::CallBack, this));
	menuItem_1->setTag(2);
	menuItem_1->setPosition(Vec2(origin.x + winSize.width *0.15, origin.y + winSize.height*0.9));

	auto menuItem_2 = MenuItemImage::create("/res/UI/2Option/help.png", "/res/UI/2Option/helpS.png", CC_CALLBACK_1(SetLayer::CallBack, this));
	menuItem_2->setTag(1);
	menuItem_2->setPosition(Vec2(origin.x + winSize.width / 2, origin.y + winSize.height*0.2));

	auto menu = Menu::create(menuItem_1, menuItem_2,  NULL);
	menu->setPosition(Point::ZERO);
	this->addChild(menu);

	
	changeVolumn();

	return true;
}


void SetLayer::CallBack(Ref *pSender) {
	int tag = ((MenuItem*)pSender)->getTag();
	switch (tag)
	{
	case 1:
		SimpleAudioEngine::sharedEngine()->playEffect("/music/trans1.wav");
		SceneManager::goHelpLayer(tag);
		break;
	case 2:
		SimpleAudioEngine::sharedEngine()->playEffect("/music/trans1.wav");
		SceneManager::goMenuLayer(tag);
		break;
	default:
		break;
	}
}

void SetLayer::changeVolumn() {
	auto listener = EventListenerTouchOneByOne::create();

	listener->setSwallowTouches(true);

	listener->onTouchBegan = CC_CALLBACK_2(SetLayer::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(SetLayer::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(SetLayer::onTouchEnded, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, backCir);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener->clone(), effectCir);
	
	Size size = Director::sharedDirector()->getWinSize();


}
void SetLayer::onTouchMoved(Touch *touch, Event *unused_event) {
	auto target = static_cast<Sprite*>(unused_event->getCurrentTarget());
	auto min = backBar->getPosition().x - backBar->getContentSize().width / 2;
	auto max = backBar->getPosition().x + backBar->getContentSize().width / 2;
	/*
	if (touch->getLocation().x >= min&&touch->getLocation().x <=max&&touch->getLocation().y==target->getPosition().y) {
		target->setPosition(target->getPosition().x + touch->getDelta().x, target->getPosition().y);
	}

	else if (touch->getLocation().x > max&&touch->getLocation().y) {
		target->setPosition(max,target->getPosition().y);
	}
	else if (touch->getLocation().x <min) {
		target->setPosition(min, target->getPosition().y);
	}*/
	Vec2 locationInNode = effectBar->convertToNodeSpace(touch->getLocation());
	Vec2 locationInWorld = touch->getLocation();
	Size s = effectBar->getContentSize();
	log("sprite began... x = %f, y = %f", s.width, s.height);
	Rect rect = Rect(0, 0, s.width, s.height);
	if (rect.containsPoint(locationInNode)) {
		target->setPosition(Vec2(touch->getLocation().x, target->getPosition().y));
		auto scale = (target->getPosition().x - effectBar->getPosition().x) / effectBar->getContentSize().width;
	}

}

bool SetLayer::onTouchBegan(Touch *touch, Event *unused_event) {
	auto target = static_cast<Sprite*>(unused_event->getCurrentTarget());
	Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());
	Size s = target->getContentSize();
	log("sprite began... x = %f, y = %f", s.width,s.height);
	Rect rect = Rect(0, 0, s.width, s.height);

	// µã»÷·¶Î§ÅÐ¶Ï¼ì²â
	if (rect.containsPoint(locationInNode))
	{
		log("sprite began... x = %f, y = %f", locationInNode.x, locationInNode.y);
		target->setOpacity(180);

		return true;
	}

	return true;
}

void SetLayer::onTouchEnded(Touch *touch, Event *unused_event) {
	auto target = static_cast<Sprite*>(unused_event->getCurrentTarget());
	target->setOpacity(255);
}

