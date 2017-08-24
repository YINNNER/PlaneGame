
#pragma once
#include <cocos2d.h>
#include "SceneManager.h"
#include "LoadLayer.h"
#include "CreateLayer.h"
#include "SetLayer.h"
#include "SaveLayer.h"
USING_NS_CC;
class MenuLayer :
	public Layer
{
public:
	
	virtual bool init();
	CREATE_FUNC(MenuLayer);
	
	void CallMenu(Ref* pSender);


	Sprite *_background;

};
