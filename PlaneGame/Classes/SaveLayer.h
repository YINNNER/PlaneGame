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
    
    //init plist
    void initInfo(Ref * pSender);
    
    //save info to plist
    void saveInfo(Ref * pSender);
    
    //load info from plist
    void loadInfo(Ref * pSender);
    
    CREATE_FUNC(SaveLayer);
    
    //
};

#endif /* SaveLayer_h */
