#include "MapLayer.h"
#include "SimpleAudioEngine.h"
#include"FightLayer.h"
using namespace CocosDenshion;

bool MapLayer::init() {

	auto winSize = Director::getInstance()->getWinSize();
	auto origin = Director::getInstance()->getVisibleOrigin();
	auto _background = Sprite::createWithSpriteFrameName("background.png");
	_background->setPosition(Vec2(origin.x + winSize.width / 2, origin.y + winSize.height / 2));
	auto scale = winSize.width / _background->getContentSize().width;
	_background->setScale(scale);
	this->addChild(_background);

	if (SetLayer::backState == 1) {
		if (!SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying()) {
			SimpleAudioEngine::getInstance()->playBackgroundMusic("music/background3.mp3", true);
		}
	}

	//小飞机移动动画
	auto animation = Animation::create();
	for (int i = 1; i <= 3; i++) {
		char szName[100] = { 0 };
		sprintf(szName, "res/UI/a2SelectLevel/%d.png", i);
		animation->addSpriteFrameWithFile(szName);
	}
	animation->setDelayPerUnit(0.1f);
	animation->setRestoreOriginalFrame(true);
	auto spray = Animate::create(animation);
	RepeatForever *sprayForever = RepeatForever::create(spray);
	

	//跳入仓库
	auto repo = MenuItemImage::create("res/UI/a2SelectLevel/repo.png", "res/UI/a2SelectLevel/repoS.png", CC_CALLBACK_1(MapLayer::CallMenu, this));
	repo->setPosition(Vec2(winSize.width*0.9, winSize.height*0.92));
	repo->setScale(0.25);
	repo->setTag(1);
	//返回菜单
	auto back = MenuItemImage::create("res/UI/a2SelectLevel/back.png", "res/UI/a2SelectLevel/backB.png", CC_CALLBACK_1(MapLayer::CallMenu, this));
	back->setPosition(Vec2(winSize.width*0.1, winSize.height*0.92));
	back->setScale(0.4);
	back->setTag(2);
	//存储游戏
	auto save = MenuItemImage::create("res/UI/a2SelectLevel/save.png", "res/UI/a2SelectLevel/saveS.png", CC_CALLBACK_1(MapLayer::CallMenu, this));
	save->setPosition(Vec2(winSize.width*0.78, winSize.height*0.92));
	save->setScale(0.25);
	save->setTag(4);
	//第一关文字显示
	//auto level_1_label = Label::createWithSystemFont("Level 1", "fonts/AdobeHeitiStd-Regular.ttf", 20);
    auto level_1_label = Sprite::create("res/UI/a2SelectLevel/firstLevel.png");
    level_1_label->setScale(0.5);
	level_1_label->setPosition(Vec2(winSize.width*0.7, winSize.height*0.1));
	this->addChild(level_1_label);
	
	level_1Normal = Sprite::createWithSpriteFrameName("planet1.png");
	level_1Selected = Sprite::createWithSpriteFrameName("planet1.png");

	level_1 = MenuItemSprite::create(level_1Normal, level_1Selected,CC_CALLBACK_1(MapLayer::CallMenu, this));
	level_1->setScale(0.5);
	level_1->setAnchorPoint(Vec2(0,0));
	level_1->setPosition(Vec2(winSize.width*0.5, winSize.height*0.15));
	level_1->setTag(31);

	
    auto level_2_label = Sprite::create("res/UI/a2SelectLevel/secondLevel.png");
    level_2_label->setScale(0.5);
	level_2_label->setPosition(Vec2(winSize.width*0.2, winSize.height*0.35));
	this->addChild(level_2_label);
	
	
	level_2Normal = Sprite::createWithSpriteFrameName("planet2.png");
	level_2Selected = Sprite::createWithSpriteFrameName("planet2.png");
	level_2Forbidden = Sprite::createWithSpriteFrameName("planet2Forbidden.png");

	level_2 = MenuItemSprite::create(level_2Normal, level_2Selected, level_2Forbidden, CC_CALLBACK_1(MapLayer::CallMenu, this));
	level_2->setScale(0.5);
	level_2->setPosition(Vec2(winSize.width*0.2, winSize.height*0.5));
	level_2->setTag(32);


    auto level_3_label = Sprite::create("res/UI/a2SelectLevel/thirdLevel.png");
    level_3_label->setScale(0.5);
	level_3_label->setPosition(Vec2(winSize.width*0.7, winSize.height*0.55));
	this->addChild(level_3_label);
	
	level_3Normal = Sprite::createWithSpriteFrameName("planet3.png");
	level_1Selected = Sprite::createWithSpriteFrameName("planet1.png");
	level_3Forbidden = Sprite::createWithSpriteFrameName("planet3Forbidden.png");

	level_3 = MenuItemSprite::create(level_3Normal, level_3Selected, level_3Forbidden, CC_CALLBACK_1(MapLayer::CallMenu, this));
	level_3->setScale(0.5);
	level_3->setPosition(Vec2(winSize.width*0.7, winSize.height*0.7));
	level_3->setTag(33);

	Menu*menu = Menu::create(back,repo,save,level_1,level_2,level_3, NULL);        
	menu->setPosition(Point::ZERO); 
	this->addChild(menu, 1);
	
	//移动的小飞机
	plane = Sprite::createWithSpriteFrameName("plane01.png");
	plane->setPosition(Vec2(level_1->getPosition().x,level_1->getPosition().y));
	plane->setScale(0.5);
	plane->setRotation(60);
	//plane->setOpacity(0);
	plane->runAction(sprayForever);
	this->addChild(plane,2);

	return true;
}

void MapLayer::CallMenu(Ref * pSender) {
	int tag = ((MenuItem *)pSender)->getTag();
	int times = 1;
	switch (tag)
	{
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
		if (SetLayer::effectState == 1) {
			SimpleAudioEngine::getInstance()->playEffect("music/click2.wav");
		}
		chooseLevel = 1;
		SceneManager::goFightLayer(chooseLevel,user);
	}break;
	case 32:
	{
		if (SetLayer::effectState == 1) {
			
			SimpleAudioEngine::getInstance()->playEffect("music/click2.wav");
		}
		chooseLevel = 2;
		SceneManager::goFightLayer(chooseLevel,user);
	}break;
	case 33:
	{
		if (SetLayer::effectState == 1) {
			SimpleAudioEngine::getInstance()->playEffect("music/click2.wav");
		}
		chooseLevel = 3;
		SceneManager::goFightLayer(chooseLevel,user);
	}break;
	case 4:
	{
		if (SetLayer::effectState == 1) {
			SimpleAudioEngine::getInstance()->playEffect("music/trans1.wav");
			SimpleAudioEngine::getInstance()->playEffect("music/click8.wav");
		}
		SceneManager::goSaveLayer(2,user);
	}
	}
}
