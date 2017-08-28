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
	static void goMenuLayer(int tag,int transiTimes);
	static void goCreateLayer(int tag);
	static void goMapLayer(int tag,UserInfo &userInfo);
	static void goSaveLayer(int tag,UserInfo &userInfo);//¥Ê¥¢Ω¯∂» ±µ˜”√
	static void goSaveLayer(int tag);//∂¡»°Ω¯∂» ±µ˜”√
	static void goHelpLayer(int tag);
	static void goSetLayer(int tag);
	static void goRepoLayer(int tag, UserInfo &userInfo);

public:
	Scene * loadScene;
	//int level;

};


#endif
