//
//  SaveLayer.h
//  MyCppGame
//
//  Created by yiner on 24/08/2017.
//
//

#ifndef SaveLayer_h
#define SaveLayer_h

#include <iostream>
#pragma once
#include "cocos2d.h"
#include "UserInfo.h"

USING_NS_CC;
class SaveLayer :
public Layer
{
public:
    virtual bool init();
    CREATE_FUNC(SaveLayer);
    
    //call back menu
    void callBack(Ref * pSender);
    
    //save menu
    void setSaveMenu(Vec2 origin,Size winSize,float py,int tag);
    void saveMenuItem(Ref * pSender,int tag);
    
    //manager user info
    void initInfo();
    void initInfoDetail( __Dictionary * user);
    void saveInfo();
    void loadInfo(int tag);
    
    std::string getSysTime();
    std::string getSysDay();
    
    
};


#endif /* SaveLayer_h */
