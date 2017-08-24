//
//  SaveLayer.cpp
//  PlaneGame
//
//  Created by yiner on 23/08/2017.
//
//

#include "SaveLayer.h"

Scene * SaveLayer::createScene(){
    auto scene = Scene::create();
    auto layer = SaveLayer::create();
    scene->addChild(layer);
    return scene;
}

void SaveLayer::setTitle(char * str,char * font,int fontSize,Size visibleSize,Vec2 origin,int childIndex){
    auto label = LabelTTF::create(str,font,fontSize);
    label-> setPosition(Vec2(visibleSize.width/2, visibleSize.height*0.9));
    this->addChild(label,childIndex);

    
}

void SaveLayer::setBg(const char * str,Size visibleSize,Vec2 origin,int childIndex){
    auto bg = Sprite::create(str);
    bg-> setPosition(Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height/2));
    auto scale = visibleSize.width/bg->getContentSize().width;
    bg->setScale(scale);
    this->addChild(bg);
}


bool SaveLayer::init(){
    //check whether base class has initialled successfully
    if (!Layer::init()) {
        return false;
    }
    //get origin & visibleSize
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    //set title
    setTitle("载入游戏存档","fonts/AdobeHeitiStd-Regular.otf",28,visibleSize,origin,1);
    
    //set background
    setBg("res/UI/1Menu/background.png",visibleSize,origin,0);
    
    //set back menu
    auto back=MenuItemImage::create("res/UI/2Option/back.png","res/UI/2Option/backS.png",CC_CALLBACK_1(SaveLayer::menuCloseCallback, this));
    back->setPosition(Vec2(visibleSize.width*0.15, visibleSize.height*0.9));
    Menu*mu = Menu::create(back, NULL);
    mu->setPosition(Point::ZERO);
    this->addChild(mu);
    return true;
}


void SaveLayer::menuCloseCallback(Ref *pSender){
    
}

/**
 void SaveLayer::initInfo(Ref * pSender){
 auto root = __Dictionary::create();
 auto array = __Array::create();
 
 // String currentTime = MyUtility::getCurrentTime();
 // log("%s",currentTime.c_str());
 
 //Fist item
 auto dict = __Dictionary::create();
 dict->setObject(<#cocos2d::Ref *pObject#>, <#const std::string &key#>)
 }


 @param pSender <#pSender description#>
 */

void SaveLayer::saveInfo(Ref * pSender){
    
}


void SaveLayer::loadInfo(Ref * pSender){
    
}
