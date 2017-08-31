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
	MenuItemSprite *level_1;//��һ�ذ�ť
	MenuItemSprite *level_2;//�ڶ��ذ�ť
	MenuItemSprite *level_3;//�����ذ�ť
	Sprite *plane;//�ƶ���С�ɻ�
	int chooseLevel;
};

