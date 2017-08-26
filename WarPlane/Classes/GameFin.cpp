//
//  GameFin.cpp
//  MyCppGame
//
//  Created by yiner on 26/08/2017.
//
//

#include "GameFin.h"

bool GameFin::init(){
    
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto origin = Director::getInstance()->getVisibleOrigin();
    
    //set background
    auto _background = Sprite::create("res/UI/1Menu/background.png");
    _background->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2));
    auto scale = visibleSize.width / _background->getContentSize().width;
    _background->setScale(scale);
    this->addChild(_background);
    
    //set menu rect
    auto menuRect = Sprite::create("res/UI/a5GameFin/rect.png");
    menuRect->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2));
    menuRect->setScale(0.8);
    this->addChild(menuRect);

    
    //set title
    //胜负条件判断
    int isWin=1;
    if (isWin) {
        auto title = Label::createWithTTF("通关成功","fonts/simhei.ttf",30);
        title->setPosition(Vec2(origin.x + visibleSize.width /2, origin.y + visibleSize.height *0.8));
        this->addChild(title);
        
        //set menu item to save info
        auto goSaveMenu = MenuItemImage::create("res/UI/a5GameFin/save.png","res/UI/a5GameFin/saveS.png",CC_CALLBACK_1(GameFin::saveMenuItem, this));
        goSaveMenu->setPosition(Vec2(origin.x + visibleSize.width *0.3, origin.y + visibleSize.height *0.25));
        goSaveMenu->setScale(0.7);
        
        //set menu item to mapLayer
        auto goMapMenu = MenuItemImage::create("res/UI/a5GameFin/selectLevel.png","res/UI/a5GameFin/selectLevelS.png",CC_CALLBACK_1(GameFin::saveMenuItem, this));
        goMapMenu->setPosition(Vec2(origin.x + visibleSize.width *0.7, origin.y + visibleSize.height *0.25));
        goMapMenu->setScale(0.7);
        
        auto menu=Menu::create(goSaveMenu,goMapMenu,NULL);
        menu->setPosition(Point::ZERO);
        this->addChild(menu);
        
        //show finish time and the rest hp
        //！！Api----用时处需要得到游戏时间
        std::string usingTime="03:00:00";
        std::stringstream tmp;
        tmp<<"用时："<<usingTime;
        auto time = Label::createWithTTF(tmp.str(),"fonts/simhei.ttf",30);
        time->setPosition(Vec2(origin.x + visibleSize.width *0.3, origin.y + visibleSize.height *0.7));
        this->addChild(time);
        

        
    }
    else{
        auto title = Label::createWithTTF("通关失败","fonts/simhei.ttf",30);
        title->setPosition(Vec2(origin.x + visibleSize.width /2, origin.y + visibleSize.height *0.8));
        this->addChild(title);
        
        //set menu item to mapLayer
        auto goMapMenu = MenuItemImage::create("res/UI/a5GameFin/selectLevel.png","res/UI/a5GameFin/selectLevelS.png",CC_CALLBACK_1(GameFin::saveMenuItem, this));
        goMapMenu->setPosition(Vec2(origin.x + visibleSize.width *0.5, origin.y + visibleSize.height *0.25));
        goMapMenu->setScale(0.7);

        
        auto menu=Menu::create(goMapMenu,NULL);
        menu->setPosition(Point::ZERO);
        this->addChild(menu);

    }
    
    
    
    return true;
}


void GameFin::saveMenuItem(Ref *pSender){
    
}

void GameFin::MapMenuItem(Ref *pSender){
    
}
