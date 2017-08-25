#ifndef _warplane_SceneManager_
#define _warplane_SceneManager_


#pragma once
#include <cocos2d.h>
#include "LoadLayer.h"
#include "MenuLayer.h"
#include "RepoLayer.h"

USING_NS_CC;
class SceneManager
{
public:
	void CreateLoadScene();
	static void goMenuLayer(int tag);
	static void goCreateLayer(int tag);
	static void goMapLayer(int tag);
	static void goSaveLayer(int tag);
	static void goHelpLayer(int tag);
	static void goSetLayer(int tag);
	static void goRepoLayer(int tag);

	Scene *loadScene;
};

template <class layer,void (&CallBack)(Ref * pSender),  const char* normal, const char *selected>
Menu* Back()
{
	layer *tsm = this;
	auto back = MenuItemImage::create(normal, selected, CC_CALLBACK_1(CallBack,layer ));
	back->setPosition(Vec2(winSize.width*0.15, winSize.height*0.9));

	Menu*mu = Menu::create(back, NULL);
	mu->setPosition(Point::ZERO);
	
}


#endif
