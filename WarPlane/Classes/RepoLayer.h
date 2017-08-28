#pragma once
#include<iostream>
#include"cocos2d.h"
#include"Equip.h"
#include"SceneManager.h"
USING_NS_CC;

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
		void menuCallBack_3(Ref * psender);//传递被点击的菜单的对象
		//void menuCallBack_4(Ref * psender);//传递被点击的菜单的对象
		void setOffset(float);
		void setTag(int);


		//监听键盘事件
		virtual void onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event);
		virtual void onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event);
		virtual void equipUpdate(float dt);
	
		//void schedule(SEL_SCHEDULE selector, float interval);
		//long getCurrentTime();
		//返回关卡选择
		void CallMenu(Ref *pSender);
		SceneManager * tsm;

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
		//EquipManager * tsm;
		Equip * _equip_head;
		Equip * _equip_head_b;
		Equip * _equip_head_c;

		Equip * _equip_arm;
		Equip * _equip_arm_b;
		Equip * _equip_arm_c;

		Equip * _equip_tail;
		Equip * _equip_tail_b;
		Equip * _equip_tail_c;

		Sprite * _equip_1;
		Sprite * _equip_1_b;
		Sprite * _equip_1_c;
		Sprite * _equip_2;
		Sprite * _equip_2_b;
		Sprite * _equip_2_c;
		Sprite * _equip_3;
		Sprite * _equip_3_b;
		Sprite * _equip_3_c;

		Label * equipNum_1_1;
		Label * equipNum_1_2;
		Label * equipNum_1_3;

		Label * equipNum_2_1;
		Label * equipNum_2_2;
		Label * equipNum_2_3;

		Label * equipNum_3_1;
		Label * equipNum_3_2;
		Label * equipNum_3_3;
		

//装备部件
		Sprite * _body_1;
		Sprite * _tail_1;
		Sprite * _wing_1;
		Sprite * _wing_2;

		Sprite * BaseBarHp;
		Sprite * BaseBarEn;
		Sprite * BaseBarAtk;
		Sprite * BaseBarSpd;

		Sprite * HpBar;
		Sprite * EnBar;
		Sprite * AtkBar;
		Sprite * SpdBar;

		


	private:
		float Offset;
		int Tag;
		EventKeyboard::KeyCode key;
		
	
    
    // a selector callback
    
		/*_plane = Sprite::create("/res/SpaceShooterRedux/PNG/Planes/playerShip1_green.png");
		_plane->setPosition(Vec2(winSize.width * 1 / 4, winSize.height * 3 / 4));
		_plane->setScale(0.5);
		this->addChild(_plane);*/
	

    // implement the "static create()" method manually*/
};

