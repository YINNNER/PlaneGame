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
    int spd;
    int gameLevel;
    int hp;
    int mp;
    int planeLevel;
    //equip
    //1.head
    bool _equip_head_have;
    bool _equip_head_b_have;
    bool _equip_head_c_have;
    bool _equip_head_load;
    bool _equip_head_b_load;
    bool _equip_head_c_load;
    //2.arm
    bool _equip_arm_have;
    bool _equip_arm_b_have;
    bool _equip_arm_c_have;
    bool _equip_arm_load;
    bool _equip_arm_b_load;
    bool _equip_arm_c_load;
    //3.tail
    bool _equip_tail_have;
    bool _equip_tail_b_have;
    bool _equip_tail_c_have;
    bool _equip_tail_load;
    bool _equip_tail_b_load;
    bool _equip_tail_c_load;
    
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
    int getSpd();
    int getGameLevel();
    int getHp();
    int getMp();
    int getPlaneLevel();
	std::string getSysTime();
	std::string getSysDay();
    //equip
    bool get_equip_head_have();
    bool get_equip_head_b_have();
    bool get_equip_head_c_have();
    bool get_equip_arm_have();
    bool get_equip_arm_b_have();
    bool get_equip_arm_c_have();
    bool get_equip_tail_have();
    bool get_equip_tail_b_have();
    bool get_equip_tail_c_have();
    bool get_equip_head_load();
    bool get_equip_head_b_load();
    bool get_equip_head_c_load();
    bool get_equip_arm_load();
    bool get_equip_arm_b_load();
    bool get_equip_arm_c_load();
    bool get_equip_tail_load();
    bool get_equip_tail_b_load();
    bool get_equip_tail_c_load();
};

#endif /* UserInfo_h */
