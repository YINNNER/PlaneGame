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
	
	void CallBack(Ref *pSender);

private:
	Sprite *selected_1;
	Sprite *selected_2;
	Sprite *selected_3;

};
