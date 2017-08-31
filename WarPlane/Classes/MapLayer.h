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
	Sprite *level_1Normal;
	Sprite *level_1Selected;
	Sprite *level_1Forbidden;
	Sprite *level_2Normal;
	Sprite *level_2Selected;
	Sprite *level_2Forbidden;
	Sprite *level_3Normal;
	Sprite *level_3Selected;
	Sprite *level_3Forbidden;
	MenuItemSprite *level_1;//第一关按钮
	MenuItemSprite *level_2;//第二关按钮
	MenuItemSprite *level_3;//第三关按钮
	Sprite *plane;//移动的小飞机
	int chooseLevel;
};

