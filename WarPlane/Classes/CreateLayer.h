#pragma once
#include <cocos2d.h>
#include "MapLayer.h"
USING_NS_CC;
class CreateLayer :
	public Layer
{
public:
	
	virtual bool init();
	CREATE_FUNC(CreateLayer);
	
	bool CreatePlayer(Ref *pSender);

};
