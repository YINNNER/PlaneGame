#include "Supply.h"
#include"GameManager.h"


Supply::Supply()
{
}


Supply::~Supply()
{
}
void Supply::setSpt(int type)
{
	switch (type)
	{
	case 1 :
		this->sType = type;
		this->spyImg = Sprite::create("res/star_gold.png");
		this->addChild(spyImg);
		break;
	case 2 :
		this->sType = type;
		this->spyImg = Sprite::create("res/meteorBrown_med1.png");
		this->addChild(spyImg);
		break;
	default:
		break;
	}
	scheduleUpdate();
}

bool Supply::init() {
	
	return true;
 }

int Supply::getType()
{
	return sType;
}
void Supply::update(float dt)
{
	static Size visibleSize = Director::getInstance()->getVisibleSize();
	if (sType == 1) {  //²¹¸ø
		this->setPositionY(this->getPositionY() - 3);
		if (this->getPositionY()<0)
		{
			this->removeAllChildrenWithCleanup(true);
			removeSupply();
		}
	}
	else if (sType==2)//ÔÉÊ¯
	{
		this->setPositionX(this->getPositionX() - 3);
		this->setPositionY(this->getPositionY() - 4);
		if (this->getPositionY()>visibleSize.height)
		{
			this->removeAllChildrenWithCleanup(true);
			removeSupply();
		}
	}

}

void Supply::removeSupply()
{
	GameManager::getInstance()->removeSupply(this);
	this->removeFromParentAndCleanup(true);

}
