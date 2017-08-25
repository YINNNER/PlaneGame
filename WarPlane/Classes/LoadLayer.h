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

	void loadingCallback(Object* pSender);//����һ��ͼƬ��ɺ���ת�Ļٵ�����
	void loading();

private:
	ProgressTimer* loadProgress;//������

	LabelTTF* percentLabel;//���ؽ���label
	LabelTTF* loadLabel;//��ʾ loading: ��label

	int m_numSp;//Ҫ���صľ�����Ŀ
	int m_loadedSp;//�Ѽ��صľ�����Ŀ
	
};
#endif // !_warplane_LoadLayer_
