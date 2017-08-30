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
void GameManager::setEBullet(Bullet * bullet)
{
	Ebullet_list.pushBack(bullet);
}
void GameManager::setSupply(Supply * supply)
{
	supply_list.pushBack(supply);
}
void GameManager::removePlane(Enemy * plane)
{
	plane_list.eraseObject(plane);
}
void GameManager::removeBullet(Bullet * bullet)
{
	bullet_list.eraseObject(bullet);
}
void GameManager::removeEBullet(Bullet * bullet)
{
	Ebullet_list.eraseObject(bullet);
}
void GameManager::removeSupply(Supply * supply)
{
	supply_list.eraseObject(supply);
}
Vector<Bullet*>& GameManager::getBulletList()
{
	return this->bullet_list;
	// TODO: 在此处插入 return 语句
}
Vector<Bullet*>& GameManager::getEBulletList()
{
	return Ebullet_list;
	// TODO: 在此处插入 return 语句
}
Vector<Enemy*>& GameManager::getPlaneList()
{
	return this->plane_list;
	// TODO: 在此处插入 return 语句
}
Vector<Supply*>& GameManager::getSupplyList()
{
	return this->supply_list;
	// TODO: 在此处插入 return 语句
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

void GameManager::setPlane(Enemy * plane)
{
	plane_list.pushBack(plane);
}
void GameManager::setSkill(Bullet * skill)
{
	skill_list.pushBack(skill);
}
void GameManager::removeSkill(Bullet * skill)
{
	skill_list.eraseObject(skill);
}
Vector<Bullet*>& GameManager::getSkillList()
{
	return this->skill_list;
}