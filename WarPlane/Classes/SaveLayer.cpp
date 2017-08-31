//
//  SaveLayer.cpp
//  WarPlane
//
//  Created by yiner on 24/08/2017.
//
//

#include "SaveLayer.h"
#include <time.h>
#include "SceneManager.h"
#include "SetLayer.h"
#include "SimpleAudioEngine.h"
using namespace CocosDenshion;

#define winSize Director::getInstance()->getVisibleSize()
#define origin Director::getInstance()->getVisibleOrigin()

bool SaveLayer::init() {
    
    if ( !Layer::init() )
    {
        return false;
    }
   
    //set background
    auto _background = Sprite::create("res/UI/1Menu/background.png");
    _background->setPosition(Vec2(origin.x + winSize.width / 2, origin.y + winSize.height / 2));
    auto scale = winSize.width / _background->getContentSize().width;
    _background->setScale(scale);
    this->addChild(_background);
    
    //set title
    auto title = Label::createWithTTF("载入游戏存档","fonts/simhei.ttf",30);
    title->setPosition(Vec2(origin.x + winSize.width /2, origin.y + winSize.height *0.9));
    this->addChild(title);
    
    //set back menu
    auto backMenu = MenuItemImage::create("res/UI/2Option/back.png","res/UI/2Option/backS.png",CC_CALLBACK_1(SaveLayer::callBack, this));
    backMenu->setPosition(Vec2(origin.x + winSize.width *0.15, origin.y + winSize.height *0.9));
    auto menu=Menu::create(backMenu,NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu);
    
    
    //create and init userInfo.plist
    createInfo();
    
    
    //set save menu
    setSaveMenu(0.70,1);
    setSaveMenu(0.45,2);
    setSaveMenu(0.20,3);
    
    return true;
}


void SaveLayer::callBack(Ref * pSender){
	if (SetLayer::getEffectState() == 1) {
		SimpleAudioEngine::getInstance()->playEffect("music/trans1.wav");
		SimpleAudioEngine::sharedEngine()->playEffect("music/click8.wav");
	}
    int back=2;
    int transiTime=1;
    SceneManager::goMenuLayer(back, transiTime);
}


void SaveLayer::saveMenuItem(Ref * pSender,int tag){
	if (SetLayer::getEffectState() == 1) {
		SimpleAudioEngine::getInstance()->playEffect("music/trans1.wav");
		SimpleAudioEngine::sharedEngine()->playEffect("music/click8.wav");
	}
	if (times==1)
	{
		loadInfo(tag);

	}
	else{
	
	saveInfo(tag);
    times=1;

	}

    
}


