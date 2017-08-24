#pragma once
#include <cocos2d.h>
#include "SceneManager.h"
#include "HelpLayer.h"
USING_NS_CC;
class SetLayer :
	public Layer
{
public:
	virtual bool init();
	CREATE_FUNC(SetLayer);

	void CallBack(Ref *pSender);
};

