#include "GameManager.h"


GameManager * GameManager::manager_ = NULL;
GameManager::GameManager()
{
}


GameManager::~GameManager()
{
}
void GameManager::setBullet(Bullet * bullet) {
	bullet_list.pushBack(bullet);
}
void GameManager::setSupply(Supply * supply)
{
	supply_list.pushBack(supply);
}
void GameManager::removePlane(CCPlane * plane)
{
	plane_list.eraseObject(plane);
}
void GameManager::removeBullet(Bullet * bullet)
{
	bullet_list.eraseObject(bullet);
}
void GameManager::removeSupply(Supply * supply)
{
	supply_list.eraseObject(supply);
}
Vector<Bullet*>& GameManager::getBulletList()
{
	return this->bullet_list;
	// TODO: �ڴ˴����� return ���
}
Vector<CCPlane*>& GameManager::getPlaneList()
{
	return this->plane_list;
	// TODO: �ڴ˴����� return ���
}
Vector<Supply*>& GameManager::getSupplyList()
{
	return this->supply_list;
	// TODO: �ڴ˴����� return ���
}
GameManager* GameManager::getInstance() {
	if (manager_==NULL)
	{
		manager_ = new GameManager();
	}
	return manager_;
}
void GameManager::removeInstance() {
	if (manager_) {
		delete manager_;
		manager_ = NULL;
	}
}

void GameManager::setPlane(CCPlane * plane)
{
	plane_list.pushBack(plane);
}