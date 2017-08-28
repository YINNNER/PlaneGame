#ifndef _warplane_SceneManager_
#define _warplane_SceneManager_


#pragma once
#include <cocos2d.h>
#include "UserInfo.h"
USING_NS_CC;
class SceneManager
{
public:
	void CreateLoadScene();
	static void goMenuLayer(int tag,int transiTimes);
	static void goCreateLayer(int tag);
	static void goMapLayer(int tag,UserInfo &userInfo);
	static void goSaveLayer(int tag,UserInfo &userInfo);//存储进度时调用
	static void goSaveLayer(int tag);//读取进度时调用
	static void goHelpLayer(int tag);
	static void goSetLayer(int tag);
	static void goRepoLayer(int tag, UserInfo &userInfo);

public:
	Scene * loadScene;
	//int level;

};


#endif
