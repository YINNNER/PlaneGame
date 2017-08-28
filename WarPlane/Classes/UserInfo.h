//
//  UserInfo.h
//  MyCppGame
//
//  Created by yiner on 24/08/2017.
//
//

#ifndef UserInfo_h
#define UserInfo_h

#include <stdio.h>
#include "cocos2d.h"
USING_NS_CC;

class UserInfo
{
public:
    std::string userName;
    std::string saveTime;
    std::string saveDay;
    
private:
    int planeType;
    int atk;
    int def;
    int exp;
    int gameLevel;
    int hp;
    int mp;
    int planeLevel;
    //equip
    //1.head
    Vec2 _equip_head;
    Vec2 _equip_head_b;
    Vec2 _equip_head_c;
    //2.arm
    Vec2 _equip_arm;
    Vec2 _equip_arm_b;
    Vec2 _equip_arm_c;
    //3.tail
    Vec2 _equip_tail;
    Vec2 _equip_tail_b;
    Vec2 _equip_tail_c;
    
public:
    void setInfo(int tag);
    //点击保存进度调用的api
    void saveInfoToPlist(UserInfo & userInfo,int tag);
    //点击创建对象调用的api
    UserInfo  createUser(std::string planeName,int planeType);
    //读取plist文件
    ValueMap readPlist();

    UserInfo();
    
    UserInfo(UserInfo const & userInfo);

    //外部调用得到数据的接口
    std::string getSaveTime();
    std::string getSaveDay();
    std::string getUserName();
    int getPlaneType();
    int getAtk();
    int getDef();
    int getExp();
    int getGameLevel();
    int getHp();
    int getMp();
    int getPlaneLevel();
	std::string getSysTime();
	std::string getSysDay();
    
};

#endif /* UserInfo_h */
