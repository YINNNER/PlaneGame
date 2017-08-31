
#include "SceneManager.h"
#include"FightLayer.h"
#include "LoadLayer.h"
#include "MenuLayer.h"
#include "RepoLayer.h"
#include "FightLayer.h"
#include "SimpleAudioEngine.h"
using namespace CocosDenshion;
using namespace experimental;

USING_NS_CC;

auto winSize = Director::getInstance()->getWinSize();
auto origin = Director::getInstance()->getVisibleOrigin();

void SceneManager::CreateLoadScene() {
	loadScene = Scene::create();
	LoadLayer *layer = LoadLayer::create();
	loadScene->addChild(layer);


}
void SceneManager::goMenuLayer(int tag) {

	auto menuScene = Scene::create();
	MenuLayer *layer = MenuLayer::create();
	menuScene->addChild(layer);
	if (tag == 1) {

		auto transition = TransitionFade::create(2.0f, menuScene);
		Director::getInstance()->replaceScene(transition);

	}
	else {
		auto transition = TransitionMoveInL::create(0.2f, menuScene);
		Director::getInstance()->replaceScene(transition);
	}

}

void SceneManager::goCreateLayer(int tag) {
	auto createScene = Scene::create();
	CreateLayer *layer = CreateLayer::create();

	createScene->addChild(layer);
	if (tag == 1) {
		auto transition = TransitionMoveInR::create(0.2f, createScene);
		Director::getInstance()->replaceScene(transition);
	}
	else {
		auto transition = TransitionMoveInL::create(0.2f, createScene);
		Director::getInstance()->replaceScene(transition);

	}
}

void SceneManager::goMapLayer(int tag, UserInfo &userInfo) {
	auto mapScene = Scene::create();
	auto layer = MapLayer::create();

    //判断是否是从创建角色进入，若是飞机类型为2或3，则需改变初始值
	if (userInfo.getExp()==0&&userInfo.getGameLevel()==1)
	{


    if (userInfo.getPlaneType()==2) {
        userInfo.setAtk(15);
        userInfo.setSpd(5);
        userInfo.setHp(16);
        userInfo.setMp(10);
		
    }
    else if(userInfo.getPlaneType()==3){
        userInfo.setAtk(13);
        userInfo.setSpd(6);
        userInfo.setHp(20);
        userInfo.setMp(10);
    }

    else ;
	}
    layer->user = userInfo;
	
	auto action=FadeIn::create(1.0f);//星球渐变出现的特效
	auto planeAction = MoveTo::create(1.0f, Vec2(layer->level_2->getPosition().x+layer->level_2->getContentSize().width*0.25,
		layer->level_2->getPosition().y));//飞机从第一关移动到第二关
	auto planeAction_2 = MoveTo::create(1.0f, Vec2(layer->level_3->getPosition().x-50,
		layer->level_3->getPosition().y-50));//飞机从第二关移动到第三关
	auto planeFadeIn = FadeIn::create(1.0f);

	auto levelAction_1 = MoveBy::create(0.8f, Vec2(0, 10));
	MoveBy *levelAction_back = levelAction_1->reverse();
	auto repeat = RepeatForever::create(Sequence::create(levelAction_1, levelAction_back, NULL));

	

	
	//判断点击的关卡
	switch (layer->user.getGameLevel())
	{
	case 1:
		layer->level_1->runAction(repeat);
		layer->plane->runAction(planeFadeIn);
		layer->level_2->setEnabled(false);
		layer->level_3->setEnabled(false);
		break;
	case 2:
		layer->level_2->runAction(repeat);
		layer->plane->setRotation(340);
		layer->plane->runAction(Sequence::create( planeAction, NULL));
		layer->level_3->setEnabled(false);
		layer->level_2->setOpacity(0);
		layer->level_2->runAction(action);
		
		break;
	case 3:
		layer->level_3->runAction(repeat);
		layer->plane->setPosition(Vec2(layer->level_2->getPosition().x + layer->level_2->getContentSize().width*0.25,
			layer->level_2->getPosition().y));
		layer->plane->setRotation(60);
		layer->plane->runAction(Sequence::create(planeAction_2, NULL));
		layer->level_3->setOpacity(0);
		layer->level_3->runAction(action);
		
		break;
	}
	mapScene->addChild(layer);
	if (tag == 1) {
		auto transition = TransitionMoveInR::create(0.2f, mapScene);
		Director::getInstance()->replaceScene(transition);
	}
	else {
		auto transition = TransitionMoveInL::create(0.2f, mapScene);
		Director::getInstance()->replaceScene(transition);

	}
}

void SceneManager::goSaveLayer(int tag, UserInfo &userInfo) {
	auto saveScene = Scene::create();
	auto layer = SaveLayer::create();
	layer->times = tag;
	layer->user = userInfo;
	saveScene->addChild(layer);
	if (tag == 1) {
		auto transition = TransitionMoveInR::create(0.2f, saveScene);
		Director::getInstance()->replaceScene(transition);
	}
	else {
		auto transition = TransitionMoveInL::create(0.2f, saveScene);
		Director::getInstance()->replaceScene(transition);

	}


}

void SceneManager::goSaveLayer(int tag) {
	auto saveScene = Scene::create();
	auto layer = SaveLayer::create();
	layer->times = tag;
	saveScene->addChild(layer);
	if (tag == 1) {
		auto transition = TransitionMoveInR::create(0.2f, saveScene);
		Director::getInstance()->replaceScene(transition);
	}
	else {
		auto transition = TransitionMoveInL::create(0.2f, saveScene);
		Director::getInstance()->replaceScene(transition);

	}


}

void SceneManager::goHelpLayer(int tag) {
	auto helpScene = Scene::create();
	auto layer = HelpLayer::create();
	helpScene->addChild(layer);
	if (tag == 1) {
		auto transition = TransitionMoveInR::create(0.2f, helpScene);
		Director::getInstance()->pushScene(transition);
	}
	else {
		auto transition = TransitionMoveInL::create(0.2f, helpScene);
		Director::getInstance()->pushScene(transition);

	}
}

void SceneManager::goSetLayer(int tag) {
	auto setScene = Scene::create();
	auto layer = SetLayer::create();
	setScene->addChild(layer);
	
	auto transition = TransitionMoveInR::create(0.2f, setScene);
	Director::getInstance()->pushScene(transition);


}

void SceneManager::goRepoLayer(int tag,UserInfo &userInfo) {
	auto repoScene = Scene::create();
    auto layer = new RepoLayer();
    layer->user=userInfo;
    layer->init();
	repoScene->addChild(layer);

	if (tag == 1) {
		auto transition = TransitionMoveInR::create(0.2f, repoScene);
		Director::getInstance()->replaceScene(transition);
	}
	else {
		auto transition = TransitionMoveInL::create(0.2f, repoScene);
		Director::getInstance()->replaceScene(transition);

	}

}

void SceneManager::goFightLayer(int level,UserInfo &userInfo) {
	auto gameScene = Scene::create();
	FightLayer * fightLayer_1 = FightLayer::create();
	fightLayer_1->setPlayer(userInfo);
	fightLayer_1->user = userInfo;
	fightLayer_1->getGameLevel(level);
	gameScene->addChild(fightLayer_1);
	auto transit = TransitionSlideInR::create(0.5f, gameScene);
	SimpleAudioEngine::getInstance()->stopBackgroundMusic();
	Director::getInstance()->replaceScene(transit);

}
