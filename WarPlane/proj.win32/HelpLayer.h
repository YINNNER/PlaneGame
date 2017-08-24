#pragma once
#include <cocos2d.h>
#include "SceneManager.h"

USING_NS_CC;
class HelpLayer :
	public Layer
{
public:
	virtual bool init();
	CREATE_FUNC(HelpLayer);

	void CallBack(Ref *pSender);
};
