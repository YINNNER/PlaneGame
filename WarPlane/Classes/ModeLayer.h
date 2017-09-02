#pragma once
#include <cocos2d.h>
#include"SceneManager.h"

USING_NS_CC;

class ModeLayer :
	public Layer
{
public:
	virtual bool init();
	CREATE_FUNC(ModeLayer);

	//void mouseMove(Event *event);
	void CallBack(Ref *pSender);
	UserInfo user;

};