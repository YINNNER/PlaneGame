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
    //tag为1表示首次进入，2表示返回至该界面（除goSaveLayer）
	static void goMenuLayer(int tag);
	static void goCreateLayer(int tag);
	static void goMapLayer(int tag,UserInfo &userInfo);
	static void goSaveLayer(int tag,UserInfo &userInfo);//进行存储，tag=2，表示存储
	static void goSaveLayer(int tag);//进行载入，tag=1，表示载入
	static void goHelpLayer(int tag);
	static void goSetLayer(int tag);
	static void goRepoLayer(int tag, UserInfo &userInfo);
	static void goFightLayer(int level,UserInfo &userInfo);

public:
	Scene * loadScene;
	//int level;

};


#endif
