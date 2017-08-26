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
    int planeType;
    int atk;
    int def;
    int exp;
    int gameLevel;
    int hp;
    int mp;
    int planeLevel;
    
    void setInfo(int tag);
    UserInfo();

    
    
};

#endif /* UserInfo_h */
