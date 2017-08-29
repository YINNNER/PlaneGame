//
//  SaveLayer.h
//  WarPlane
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
    void setSaveMenu(float py,int tag);
    void saveMenuItem(Ref * pSender,int tag);
	void setInfoLabel(float py);
    //manager user info
    void createInfo();
    void initInfo();
    void initInfoDetail( __Dictionary * user);
    void saveInfo(int tag);
    void loadInfo(int tag);
  
    std::string getSysTime();
    std::string getSysDay();
	int times;//判断从哪里跳转过来，menu过来为1，其他都为2
	UserInfo user;
    
    
};


#endif /* SaveLayer_h */
