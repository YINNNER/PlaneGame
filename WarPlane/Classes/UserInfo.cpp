//
//  UserInfo.cpp
//  MyCppGame
//
//  Created by yiner on 24/08/2017.
//
//

#include "UserInfo.h"
#include "SaveLayer.h"

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

UserInfo::UserInfo(UserInfo const & userInfo){
    //add userName and planeType
    userName=userInfo.userName;
    planeType=userInfo.planeType;
    //the same as constructor
    saveTime=userInfo.saveTime;
    saveDay=userInfo.saveDay;
    atk=userInfo.atk;
    def=userInfo.def;
    exp=userInfo.exp;
    gameLevel=userInfo.gameLevel;
    hp=userInfo.hp;
    mp=userInfo.mp;
    planeLevel=userInfo.planeLevel;
}

ValueMap UserInfo::readPlist(){
    //设置文件路径
    std::string path;
    if (CC_TARGET_PLATFORM == CC_PLATFORM_MAC)
    {
        //是MAC平台
        path = "./res/userInfo.plist";
    }
    else if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
    {
        //WIN32平台
        path = "res/userInfo.plist";
        
    }
    else ;
    
    // 读取plist文件
    // 根节点为字典Dictionary , 读取为一个ValueMap
    ValueMap plist = FileUtils::getInstance()->getValueMapFromFile(path);
    
    return plist;
    
}

//load&read info from plist
void UserInfo::setInfo(int tag){
    
    //read plist file
    ValueMap plist = readPlist();
    
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
    atk=dict["atk"].asInt();
    def=dict["def"].asInt();
    exp=dict["exp"].asInt();
    gameLevel=dict["gameLevel"].asInt();
    hp=dict["hp"].asInt();
    mp=dict["mp"].asInt();
    planeLevel=dict["planeLevel"].asInt();
    
    //用CCLOG做调试语句
    //CCLOG("plane_type = %s", (dict["planeType"].asString()).c_str());
    //CCLOG("plane_type = %d", dict["planeType"].asInt());
    //CCLOG("user_name = %s", (dict["saveDay"].asString()).c_str());
    
}




void UserInfo::saveInfoToPlist(UserInfo & userInfo){
    auto saveLayer = new SaveLayer();
    //create and init userInfo.plist
    saveLayer->createInfo();
    //read plist file
    ValueMap plist = readPlist();
    
    //judge which user number to save info
    
    //save info into user1
    ValueMap& dict = plist["user1"].asValueMap();
    auto user = new __Dictionary();
    //user->setObject(__Integer::create(planeType), "planeType");
    //user->setObject(__String::create(planeName), "userName");

    
}


UserInfo UserInfo::createUser(std::string planeName,int planeType){
    auto saveLayer = new SaveLayer();
    //create and init userInfo.plist
    saveLayer->createInfo();
    auto userInfo = UserInfo();
    userInfo.userName = planeName;
    userInfo.planeType = planeType;
    return userInfo;

}



std::string UserInfo::getSaveTime(){return saveTime;}
std::string UserInfo::getSaveDay(){return saveDay;}
std::string UserInfo::getUserName(){return userName;}
int UserInfo::getPlaneType(){return planeType;}
int UserInfo::getAtk(){return atk;}
int UserInfo::getDef(){return def;}
int UserInfo::getExp(){return exp;}
int UserInfo::getGameLevel(){return gameLevel;}
int UserInfo::getHp(){return hp;}
int UserInfo::getMp(){return mp;}
int UserInfo::getPlaneLevel(){return planeLevel;}
