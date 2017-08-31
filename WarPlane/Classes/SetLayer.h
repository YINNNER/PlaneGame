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
	
	static int effectState;//音效开关状态
	static int backState;//bgm开关状态

private:
	Sprite *backCir;
	Sprite *effectCir;
	Sprite *backBar;
	Sprite *effectBar;
	Menu *menu;
	MenuItemToggle *backToggle;
	MenuItemToggle *effectToggle;

};


