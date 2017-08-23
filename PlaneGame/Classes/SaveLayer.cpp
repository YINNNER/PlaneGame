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


bool SaveLayer::init(){
    
    
    return true;
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
