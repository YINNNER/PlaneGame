
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
	layer->user = userInfo;
	auto action=FadeIn::create(1.0f);
	
	switch (layer->user.getGameLevel())
	{
	case 1:
		layer->level_2->setEnabled(false);
		layer->level_3->setEnabled(false);
		break;
	case 2:
		layer->level_3->setEnabled(false);
		layer->level_2->setOpacity(0);
		layer->level_2->runAction(action);
		
		break;
	case 3:
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

//从菜单第一次进入时创建setScene，之后不管从哪里进入都是用popScene(),setScene进入任何场景都是pushScene()
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
	Director::getInstance()->replaceScene(transition);
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
	layer->user = userInfo;
	scene->addChild(layer);

}
