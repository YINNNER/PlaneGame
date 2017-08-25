//
//  UserInfo.cpp
//  MyCppGame
//
//  Created by yiner on 24/08/2017.
//
//

#include "UserInfo.h"

UserInfo::UserInfo(){
    userName="";
    saveTime="";
    saveDay="";
    planeType=0;
    atk=0;
    def=0;
    exp=0;
    gameLevel=1;
    hp=500;
    mp=500;
    planeLevel=1;
    
   }

void UserInfo::getInfo(int tag){
    
    // 文件路径
    std::string path = "res/userInfo.plist";
    
    
    // 读取plist文件
    // 根节点为字典Dictionary , 读取为一个ValueMap
    ValueMap plist = FileUtils::getInstance()->getValueMapFromFile(path);
    
    
    
    // 获取数据
    // 读取 "user1/2/3" , 也是一个字典ValueMap
    std::stringstream name;
    name<<"user"<<tag;
    ValueMap& dict = plist[name.str()].asValueMap();
    //读取字典内部的元素dict[]，再用其类型对应的方法
    userName=(dict["userName"].asString()).c_str();
    saveTime=(dict["saveTime"].asString()).c_str();
    saveDay=(dict["saveDay"].asString()).c_str();
    planeType=dict["planeType"].asInt();
    atk=dict["planeType"].asInt();
    def=dict["planeType"].asInt();
    exp=dict["planeType"].asInt();
    gameLevel=dict["planeType"].asInt();
    hp=dict["planeType"].asInt();
    mp=dict["planeType"].asInt();
    planeLevel=dict["planeType"].asInt();
    
    //用CCLOG做调试语句
    //CCLOG("plane_type = %s", (dict["planeType"].asString()).c_str());
    //CCLOG("plane_type = %d", dict["planeType"].asInt());
    //CCLOG("user_name = %s", (dict["saveDay"].asString()).c_str());
    
      
}