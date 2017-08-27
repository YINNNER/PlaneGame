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

std::string UserInfo::getSysTime() {
	time_t t = time(0);
	//set saveTime
	char tmp1[64];
	strftime(tmp1, sizeof(tmp1), "%X", localtime(&t));
	return tmp1;

}

std::string UserInfo::getSysDay() {
	time_t t = time(0);
	//set saveDay
	char tmp2[64];
	strftime(tmp2, sizeof(tmp2), "%Y/%m/%d", localtime(&t));
	return tmp2;
}

void UserInfo::saveInfoToPlist(UserInfo & userInfo,int tag){

    //judge which user to save info 
	std::stringstream name;
	name << "user" << tag;
	std::string key = name.str();

	//open plist file
	//1.设置文件路径
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
	else;
	//2.从文件中创建字典对象
	__Dictionary * root = __Dictionary::createWithContentsOfFile(path.c_str());

	
	//从字典对象Root中取出字典对象user1/2/3
	auto user = static_cast<__Dictionary *>(root->objectForKey(key));


	//4.更新user内部数据

	//通过key设置value
	user->setObject(__String::create(userInfo.userName), "userName");
	//获得系统时间，并用userInfo类的成员变量记录下来
	userInfo.saveTime = getSysTime();
	userInfo.saveDay = getSysDay();
	user->setObject(__String::create(userInfo.saveTime), "saveTime");
	user->setObject(__String::create(userInfo.saveDay), "saveDay");
	user->setObject(__Integer::create(userInfo.atk), "atk");
	user->setObject(__Integer::create(userInfo.def), "def");
	user->setObject(__Integer::create(userInfo.exp), "exp");
	user->setObject(__Integer::create(userInfo.gameLevel), "gameLevel");
	user->setObject(__Integer::create(userInfo.hp), "hp");
	user->setObject(__Integer::create(userInfo.mp), "mp");
	user->setObject(__Integer::create(userInfo.planeLevel), "planeLevel");
	user->setObject(__Integer::create(userInfo.planeType), "planeType");


	//5.将字典对象root写入到plist里，log用于调试
	if (root->writeToFile(path.c_str())) 
	{
		log("see the plist file at %s", path.c_str());
		
	}
	else
		log("write plist file failed");
	
    
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
