#pragma once
#include"cocos2d.h"
USING_NS_CC;
class Bullet:public Node
{
public:
	Bullet();
	~Bullet();
	CREATE_FUNC(Bullet);
	virtual bool init();
	void setBulletImg(const char * filename);
	void update(float dt);
	void removeBullet();
	void removeSkill();
	void setSkillImg(int type);


	void skillMove(float dt);
	Sprite * skillImg_1;
	Sprite * skillImg_2;
private:
	Sprite * bulletImg;
};

