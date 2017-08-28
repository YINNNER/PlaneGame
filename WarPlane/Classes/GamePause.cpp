//
//  GamePause.cpp
//  WarPlane
//
//  Created by yiner on 27/08/2017.
//
//

#include "GamePause.h"
#include "SceneManager.h"

bool GamePause::init(){
    auto visibleSize=Director::getInstance()->getVisibleSize();
    
    auto _background = Sprite::create("res/UI/1Menu/background.png");
    _background->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
    auto scale = visibleSize.width / _background->getContentSize().width;
    _background->setScale(scale);
    this->addChild(_background);
    
    MenuItem *backToGame=MenuItemImage::create("res/UI/a4GamePause/backGame.png","res/UI/a4GamePause/backGameS.png",CC_CALLBACK_1(GamePause::CallBack, this));
    backToGame->setTag(1);
    backToGame->setPosition(Vec2(visibleSize.width/2,visibleSize.height*0.6));
    
    auto menu=Menu::create(backToGame,NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu);

    return true;
}


void GamePause::CallBack(Ref *pSender){
    Director::getInstance()->popScene();
    
}
