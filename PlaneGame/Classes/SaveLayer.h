//
//  SaveLayer.h
//  PlaneGame
//
//  Created by yiner on 23/08/2017.
//
//

#ifndef SaveLayer_h
#define SaveLayer_h

#include <stdio.h>
#include "cocos2d.h"
USING_NS_CC;

class SaveLayer:public Layer{
public:
    static Scene * createScene();
    
    virtual bool init();
    
    //!!encapsulation this 2 method
    void setTitle(char * str,char * font,int fontSize,Size visibleSize,Vec2 origin,int childIndex);
    
    void setBg(const char * str,Size visibleSize,Vec2 origin,int childIndex);
    
    //init plist
    void initInfo(Ref * pSender);
    
    //save info to plist
    void saveInfo(Ref * pSender);
    
    //load info from plist
    void loadInfo(Ref * pSender);
    
    CREATE_FUNC(SaveLayer);
    
    void menuCloseCallback(Ref *pSender);
    
    
};

#endif /* SaveLayer_h */
