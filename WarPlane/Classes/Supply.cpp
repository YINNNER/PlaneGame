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
		this->spyImg = Sprite::create("res/SpaceShooterRedux/PNG/Power-ups/star_gold.png");
		this->addChild(spyImg);
		break;
	case 2 :
	{this->sType = type;
	this->spyImg = Sprite::create("res/SpaceShooterRedux/PNG/Meteors/meteorBrown_med1.png");
	CCParticleSystem* particleSystem1 = CCParticleSun::create();
	particleSystem1->setTexture(CCTextureCache::sharedTextureCache()->addImage("res/SpaceShooterRedux/PNG/Meteors/meteorBrown_med1.png"));
	//自动释放  
	particleSystem1->setAutoRemoveOnFinish(true);
	//设置移动类型:自由模式  
	particleSystem1->setPositionType(kCCPositionTypeFree);
	particleSystem1->setPosition(ccp(0, 0));
	particleSystem1->setStartSize(9);
	particleSystem1->setEndSize(10);
	particleSystem1->setEmissionRate(100);
	addChild(particleSystem1);
	this->addChild(spyImg);
	break; }
	case 3:
	{this->sType = type;
	this->spyImg = Sprite::create("res/SpaceShooterRedux/PNG/Meteors/meteorBrown_med1.png");
	CCParticleSystem* particleSystem1 = CCParticleSun::create();
	particleSystem1->setTexture(CCTextureCache::sharedTextureCache()->addImage("res/SpaceShooterRedux/PNG/Meteors/meteorBrown_med1.png"));
	//自动释放  
	particleSystem1->setAutoRemoveOnFinish(true);
	//设置移动类型:自由模式  
	particleSystem1->setPositionType(kCCPositionTypeFree);
	particleSystem1->setPosition(ccp(0, 0));
	particleSystem1->setStartSize(9);
	particleSystem1->setEndSize(10);
	particleSystem1->setEmissionRate(200);
	addChild(particleSystem1);
	this->addChild(spyImg);
	break; }
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
	auto visibleSize = Director::getInstance()->getVisibleSize();
	if (sType == 1) {  //补给
		this->setPositionY(this->getPositionY() - 3);
		if (this->getPositionY()<0)
		{
			this->removeAllChildrenWithCleanup(true);
			removeSupply();
		}
	}
	else if (sType==2)//陨石
	{
		this->setPositionX(this->getPositionX() - 3);
		this->setPositionY(this->getPositionY() - 4);
		if (this->getPositionY()<0)
		{
			this->removeAllChildrenWithCleanup(true);
			removeSupply();
		}
	}
	else if (sType==3)
	{
		this->setPositionX(this->getPositionX() + 3);
		this->setPositionY(this->getPositionY() - 4);
		if (this->getPositionY()<0)
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

void Supply::removeSupply_2(float)
{
	this->removeFromParentAndCleanup(true);
}

void Supply::replaceImg()
{
	spyImg->removeFromParent();
	spyImg->Sprite::create("res/SpaceShooterRedux/PNG/Damage/playerShip3_damage3.png");
	this->addChild(spyImg);
}
