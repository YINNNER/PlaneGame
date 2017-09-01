#include "LoadLayer.h"
#include "SimpleAudioEngine.h"
using namespace CocosDenshion;

bool LoadLayer::init() {
	auto winSize = Director::getInstance()->getWinSize();
	auto origin = Director::getInstance()->getVisibleOrigin();

	_background = Sprite::create("res/UI/0aStart/background.png");
	_background->setPosition(Vec2(origin.x + winSize.width/2, origin.y + winSize.height/2));
	auto scale = winSize.width / _background->getContentSize().width;
	_background->setScale(scale);
	this->addChild(_background);

	_logo = Sprite::create("res/UI/0aStart/logo.png");
	_logo->setPosition(Vec2(origin.x + winSize.width /2, origin.y + winSize.height *3/5));
	_logo->setScale(scale);
	//this->addChild(_logo);
    _logo->setOpacity(0);
    _logo->runAction(FadeIn::create(2.0f));
    this->addChild(_logo);
   
	//Ô¤¼ÓÔØ×ÊÔ´
	loadedImage = 0;
	Director::getInstance()->getTextureCache()->addImageAsync("res/UI/a2SelectLevel/MapScene.png", CC_CALLBACK_1(LoadLayer::loadingCallback, this));
	Director::getInstance()->getTextureCache()->addImageAsync("res/game.png", CC_CALLBACK_1(LoadLayer::loadingCallback, this));
	Director::getInstance()->getTextureCache()->addImageAsync("res/UI/plane_parts/planeParts.png", CC_CALLBACK_1(LoadLayer::loadingCallback, this));
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("res/UI/a1CreatePlayer/createScene.plist");
	SimpleAudioEngine::getInstance()->preloadEffect("music/trans1.wav");
	SimpleAudioEngine::getInstance()->preloadEffect("music/click8.wav");
	SimpleAudioEngine::getInstance()->preloadEffect("music/click2.wav");
	SimpleAudioEngine::getInstance()->preloadEffect("music/switch01.wav");
	SimpleAudioEngine::getInstance()->preloadEffect("music/stone1.wav");
	SimpleAudioEngine::getInstance()->preloadEffect("music/getSupply03.wav");
	SimpleAudioEngine::getInstance()->preloadEffect("music/bullet3.mp3");
	SimpleAudioEngine::getInstance()->preloadEffect("music/switch01.wav");
	SimpleAudioEngine::getInstance()->preloadEffect("music/hiding1.mp3");
	SimpleAudioEngine::getInstance()->preloadEffect("music/skill5.wav");
	SimpleAudioEngine::getInstance()->preloadEffect("music/bomb3.wav");
	SimpleAudioEngine::getInstance()->preloadEffect("music/skill2.wav");
	SimpleAudioEngine::getInstance()->preloadEffect("music/skill4.wav");
	SimpleAudioEngine::getInstance()->preloadEffect("music/bomb4.wav");
	SimpleAudioEngine::getInstance()->preloadEffect("music/hited2.wav");
	SimpleAudioEngine::getInstance()->preloadEffect("music/skill4.wav");
	SimpleAudioEngine::getInstance()->preloadEffect("music/lose1.wav");
	SimpleAudioEngine::getInstance()->preloadEffect("music/win02.mp3");
	SimpleAudioEngine::getInstance()->preloadBackgroundMusic("music/fight05.mp3");
	SimpleAudioEngine::getInstance()->preloadBackgroundMusic("music/fight08.mp3");
	SimpleAudioEngine::getInstance()->preloadBackgroundMusic("music/fight04.mp3");
	SimpleAudioEngine::getInstance()->playBackgroundMusic("music/background3.mp3",true);

	

	
	scheduleOnce(CC_SCHEDULE_SELECTOR(LoadLayer::onScheduleOnce),3.0f);

	return true;
}

void LoadLayer::onScheduleOnce(float dt){

	int tag = 1;
	int transiTime = 1;
	SceneManager::goMenuLayer(tag);

}

void LoadLayer::loadingCallback(Ref * pSender)
{
	switch (loadedImage) {
	case 0:
		SpriteFrameCache::getInstance()->addSpriteFramesWithFile("res/UI/a2SelectLevel/MapScene.plist");
		log("planet1.png already exist");
		loadedImage++;
		break;
	case 1:
		SpriteFrameCache::getInstance()->addSpriteFramesWithFile("res/game.plist");
		log("game.png already exist");
		loadedImage++;
		break;
	case 2:
		SpriteFrameCache::getInstance()->addSpriteFramesWithFile("res/UI/plane_parts/planeParts.plist");
		log("planeParts.png already exist");
		loadedImage++;
	
	}
}
