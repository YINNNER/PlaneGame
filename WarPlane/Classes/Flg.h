#pragma once
#include "cocos2d.h"
USING_NS_CC;
class Flg :
	public Node
{
public:
	Flg();
	~Flg();
	CREATE_FUNC(Flg);
	virtual bool init();
	void setAttri(int hp, int armor);
	void changeAttri(int hp, int armor);
	void setFlgImg(const char * filename);
	int getHp();
	int getArmor();
private:
	int hp;
	int armor;
	Sprite * flgImg;
};

