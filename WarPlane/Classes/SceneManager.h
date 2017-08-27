#ifndef _warplane_SceneManager_
#define _warplane_SceneManager_


#pragma once
#include <cocos2d.h>
USING_NS_CC;
class SceneManager
{
public:
	void CreateLoadScene();
	static void goMenuLayer(int tag,int transiTimes);
	static void goCreateLayer(int tag);
	static void goMapLayer(int tag,int gameLevel);
	static void goSaveLayer(int tag);
	static void goHelpLayer(int tag);
	static void goSetLayer(int tag);
	static void goRepoLayer(int tag);

public:
	Scene * loadScene;
	//int level;

};


#endif
