#pragma once
#include <cocos2d.h>
#include "MenuLayer.h"

USING_NS_CC;

class MapLayer :
	public Layer
{
public:
	virtual bool init();
	CREATE_FUNC(MapLayer);

	void CallMenu(Ref *pSender);

};

