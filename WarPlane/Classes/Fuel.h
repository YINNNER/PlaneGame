#pragma once
#include "cocos2d.h"
USING_NS_CC;
class Fuel :
	public Node
{
public:
	Fuel();
	~Fuel();
	CREATE_FUNC(Fuel);
	virtual bool init();
	void setSpeed(int spd);
	void changeSpeed(int changeSpd);
	void setFuelImg(const char * filename);
	int getSpd();
private:
	int speed;
	Sprite * spdImg;
};