//check whether userInfo.plist is existed
//if is not existed, create and init userInfo.plist
void SaveLayer::createInfo(){
    std::string writablePath;
    
    if(CC_TARGET_PLATFORM == CC_PLATFORM_MAC)
    {
        //是MAC平台
        writablePath = "res/";
        
        
    }
    else if(CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
    {
        
        writablePath ="res/";
        
    }
    else ;
    
    std::stringstream fullPath;
    fullPath<< writablePath <<"userInfo.plist";
    
    //check whether userInfo.plist is existed(user info has been initialled)
    if (!FileUtils::getInstance()->isFileExist(fullPath.str().c_str())) {
        //if (!FileUtils::getInstance()->isFileExist("res/userInfo.plist")) {
        CCLOG("no exist");
        initInfo();
        
    }
    else CCLOG("exist") ;

}

//获得系统时间
std::string SaveLayer::getSysTime(){
    time_t t = time(0);
    //set saveTime
    char tmp1[64];
    strftime( tmp1, sizeof(tmp1), "%X",localtime(&t) );
    return tmp1;

}

std::string SaveLayer::getSysDay(){
    time_t t = time(0);
    //set saveDay
    char tmp2[64];
    strftime( tmp2, sizeof(tmp2), "%Y/%m/%d",localtime(&t) );
    return tmp2;
}

void SaveLayer::initInfoDetail( __Dictionary * user){
    //通过key设置value
    user->setObject(__String::create(""), "userName");
    //获得系统时间，并用userInfo类的成员变量记录下来
    auto userInfo=new UserInfo();
    userInfo->saveTime=getSysTime();
    userInfo->saveDay=getSysDay();
    user->setObject(__String::create(userInfo->saveTime), "saveTime");
    user->setObject(__String::create(userInfo->saveDay), "saveDay");
    user->setObject(__Integer::create(100), "atk");
    user->setObject(__Integer::create(40), "spd");
    user->setObject(__Integer::create(1), "gameLevel");
    user->setObject(__Integer::create(500), "hp");
    user->setObject(__Integer::create(100), "mp");
    user->setObject(__Integer::create(1), "planeLevel");
    user->setObject(__Integer::create(1), "planeType");
    user->setObject(__Integer::create(0), "exp");

    //equip
    user->setObject(__Bool::create(0),"_equip_head_have" );
    user->setObject(__Bool::create(0),"_equip_head_load" );
    user->setObject(__Bool::create(0),"_equip_head_b_have" );
    user->setObject(__Bool::create(0),"_equip_head_b_load" );
    user->setObject(__Bool::create(0),"_equip_head_c_have" );
    user->setObject(__Bool::create(0),"_equip_head_c_load" );
    user->setObject(__Bool::create(0),"_equip_arm_have" );
    user->setObject(__Bool::create(0),"_equip_arm_load" );
    user->setObject(__Bool::create(0),"_equip_arm_b_have" );
    user->setObject(__Bool::create(0),"_equip_arm_b_load" );
    user->setObject(__Bool::create(0),"_equip_arm_c_have" );
    user->setObject(__Bool::create(0),"_equip_arm_c_load" );
    user->setObject(__Bool::create(0),"_equip_tail_have" );
    user->setObject(__Bool::create(0),"_equip_tail_load" );
    user->setObject(__Bool::create(0),"_equip_tail_b_have" );
    user->setObject(__Bool::create(0),"_equip_tail_b_load" );
    user->setObject(__Bool::create(0),"_equip_tail_c_have" );
    user->setObject(__Bool::create(0),"_equip_tail_c_load" );


    delete userInfo;
}


void SaveLayer::initInfo(){
   
    //创建plist文件步骤
    //1.创建__Dictionary字典结果对象Root，Root与整个属性列表文件对应
    auto Root = __Dictionary::create();
    
    //2.First user,创建__Dictionary字典结果对象user1
    auto user1 = __Dictionary::create();
    //3.初始化user1内部数据
    initInfoDetail(user1);
    //4.将user1对象加入Root中
    Root->setObject(user1,"user1");
    
    //Second user,创建__Dictionary字典结果对象user2
    auto user2 = __Dictionary::create();
    //初始化user2内部数据
    initInfoDetail(user2);
    //将user2对象加入Root中
    Root->setObject(user2,"user2");
    
    //Third user,创建__Dictionary字典结果对象user3
    auto user3 = __Dictionary::create();
    //初始化user3内部数据
    initInfoDetail(user3);
    //将user3对象加入Root中
    Root->setObject(user3,"user3");
    
    //获得可写入目录
    std::string writablePath;
    
    
    if(CC_TARGET_PLATFORM == CC_PLATFORM_MAC)
    {
        //是MAC平台
        writablePath = "./res/";
    }
    else if(CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
    {
        //WIN32平台
        writablePath = "res/";
    }
    else ;
    
    //set file path
    
    std::stringstream fullPath;
    fullPath<< writablePath <<"userInfo.plist";
    //将字典对象Root写入属性列表文件中
    //std::stringstream a; a.str().c_str();//---->string--->char *
    if(Root->writeToFile(fullPath.str().c_str())){
        log("create info and init it,see the plist file at %s",fullPath.str().c_str());
        std::string _fullPath=FileUtils::getInstance()->fullPathForFilename(fullPath.str());
        CCLOG("see the plist file at %s", _fullPath.c_str());
    }
    else
        log("write plist file failed");
    
}



void SaveLayer::saveInfo(int tag){
	
	user.saveInfoToPlist(user,tag);
	this->removeChildByTag(tag);

	float py;
	switch (tag){
	case 1:	py = 0.70;
	break;
	case 2:	py = 0.45;
	break;
	case 3:	py = 0.20;
	break;
	default:
		break;
	}
	setSaveMenu(py,tag);
	
}

void SaveLayer::loadInfo(int tag){
    user.setInfo(tag);
    if (user.getUserName()!= "") {
        int enter=1;
        SceneManager::goMapLayer(enter,user);
    }
    
}

void SaveLayer::setInfoLabel(float py){
	//1.If there is no info in the menu
	if (user.getUserName() == "") {
		auto noInfo = Label::createWithTTF("暂无存档", "fonts/simhei.ttf", 40);
		noInfo->enableOutline(Color4B(73, 75, 80, 130), 3);
		noInfo->setAdditionalKerning(15);
		noInfo->setPosition(Vec2(origin.x + winSize.width / 2, origin.y + winSize.height *py));
		noInfo->setTag(100);
		this->addChild(noInfo);
	}
	//2.If there if info in the menu
	else {
		//1.add plane image
		std::stringstream picName;
		picName << "res/SpaceShooterRedux/PNG/Planes/playerShip" << user.getPlaneType() << "_green.png";
		auto planeImg = Sprite::create(picName.str());
		planeImg->setPosition(Vec2(origin.x + winSize.width / 2 - planeImg->getContentSize().width*1.2, origin.y + winSize.height *py));
		planeImg->setTag(101);
		this->addChild(planeImg);

		//2.add plane info
		std::stringstream name;
		name << "战机名：" << user.getUserName() << std::endl << user.getSaveTime() << std::endl << user.getSaveDay() << std::endl;
		auto infoPlane = Label::createWithTTF(name.str(), "fonts/simhei.ttf", 23);
		infoPlane->enableOutline(Color4B(73, 75, 80, 130), 3);
		infoPlane->setPosition(Vec2(origin.x + winSize.width / 2 + planeImg->getContentSize().width *0.52, origin.y + winSize.height *(py-0.02) ));
		infoPlane->setAdditionalKerning(4);
		infoPlane->setLineHeight(38);
		infoPlane->setTag(102);
		this->addChild(infoPlane);
	}
}



void SaveLayer::setSaveMenu(float py,int tag){
    auto saveMenu = MenuItemImage::create("res/UI/3LoadingSave/rec1.png","res/UI/3LoadingSave/rec2.png",CC_CALLBACK_1(SaveLayer::saveMenuItem,this,tag));
    saveMenu->setPosition(Vec2(origin.x + winSize.width /2, origin.y + winSize.height *py));
    saveMenu->setScale(0.8);
    saveMenu->setTag(tag);
    auto menu=Menu::create(saveMenu,NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu);
    
    //add save menu info
    user.setInfo(tag);
	setInfoLabel(py);
}
