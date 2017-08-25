#pragma once
#include"cocos2d.h"
USING_NS_CC;
class Supply :public Node
{
public:
	Supply();
	~Supply();
	void setSpt(int type);
	CREATE_FUNC(Supply);
	virtual bool init();
	int getType();
	void update(float dt);
	void removeSupply();
private:
	Sprite * spyImg;
	int sType;
};

