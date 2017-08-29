
#include "SceneManager.h"
#include"FightLayer.h"
#include "LoadLayer.h"
#include "MenuLayer.h"
#include "RepoLayer.h"
#include "FightLayer.h"
using namespace experimental;

USING_NS_CC;

auto winSize = Director::getInstance()->getWinSize();
auto origin = Director::getInstance()->getVisibleOrigin();

void SceneManager::CreateLoadScene() {
	loadScene = Scene::create();
	LoadLayer *layer = LoadLayer::create();
	loadScene->addChild(layer);


}
void SceneManager::goMenuLayer(int tag,int times) {
	//static int times = 1;
	
	auto menuScene = Scene::create();
	MenuLayer *layer = MenuLayer::create();
	menuScene->addChild(layer);
	if (times == 1) {
		//times++;
		if (tag == 1) {
			
			auto transition = TransitionFade::create(2.0f, menuScene);
			Director::getInstance()->replaceScene(transition);
			
		}
		else {
			auto transition = TransitionMoveInL::create(0.2f, menuScene);
			Director::getInstance()->replaceScene(transition);
		}

	}
	else {
		Director::getInstance()->pushScene(menuScene);
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

    //鍒ゆ柇鎴樻満绫诲瀷锛屽苟鏍规嵁涓嶅悓绫诲瀷鍐嶆鍒濆鍖栨垬鏈哄睘鎬?
    if (userInfo.getPlaneType()==2) {
        userInfo.setAtk(150);
        userInfo.setSpd(50);
        userInfo.setHp(300);
        userInfo.setMp(100);

    }
    else if(userInfo.getPlaneType()==3){
        userInfo.setAtk(130);
        userInfo.setSpd(60);
        userInfo.setHp(300);
        userInfo.setMp(400);

    }
    else ;
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

//楼鈥濃墹脌碌鈥⒙碘亜鈥溌ヅ捨┞幻幝犅甭ヂノ┞畇etScene拢篓梅脝鈭涒墹陋蟺鈥孤モ�澠捚捖棵斘┞幻庘垈潞聽芦鈥濃垰popScene(),setScene惟炉禄脦禄艗鈭掆墺掳忙鈭炩垈潞聽芦pushScene()
void SceneManager::goSetLayer(int tag) {
	auto setScene = Scene::create();
	auto layer = SetLayer::create();
	setScene->addChild(layer);
	/*
	if (tag == 1) {
		auto transition = TransitionMoveInR::create(0.2f, setScene);
		Director::getInstance()->replaceScene(transition);
	}
	else {
		auto transition = TransitionMoveInL::create(0.2f, setScene);
		Director::getInstance()->replaceScene(transition);
	}
	*/
	/*static int times = 1;
	if (times == 1) {*/
	/*Scene* setScene = Scene::create();
	SetLayer * layer = SetLayer::create();
	setScene->addChild(layer);*/
	auto transition = TransitionMoveInR::create(0.2f, setScene);
	Director::getInstance()->pushScene(transition);
	/*	times++;
	}
	else {
		Director::getInstance()->popScene();
	}*/

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

void SceneManager::goFightLayer(UserInfo &userInfo) {
	auto scene = Scene::create();
	FightLayer *layer = FightLayer::create();

	scene->addChild(layer);

}
