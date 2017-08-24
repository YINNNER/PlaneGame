#include "LoadLayer.h"


bool LoadLayer::init() {
	auto winSize = Director::getInstance()->getWinSize();
	auto origin = Director::getInstance()->getVisibleOrigin();

	_background = Sprite::create("/res/UI/0aStart/background.png");
	_background->setPosition(Vec2(origin.x + winSize.width/2, origin.y + winSize.height/2));
	auto scale = winSize.width / _background->getContentSize().width;
	_background->setScale(scale);
	this->addChild(_background);

	_logo = Sprite::create("/res/UI/0aStart/logo.png");
	_logo->setPosition(Vec2(origin.x + winSize.width *0.6, origin.y + winSize.height *3/5));
	//_logo->setScale(2);
	this->addChild(_logo);


	
	scheduleOnce(CC_SCHEDULE_SELECTOR(LoadLayer::onScheduleOnce),0.1f);
	return true;
}

void LoadLayer::onScheduleOnce(float dt){
	/*
	auto menuScene = Scene::create();
	MenuLayer *layer = MenuLayer::create();
	menuScene->addChild(layer);
	Director::getInstance()->replaceScene(menuScene);*/
	int tag = 1;
	SceneManager::goMenuLayer(tag);

}
