#pragma once
#include <cocos2d.h>
#include "MenuLayer.h"
#include"SceneManager.h"

USING_NS_CC;

class MapLayer :
	public Layer
{
public:
	virtual bool init();
	CREATE_FUNC(MapLayer);

	//void mouseMove(Event *event);
	void CallMenu(Ref *pSender);
	UserInfo user;

public:
	MenuItemImage *level_1;//第一关按钮
	MenuItemImage *level_2;//第二关按钮
	MenuItemImage *level_3;//第三关按钮
	Sprite *plane;//移动的小飞机
};

