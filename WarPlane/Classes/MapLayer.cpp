#include "MapLayer.h"
#include "SimpleAudioEngine.h"
#include"FightLayer.h"
using namespace CocosDenshion;


bool MapLayer::init() {
	
	auto winSize = Director::getInstance()->getWinSize();
	auto origin = Director::getInstance()->getVisibleOrigin();
	auto _background = Sprite::create("res/UI/1Menu/background.png");
	_background->setPosition(Vec2(origin.x + winSize.width / 2, origin.y + winSize.height / 2));
	auto scale = winSize.width / _background->getContentSize().width;
	_background->setScale(scale);
	this->addChild(_background);

	auto repo = MenuItemImage::create("res/UI/a2SelectLevel/repo.png", "res/UI/a2SelectLevel/repo.png", CC_CALLBACK_1(MapLayer::CallMenu, this));
	repo->setPosition(Vec2(winSize.width*0.9, winSize.height*0.9));
	repo->setScale(0.3);
	repo->setTag(1);

	auto back = MenuItemImage::create("res/UI/a2SelectLevel/back.png", "res/UI/a2SelectLevel/backB.png", CC_CALLBACK_1(MapLayer::CallMenu, this));
	back->setPosition(Vec2(winSize.width*0.15, winSize.height*0.9));
	back->setScale(0.55);
	back->setTag(2);
	
	auto level_1_label = Label::createWithSystemFont("Level 1", "fonts/AdobeHeitiStd-Regular.ttf", 20);
	level_1_label->setPosition(Vec2(winSize.width*0.7, winSize.height*0.1));
	this->addChild(level_1_label);
	

	level_1 = MenuItemImage::create("res/UI/a2SelectLevel/planet1.png", "res/UI/a2SelectLevel/planet1.png",CC_CALLBACK_1(MapLayer::CallMenu, this));
	level_1->setScale(0.5);
	level_1->setAnchorPoint(Vec2(0,0));
	level_1->setPosition(Vec2(Vec2(winSize.width*0.5, winSize.height*0.15)));
	level_1->setTag(31);

	

	auto level_2_label = Label::createWithSystemFont("Level 2", "fonts/AdobeHeitiStd-Regular.ttf", 20);
	level_2_label->setPosition(Vec2(winSize.width*0.2, winSize.height*0.35));
	this->addChild(level_2_label);
	

	level_2 = MenuItemImage::create("res/UI/a2SelectLevel/planet2.png", "res/UI/a2SelectLevel/planet2.png", CC_CALLBACK_1(MapLayer::CallMenu, this));
	level_2->setScale(0.5);
	level_2->setPosition(Vec2(Vec2(winSize.width*0.2, winSize.height*0.5)));
	level_2->setTag(32);

	auto level_3_label = Label::createWithSystemFont("Level 3", "fonts/AdobeHeitiStd-Regular.ttf", 20);
	level_3_label->setPosition(Vec2(winSize.width*0.7, winSize.height*0.55));
	this->addChild(level_3_label);
	
	
	level_3 = MenuItemImage::create("res/UI/a2SelectLevel/planet3.png", "res/UI/a2SelectLevel/planet3.png", CC_CALLBACK_1(MapLayer::CallMenu, this));
	level_3->setScale(0.5);
	level_3->setPosition(Vec2(winSize.width*0.7, winSize.height*0.7));
	level_3->setTag(33);

	Menu*menu = Menu::create(back,repo,level_1,level_2,level_3, NULL);        
	menu->setPosition(Point::ZERO); 
	this->addChild(menu,1);
	/*
	auto listener = EventListenerMouse::create();//´´½¨Êó±ê¼àÌý
	listener->onMouseMove = CC_CALLBACK_1(MapLayer::mouseMove, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, level_1);
	*/
	return true;
}

void MapLayer::CallMenu(Ref * pSender) {
	int tag = ((MenuItem *)pSender)->getTag();
	int times = 1;
	switch (tag)
	{
	case 1:
		SimpleAudioEngine::sharedEngine()->playEffect("music/trans1.wav");
		SceneManager::goRepoLayer(tag);
		break;
	case 2:
		SimpleAudioEngine::sharedEngine()->playEffect("music/trans1.wav");
		
		SceneManager::goMenuLayer(tag, times);
		break;
	case 31:
	{
		if (level_2->getScale() == 0.7f)
			level_2->setScale(0.5);
		if (level_3->getScale() == 0.7f)
			level_3->setScale(0.5);
		level_1->setScale(0.7);
		auto gameScene = Scene::create();
		FightLayer * fightLayer_1 = FightLayer::create();
		fightLayer_1->setPlayer(1);
		gameScene->addChild(fightLayer_1);
		Director::getInstance()->replaceScene(gameScene);
	}break;
	case 32:
	{
		if (level_1->getScale() == 0.7f)
			level_1->setScale(0.5);
		if (level_3->getScale() == 0.7f)
			level_3->setScale(0.5);
		level_2->setScale(0.7);
	}break;
	case 33:
	{
		log("%f", level_1->getScale());
		if (level_1->getScale() == 0.7f)
			level_1->setScale(0.5);
		
		if (level_2->getScale() == 0.7f) 
			level_2->setScale(0.5);
			
		level_3->setScale(0.7);
	}break;
	}
}
/*
void MapLayer::mouseMove(Event *event) {
	auto winSize = Director::getInstance()->getWinSize();
	auto origin = Director::getInstance()->getVisibleOrigin();
	EventMouse *e = (EventMouse *)event;
	CCLOG("%f", e->getCursorY());
	auto locationInNode = level_1->convertToNodeSpace(e->getLocation());
	//Rect rect = Rect(level_1->getAnchorPoint(), level_1->getContentSize());
	Rect rect = Rect(level_1->getPositionX() - level_1->getContentSize().width * level_1->getAnchorPoint().x,
		level_1->getPositionY() - level_1->getContentSize().height * level_1->getAnchorPoint().y,
		getContentSize().width, getContentSize().height);
	if (level_1->getBoundingBox().containsPoint(locationInNode)) {
		level_1->setScale(0.7);
		return;
	}
	level_1->setScale(0.5);
}*/
