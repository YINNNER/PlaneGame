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

	void changeVolumn();
	void CallBack(Ref *pSender);
	bool onTouchBegan(Touch *touch,Event *unused_event);
	void onTouchMoved(Touch *touch, Event *unused_event);
	void onTouchEnded(Touch *touch, Event *unused_event);
	//void SliderBallBack(Ref *pSender, Slider::EventType type);

private:
	Sprite *backCir;
	Sprite *effectCir;
	Sprite *backBar;
	Sprite *effectBar;
};

