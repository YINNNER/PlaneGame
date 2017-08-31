#include "LoadLayer.h"
#include "SimpleAudioEngine.h"
using namespace CocosDenshion;

bool LoadLayer::init() {
	auto winSize = Director::getInstance()->getWinSize();
	auto origin = Director::getInstance()->getVisibleOrigin();

	_background = Sprite::create("res/UI/0aStart/background@3x.png");
	_background->setPosition(Vec2(origin.x + winSize.width/2, origin.y + winSize.height/2));
	auto scale = winSize.width / _background->getContentSize().width;
	_background->setScale(scale);
	this->addChild(_background);

	_logo = Sprite::create("res/UI/0aStart/logo@3x.png");
	_logo->setPosition(Vec2(origin.x + winSize.width /2, origin.y + winSize.height *3/5));
	_logo->setScale(scale);
	//this->addChild(_logo);
    _logo->setOpacity(0);
    _logo->runAction(FadeIn::create(2.0f));
    this->addChild(_logo);
   
	/*
	loadLabel = LabelTTF::create("Loading", "fonts/Anklepan.ttf", 20);
	loadLabel->setPosition(Vec2(winSize.width*0.5, winSize.height*0.5));
	this->addChild(loadLabel);

	percentLabel = LabelTTF::create("0%", "fonts/Anklepan.ttf", 15);
	percentLabel->setPosition(Vec2(winSize.width*0.5, winSize.height*0.45));
	this->addChild(percentLabel);

	auto loadBg = Sprite::create("res/UI/0Loading/loadingBarEmpty.png");
	loadBg->setPosition(Vec2(winSize.width*0.5, winSize.height*0.4));
	this->addChild(loadBg, 1);
	
	loadProgress = ProgressTimer::create(Sprite::
		create("res/UI/0Loading/loadingBarFull.png"));//创建进度条
	loadProgress->setBarChangeRate(Point(1, 0));//设置变化速率
	loadProgress->setType(ProgressTimer::Type::BAR);//设置进度条的类型
	loadProgress->setMidpoint(Point(0, 1));//设置进度的运动方向
	loadProgress->setPosition(Vec2(winSize.width*0.5, winSize.height*0.4));
	loadProgress->setPercentage(0.0f);//设置初始值为0
	this->addChild(loadProgress, 2);

	m_numSp = 19;
	loading();
*/
	loadedImage = 0;
	Director::getInstance()->getTextureCache()->addImageAsync("res/UI/a2SelectLevel/mapScene.png", CC_CALLBACK_1(LoadLayer::loadingCallback, this));
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("res/UI/a1CreatePlayer/createScene.plist");
	SimpleAudioEngine::getInstance()->preloadBackgroundMusic("music/background1.mp3");
	SimpleAudioEngine::getInstance()->preloadEffect("music/trans1.wav");
	SimpleAudioEngine::getInstance()->preloadEffect("music/click8.wav");
	SimpleAudioEngine::getInstance()->preloadEffect("music/click2.wav");
	SimpleAudioEngine::getInstance()->preloadEffect("music/switch01.wav");
	SimpleAudioEngine::getInstance()->preloadEffect("music/stone1.wav");
	SimpleAudioEngine::getInstance()->preloadEffect("music/getSupply03.wav");
	SimpleAudioEngine::getInstance()->preloadEffect("music/bullet3.mp3");
	SimpleAudioEngine::getInstance()->preloadEffect("music/switch01.wav");
	SimpleAudioEngine::getInstance()->preloadBackgroundMusic("music/fight05.mp3");
	SimpleAudioEngine::getInstance()->preloadBackgroundMusic("music/fight08.mp3");
	SimpleAudioEngine::getInstance()->preloadBackgroundMusic("music/fight02.mp3");
	SimpleAudioEngine::getInstance()->playBackgroundMusic("music/background3.mp3",true);
	

	
	scheduleOnce(CC_SCHEDULE_SELECTOR(LoadLayer::onScheduleOnce),3.0f);

	return true;
}

void LoadLayer::onScheduleOnce(float dt){

	int tag = 1;
	int transiTime = 1;
	SceneManager::goMenuLayer(tag,transiTime);

}

void LoadLayer::loadingCallback(Ref * pSender)
{
	switch (loadedImage) {
	case 0:
		SpriteFrameCache::getInstance()->addSpriteFramesWithFile("res/UI/a2SelectLevel/mapScene.plist");
		log("planet1.png already exist");

	}
}
