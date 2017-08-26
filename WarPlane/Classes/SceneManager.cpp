
#include "SceneManager.h"
#include "AudioEngine.h"
#include"FightLayer.h"
#include "LoadLayer.h"
#include "MenuLayer.h"
#include "RepoLayer.h"
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

void SceneManager::goMapLayer(int tag) {
	auto mapScene = Scene::create();
	auto layer = MapLayer::create();

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

void SceneManager::goSaveLayer(int tag) {
	auto saveScene = Scene::create();
	auto layer = SaveLayer::create();
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
	static int times = 1;
	if (times == 1) {
		auto setScene = Scene::create();
		auto layer = SetLayer::create();
		setScene->addChild(layer);
		auto transition = TransitionMoveInR::create(0.2f, setScene);
		Director::getInstance()->replaceScene(transition);
		times++;
	}
	else {
		Director::getInstance()->popScene();
	}

}

void SceneManager::goRepoLayer(int tag) {
	auto repoScene = Scene::create();
	auto layer = RepoLayer::create();
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


