//
//  UserInfo.cpp
//  WarPlane
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
    planeType=1;
    atk=100;
    spd=40;
    gameLevel=1;
    hp=120;
    mp=100;
    planeLevel=1;
    exp=0;
    //equip
    //1.head
    _equip_head_have=0;
    _equip_head_b_have=0;
    _equip_head_c_have=0;
    _equip_head_load=0;
    _equip_head_b_load=0;
    _equip_head_c_load=0;
    //2.arm
    _equip_arm_have=0;
    _equip_arm_b_have=0;
    _equip_arm_c_have=0;
    _equip_arm_load=0;
    _equip_arm_b_load=0;
    _equip_arm_c_load=0;
    //3.tail
    _equip_tail_have=0;
    _equip_tail_b_have=0;
    _equip_tail_c_have=0;
    _equip_tail_load=0;
    _equip_tail_b_load=0;
    _equip_tail_c_load=0;
    

   }

UserInfo::UserInfo(UserInfo const & userInfo){
    //add userName and planeType
    userName=userInfo.userName;
    planeType=userInfo.planeType;
    //the same as constructor
    saveTime=userInfo.saveTime;
    saveDay=userInfo.saveDay;
    atk=userInfo.atk;
    spd=userInfo.spd;
    gameLevel=userInfo.gameLevel;
    hp=userInfo.hp;
    mp=userInfo.mp;
    planeLevel=userInfo.planeLevel;
    exp=userInfo.exp;
    //equip
    //1.head
    _equip_head_have=userInfo._equip_head_have;
    _equip_head_b_have=userInfo._equip_head_b_have;
    _equip_head_c_have=userInfo._equip_head_c_have;
    _equip_head_load=userInfo._equip_head_load;
    _equip_head_b_load=userInfo._equip_head_b_load;
    _equip_head_c_load=userInfo._equip_head_c_load;
    //2.arm
    _equip_arm_have=userInfo._equip_arm_have;
    _equip_arm_b_have=userInfo._equip_arm_b_have;
    _equip_arm_c_have=userInfo._equip_arm_c_have;
    _equip_arm_load=userInfo._equip_arm_load;
    _equip_arm_b_load=userInfo._equip_arm_b_load;
    _equip_arm_c_load=userInfo._equip_arm_c_have;
    //3.tail
    _equip_tail_have=userInfo._equip_tail_have;
    _equip_tail_b_have=userInfo._equip_tail_b_have;
    _equip_tail_c_have=userInfo._equip_tail_c_have;
    _equip_tail_load=userInfo._equip_tail_load;
    _equip_tail_b_load=userInfo._equip_tail_b_load;
    _equip_tail_c_load=userInfo._equip_tail_c_load;
}

