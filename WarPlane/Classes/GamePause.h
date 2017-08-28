//
//  GamePause.h
//  WarPlane
//
//  Created by yiner on 27/08/2017.
//
//

#ifndef GamePause_h
#define GamePause_h

#include <stdio.h>
#include <cocos2d.h>
USING_NS_CC;
class GamePause:public Layer{
public:
    virtual bool init();
    CREATE_FUNC(GamePause);
    
    void CallBack(Ref *pSender);
    
};

#endif /* GamePause_h */
