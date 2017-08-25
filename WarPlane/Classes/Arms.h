#pragma once
#include"cocos2d.h"
USING_NS_CC;
class Arms :public Node {
public:
	CREATE_FUNC(Arms);
	virtual bool init();
	void setAtkValue(int atkValue);
	void changeAtkValue(int changeValue); //³É³¤Öµ£»
	void setArmsImg(const char * filename);
	int getAtk();
private:
	int atkValue;
	Sprite * armsImg;
};
