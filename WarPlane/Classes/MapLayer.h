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
	MenuItemImage *level_1;//��һ�ذ�ť
	MenuItemImage *level_2;//�ڶ��ذ�ť
	MenuItemImage *level_3;//�����ذ�ť
	Sprite *plane;//�ƶ���С�ɻ�
};

