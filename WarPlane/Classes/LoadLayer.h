#ifndef _warplane_LoadLayer_
#define _warplane_LoadLayer_

#pragma once
#include <cocos2d.h>
#include "SceneManager.h"

USING_NS_CC;
class LoadLayer :
	public Layer
{
public:
	virtual bool init();
	CREATE_FUNC(LoadLayer);
	void onScheduleOnce(float dt);

	Sprite* _background;
	Sprite* _logo;

	


private:

};
#endif // !_warplane_LoadLayer_
