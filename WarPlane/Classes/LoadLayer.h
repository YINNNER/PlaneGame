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

	void loadingCallback(Object* pSender);//加载一张图片完成后跳转的毁掉函数
	void loading();

private:
	ProgressTimer* loadProgress;//进度条

	LabelTTF* percentLabel;//加载进度label
	LabelTTF* loadLabel;//显示 loading: 的label

	int m_numSp;//要加载的精灵数目
	int m_loadedSp;//已加载的精灵数目
	
};
#endif // !_warplane_LoadLayer_
