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
	//_logo->setScale(2);
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

	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("res/UI/a1CreatePlayer/createScene.plist");
	SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("music/background1.mp3");
	SimpleAudioEngine::sharedEngine()->preloadEffect("music/trans1.wav");
	
	SimpleAudioEngine::sharedEngine()->playBackgroundMusic("music/background3.mp3",true);
	scheduleOnce(CC_SCHEDULE_SELECTOR(LoadLayer::onScheduleOnce),3.0f);

	return true;
}

void LoadLayer::onScheduleOnce(float dt){

	int tag = 1;
	int transiTime = 1;
	SceneManager::goMenuLayer(tag,transiTime);

}
