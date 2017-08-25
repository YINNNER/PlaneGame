#pragma once
#include<iostream>
#include"cocos2d.h"
#include"Equip.h"
USING_NS_CC;
/*typedef enum {
	kEquip_1_Tag=102,
	kEquip_2_Tag,
	kEquip_3_Tag,

};*/
	class RepoLayer :public Layer{
	public:

		virtual bool init();
		CREATE_FUNC(RepoLayer);
		//在该函数中注册监听器和初始化设置
		//virtual void onEnter();
		//注销监听器、释放资源
		//virtual void onExit();
		//声明单点触摸回调函数
		//bool touchBegan(Touch * touch, Event * event);


		void menuCallBack_1(Ref * psender);//传递被点击的菜单的对象
		void menuCallBack_2(Ref * psender);//传递被点击的菜单的对象

		//int getBarLength(int life);

		//virtual bool onTouchBegan(Touch *touch, Event *unused_event);
		


	public:

		/*void hpUpdate(int dt);
		void spdUpdate(int dt);
		void atkUpdate(int dt);

		virtual bool onTouchBegan(Touch * touch, Event * event);

		*/
		Sprite * _background;
		Sprite * _background_1;
		Sprite * _background_2;
		Sprite * _background_3;

		Sprite * _background_1_white;
		Sprite * _background_2_white;
		Sprite * _background_3_white;

		Sprite * _plane;//plane photo
		Sprite * _plane_2;//plane photo
		//EquipManager * tsm;
		Equip * _equip_1;//equip photo
		Sprite * _equip_1Img;
		Sprite * _equip_2;
		Sprite * _equip_3;

		Sprite * BaseBarHp;
		Sprite * BaseBarEn;
		Sprite * BaseBarAtk;
		Sprite * BaseBarSpd;

		Sprite * HpBar;
		Sprite * EnBar;
		Sprite * AtkBar;
		Sprite * SpdBar;
	//	Sprite * BaseBarHp;

		
	
    
    // a selector callback
    
		/*_plane = Sprite::create("/res/SpaceShooterRedux/PNG/Planes/playerShip1_green.png");
		_plane->setPosition(Vec2(winSize.width * 1 / 4, winSize.height * 3 / 4));
		_plane->setScale(0.5);
		this->addChild(_plane);*/
	

    // implement the "static create()" method manually*/
};

