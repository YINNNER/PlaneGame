#ifndef _warplane_SceneManager_
#define _warplane_SceneManager_


#pragma once
#include <cocos2d.h>
USING_NS_CC;
class SceneManager
{
public:
	void CreateLoadScene();
	static void goMenuLayer(int tag);
	static void goCreateLayer(int tag);
	static void goMapLayer(int tag);
	static void goSaveLayer(int tag);
	static void goHelpLayer(int tag);
	static void goSetLayer(int tag);
	static void goRepoLayer(int tag);

public:
	Scene * loadScene;

};


#endif
