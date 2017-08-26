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
public:
    void setInfo(int tag);
    UserInfo();

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
    
    
};

#endif /* UserInfo_h */
