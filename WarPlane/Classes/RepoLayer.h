#pragma once
#include<iostream>
#include"cocos2d.h"
#include"Equip.h"
#include"SceneManager.h"
USING_NS_CC;

	class RepoLayer :public Layer{
	public:
		virtual bool init();
		void setEquipImg(int type);
		void setPlaneImg(int type);

		void menuCallBack_1(Ref * psender,int type);//传递被点击的菜单的对象
		void menuCallBack_2(Ref * psender,int type);//传递被点击的菜单的对象
		void menuCallBack_3(Ref * psender,int type);//传递被点击的菜单的对象

	

		//监听键盘事件
		virtual void onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event);
		virtual void onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event);
		virtual void equipUpdate(float dt);
	
	
		//返回关卡选择
		void CallMenu(Ref *pSender, UserInfo &userInfo);
		void UnBody_1(Ref *pSender, UserInfo &userInfo);
		void UnBody_1_b(Ref *pSender, UserInfo &userInfo);
		void UnBody_1_c(Ref *pSender, UserInfo &userInfo);
		void UnWing_1(Ref *pSender, UserInfo &userInfo);
		void UnWing_1_b(Ref *pSender, UserInfo &userInfo);
		void UnWing_1_c(Ref *pSender, UserInfo &userInfo);
		void UnTail_1(Ref *pSender, UserInfo &userInfo);
		void UnTail_1_b(Ref *pSender, UserInfo &userInfo);
		void UnTail_1_c(Ref *pSender, UserInfo &userInfo);


		//保存装备
		void SaveEquip(Ref *pSender, UserInfo &userInfo);
		SceneManager * tsm;

		//鼠标监听
		//virtual bool onTouchBegan(Touch *touch, Event *event);
	public:
		//存档信息
		UserInfo user;

	private:
		Sprite * _background;
		Sprite * _background_1;
		Sprite * _background_2;
		Sprite * _background_3;
		
		Sprite * _background_1_white;
		Sprite * _background_2_white;
		//飞机显示栏
		Sprite * _plane;
		//装备栏图片
		Sprite * _equip_1;
		Sprite * _equip_1_b;
		Sprite * _equip_1_c;
		Sprite * _equip_2;
		Sprite * _equip_2_b;
		Sprite * _equip_2_c;
		Sprite * _equip_3;
		Sprite * _equip_3_b;
		Sprite * _equip_3_c;
		//获取传入值的equip对象
		Equip * _equip_head;
		Equip * _equip_head_b;
		Equip * _equip_head_c;

		Equip * _equip_arm;
		Equip * _equip_arm_b;
		Equip * _equip_arm_c;

		Equip * _equip_tail;
		Equip * _equip_tail_b;
		Equip * _equip_tail_c;

		
		//标签
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
		MenuItemImage * _body_1;
		MenuItemImage * _body_1_b;
		MenuItemImage * _body_1_c;
		MenuItemImage * _tail_1;
		MenuItemImage * _tail_1_b;
		MenuItemImage * _tail_1_c;
		MenuItemImage * _wing_1;
		MenuItemImage * _wing_1_b;
		MenuItemImage * _wing_1_c;
		MenuItemImage * _wing_2;
		MenuItemImage * _wing_2_b;
		MenuItemImage * _wing_2_c;
		//白色进度条
		Sprite * BaseBarHp;
		Sprite * BaseBarEn;
		Sprite * BaseBarAtk;
		Sprite * BaseBarSpd;
		//蓝色进度条
		Sprite * HpBar;
		Sprite * EnBar;
		Sprite * AtkBar;
		Sprite * SpdBar;
		//安装装备按钮
		MenuItemImage * _background_3_white_1;
		MenuItemImage * _background_3_white_2;
		MenuItemImage * _background_3_white_3;
	
		//键盘监听
		EventKeyboard::KeyCode key;
		
};