ValueMap UserInfo::readPlist(){
    //设置文件路径
    std::string path;
    if (CC_TARGET_PLATFORM == CC_PLATFORM_MAC)
    {
        //是MAC平台
        path = "res/userInfo.plist";
        std::string _fullPath=FileUtils::getInstance()->fullPathForFilename(path);
        CCLOG("read the plist file at %s \n", _fullPath.c_str());
        
        if(FileUtils::getInstance()->isFileExist(_fullPath)){
            
            log("123");
        }else{
            log("111");
        }

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
    spd=dict["spd"].asInt();
    gameLevel=dict["gameLevel"].asInt();
    hp=dict["hp"].asInt();
    mp=dict["mp"].asInt();
    planeLevel=dict["planeLevel"].asInt();
    exp=dict["exp"].asInt();
    //equip
    _equip_head_have=dict["_equip_head_have"].asBool();
    _equip_head_load=dict["_equip_head_load"].asBool();
    _equip_head_b_have=dict["_equip_head_b_have"].asBool();
    _equip_head_b_load=dict["_equip_head_b_load"].asBool();
    _equip_head_c_have=dict["_equip_head_c_have"].asBool();
    _equip_head_c_load=dict["_equip_head_c_load"].asBool();

    _equip_arm_have=dict["_equip_arm_have"].asBool();
    _equip_arm_load=dict["_equip_arm_load"].asBool();
    _equip_arm_b_have=dict["_equip_arm_b_have"].asBool();
    _equip_arm_b_load=dict["_equip_arm_b_load"].asBool();
    _equip_arm_c_have=dict["_equip_arm_c_have"].asBool();
    _equip_arm_c_load=dict["_equip_arm_c_load"].asBool();
    
    _equip_tail_have=dict["_equip_tail_have"].asBool();
    _equip_tail_load=dict["_equip_tail_load"].asBool();
    _equip_tail_b_have=dict["_equip_tail_b_have"].asBool();
    _equip_tail_b_load=dict["_equip_tail_b_load"].asBool();
    _equip_tail_c_have=dict["_equip_tail_c_have"].asBool();
    _equip_tail_c_load=dict["_equip_tail_c_load"].asBool();
    
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
        std::string _fullPath=FileUtils::getInstance()->fullPathForFilename(path);
        CCLOG("see the plist file at %s \n", _fullPath.c_str());

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
	user->setObject(__Integer::create(userInfo.spd), "spd");
	user->setObject(__Integer::create(userInfo.gameLevel), "gameLevel");
	user->setObject(__Integer::create(userInfo.hp), "hp");
	user->setObject(__Integer::create(userInfo.mp), "mp");
	user->setObject(__Integer::create(userInfo.planeLevel), "planeLevel");
	user->setObject(__Integer::create(userInfo.planeType), "planeType");
    user->setObject(__Integer::create(userInfo.exp), "exp");
    //equip
    user->setObject(__Bool::create(userInfo._equip_head_have),"_equip_head_have" );
    user->setObject(__Bool::create(userInfo._equip_head_load),"_equip_head_load" );
    user->setObject(__Bool::create(userInfo._equip_head_b_have),"_equip_head_b_have" );
    user->setObject(__Bool::create(userInfo._equip_head_b_load),"_equip_head_b_load" );
    user->setObject(__Bool::create(userInfo._equip_head_c_have),"_equip_head_c_have" );
    user->setObject(__Bool::create(userInfo._equip_head_c_load),"_equip_head_c_load" );
    user->setObject(__Bool::create(userInfo._equip_arm_have),"_equip_arm_have" );
    user->setObject(__Bool::create(userInfo._equip_arm_load),"_equip_arm_load" );
    user->setObject(__Bool::create(userInfo._equip_arm_b_have),"_equip_arm_b_have" );
    user->setObject(__Bool::create(userInfo._equip_arm_b_load),"_equip_arm_b_load" );
    user->setObject(__Bool::create(userInfo._equip_arm_c_have),"_equip_arm_c_have" );
    user->setObject(__Bool::create(userInfo._equip_arm_c_load),"_equip_arm_c_load" );
    user->setObject(__Bool::create(userInfo._equip_tail_have),"_equip_tail_have" );
    user->setObject(__Bool::create(userInfo._equip_tail_load),"_equip_tail_load" );
    user->setObject(__Bool::create(userInfo._equip_tail_b_have),"_equip_tail_b_have" );
    user->setObject(__Bool::create(userInfo._equip_tail_b_load),"_equip_tail_b_load" );
    user->setObject(__Bool::create(userInfo._equip_tail_c_have),"_equip_tail_c_have" );
    user->setObject(__Bool::create(userInfo._equip_tail_c_load),"_equip_tail_c_load" );


	//5.将字典对象root写入到plist里，log用于调试
	if (root->writeToFile(path.c_str())) 
	{
		log("save the plist file at %s \n", path.c_str());
        std::string _fullPath=FileUtils::getInstance()->fullPathForFilename(path);
        CCLOG("save the plist file at %s \n", _fullPath.c_str());
		
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


//给外部的接口api
//get
std::string UserInfo::getSaveTime(){return saveTime;}
std::string UserInfo::getSaveDay(){return saveDay;}
std::string UserInfo::getUserName(){return userName;}

int UserInfo::getPlaneType(){return planeType;}
int UserInfo::getAtk(){return atk;}
int UserInfo::getSpd(){return spd;}
int UserInfo::getGameLevel(){return gameLevel;}
int UserInfo::getHp(){return hp;}
int UserInfo::getMp(){return mp;}
int UserInfo::getPlaneLevel(){return planeLevel;}
int UserInfo::getExp(){return exp;}
bool UserInfo::get_equip_head_have(){return _equip_head_have;}
bool UserInfo::get_equip_head_b_have(){return _equip_head_b_have;}
bool UserInfo::get_equip_head_c_have(){return _equip_head_c_have;}
bool UserInfo::get_equip_arm_have(){return _equip_arm_have;}
bool UserInfo::get_equip_arm_b_have(){return _equip_arm_b_have;}
bool UserInfo::get_equip_arm_c_have(){return _equip_arm_c_have;}
bool UserInfo::get_equip_tail_have(){return _equip_tail_have;}
bool UserInfo::get_equip_tail_b_have(){return _equip_tail_b_have;}
bool UserInfo::get_equip_tail_c_have(){return _equip_tail_c_have;}
bool UserInfo::get_equip_head_load(){return _equip_head_load;}
bool UserInfo::get_equip_head_b_load(){return _equip_head_b_load;}
bool UserInfo::get_equip_head_c_load(){return _equip_head_c_load;}
bool UserInfo::get_equip_arm_load(){return _equip_arm_load;}
bool UserInfo::get_equip_arm_b_load(){return _equip_arm_b_load;}
bool UserInfo::get_equip_arm_c_load(){return _equip_arm_c_load;}
bool UserInfo::get_equip_tail_load(){return _equip_tail_load;}
bool UserInfo::get_equip_tail_b_load(){return _equip_tail_b_load;}
bool UserInfo::get_equip_tail_c_load(){return _equip_tail_c_load;}

//set
void UserInfo::setPlaneType(int planeType){this->planeType=planeType;}
void UserInfo::setAtk(int atk){this->atk=atk;}
void UserInfo::setSpd(int spd){this->spd=spd;}
void UserInfo::setGameLevel(int gameLevel){this->gameLevel=gameLevel;}
void UserInfo::setHp(int hp){this->hp=hp;}
void UserInfo::setMp(int mp){this->mp=mp;}
void UserInfo::setPlaneLevel(int planeLevel){this->planeLevel=planeLevel;}
void UserInfo::setExp(int exp){this->exp=exp;}
void UserInfo::set_equip_head_have(bool _equip_head_have){this->_equip_head_have=_equip_head_have;}
void UserInfo::set_equip_head_b_have(bool _equip_head_b_have){this->_equip_head_b_have=_equip_head_b_have;}
void UserInfo::set_equip_head_c_have(bool _equip_head_c_have){this->_equip_head_b_have=_equip_head_c_have;}
void UserInfo::set_equip_arm_have(bool _equip_arm_have){this->_equip_arm_have=_equip_arm_have;}
void UserInfo::set_equip_arm_b_have(bool _equip_arm_b_have){this->_equip_arm_b_have=_equip_arm_b_have;}
void UserInfo::set_equip_arm_c_have(bool _equip_arm_c_have){this->_equip_arm_c_have=_equip_arm_c_have;}
void UserInfo::set_equip_tail_have(bool _equip_tail_have){this->_equip_tail_have=_equip_tail_have;}
void UserInfo::set_equip_tail_b_have(bool _equip_tail_b_have){this->_equip_tail_b_have=_equip_tail_b_have;}
void UserInfo::set_equip_tail_c_have(bool _equip_tail_c_have){this->_equip_tail_c_have=_equip_tail_c_have;}
void UserInfo::set_equip_head_load(bool _equip_head_load){this->_equip_head_load=_equip_head_load;}
void UserInfo::set_equip_head_b_load(bool _equip_head_b_load){this->_equip_head_b_load=_equip_head_b_load;}
void UserInfo::set_equip_head_c_load(bool _equip_head_c_load){this->_equip_head_c_load=_equip_head_c_load;}
void UserInfo::set_equip_arm_load(bool _equip_arm_load){this->_equip_arm_load=_equip_arm_load;}
void UserInfo::set_equip_arm_b_load(bool _equip_arm_b_load){this->_equip_arm_b_load=_equip_arm_b_load;}
void UserInfo::set_equip_arm_c_load(bool _equip_arm_c_load){this->_equip_arm_c_load=_equip_arm_c_load;}
void UserInfo::set_equip_tail_load(bool _equip_tail_load){this->_equip_tail_load=_equip_tail_load;}
void UserInfo::set_equip_tail_b_load(bool _equip_tail_b_load){this->_equip_tail_b_load=_equip_tail_b_load;}
void UserInfo::set_equip_tail_c_load(bool _equip_tail_c_load){this->_equip_tail_c_load=_equip_tail_c_load;}



