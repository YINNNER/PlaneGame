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

	


	auto repo = MenuItemImage::create("res/UI/a2SelectLevel/repo.png", "res/UI/a2SelectLevel/repoS.png", CC_CALLBACK_1(MapLayer::CallMenu, this));
	repo->setPosition(Vec2(winSize.width*0.9, winSize.height*0.92));
	repo->setScale(0.25);
	repo->setTag(1);

	auto back = MenuItemImage::create("res/UI/a2SelectLevel/back.png", "res/UI/a2SelectLevel/backB.png", CC_CALLBACK_1(MapLayer::CallMenu, this));
	back->setPosition(Vec2(winSize.width*0.1, winSize.height*0.92));
	back->setScale(0.4);
	back->setTag(2);

	auto save = MenuItemImage::create("res/UI/a2SelectLevel/save.png", "res/UI/a2SelectLevel/saveS.png", CC_CALLBACK_1(MapLayer::CallMenu, this));
	save->setPosition(Vec2(winSize.width*0.78, winSize.height*0.92));
	save->setScale(0.25);
	save->setTag(4);
	
	auto level_1_label = Label::createWithSystemFont("Level 1", "fonts/AdobeHeitiStd-Regular.ttf", 20);
	level_1_label->setPosition(Vec2(winSize.width*0.7, winSize.height*0.1));
	this->addChild(level_1_label);
	

	level_1 = MenuItemImage::create("res/UI/a2SelectLevel/planet1.png", "res/UI/a2SelectLevel/planet1.png",CC_CALLBACK_1(MapLayer::CallMenu, this));
	level_1->setScale(0.5);
	level_1->setAnchorPoint(Vec2(0,0));
	level_1->setPosition(Vec2(winSize.width*0.5, winSize.height*0.15));
	level_1->setTag(31);

	

	auto level_2_label = Label::createWithSystemFont("Level 2", "fonts/AdobeHeitiStd-Regular.ttf", 20);
	level_2_label->setPosition(Vec2(winSize.width*0.2, winSize.height*0.35));
	this->addChild(level_2_label);
	

	level_2 = MenuItemImage::create("res/UI/a2SelectLevel/planet2.png", "res/UI/a2SelectLevel/planet2.png", "res/UI/a2SelectLevel/planet2Forbidden.png",CC_CALLBACK_1(MapLayer::CallMenu, this));
	level_2->setScale(0.5);
	level_2->setPosition(Vec2(winSize.width*0.2, winSize.height*0.5));
	level_2->setTag(32);

	auto level_3_label = Label::createWithSystemFont("Level 3", "fonts/AdobeHeitiStd-Regular.ttf", 20);
	level_3_label->setPosition(Vec2(winSize.width*0.7, winSize.height*0.55));
	this->addChild(level_3_label);
	
	
	level_3 = MenuItemImage::create("res/UI/a2SelectLevel/planet3.png", "res/UI/a2SelectLevel/planet3.png", "res/UI/a2SelectLevel/planet3Forbidden.png",CC_CALLBACK_1(MapLayer::CallMenu, this));
	level_3->setScale(0.5);
	level_3->setPosition(Vec2(winSize.width*0.7, winSize.height*0.7));
	level_3->setTag(33);

	Menu*menu = Menu::create(back,repo,save,level_1,level_2,level_3, NULL);        
	menu->setPosition(Point::ZERO); 
	this->addChild(menu, 1);
	
	
	



	
	/*
	auto listener = EventListenerMouse::create();//����������
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
		SimpleAudioEngine::sharedEngine()->playEffect("music/click2.wav");
		SimpleAudioEngine::sharedEngine()->playEffect("music/trans1.wav");
		SceneManager::goRepoLayer(tag);
		break;
	case 2:
		SimpleAudioEngine::sharedEngine()->playEffect("music/click2.wav");
		SimpleAudioEngine::sharedEngine()->playEffect("music/trans1.wav");
		
		SceneManager::goMenuLayer(tag,times);
		break;
	case 31:
	{
		SimpleAudioEngine::sharedEngine()->playEffect("music/click2.wav");
		auto gameScene = Scene::create();
		FightLayer * fightLayer_1 = FightLayer::create();
		fightLayer_1->setPlayer(1);
		gameScene->addChild(fightLayer_1);
		auto transit = TransitionSlideInR::create(0.5f, gameScene);
		Director::getInstance()->replaceScene(transit);
	}break;
	case 32:
	{
		SimpleAudioEngine::sharedEngine()->playEffect("music/click4.wav");
		auto gameScene = Scene::create();
		FightLayer * fightLayer_1 = FightLayer::create();
		fightLayer_1->setPlayer(1);
		gameScene->addChild(fightLayer_1);
		auto transit = TransitionSlideInR::create(0.5f, gameScene);
		Director::getInstance()->replaceScene(transit);
	}break;
	case 33:
	{
		SimpleAudioEngine::sharedEngine()->playEffect("music/click4.wav");
		auto gameScene = Scene::create();
		FightLayer * fightLayer_1 = FightLayer::create();
		fightLayer_1->setPlayer(1);
		gameScene->addChild(fightLayer_1);
		auto transit= TransitionSlideInR::create(0.5f, gameScene);
		Director::getInstance()->replaceScene(transit);
	}break;
	case 4:
	{
		SimpleAudioEngine::sharedEngine()->playEffect("music/click4.wav");
		SceneManager::goSaveLayer(2,user);
	}
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
