//
//  GameFin.h
//  MyCppGame
//
//  Created by yiner on 26/08/2017.
//
//

#ifndef GameFin_h
#define GameFin_h

#include <stdio.h>
#include "cocos2d.h"
//#include "SceneManager"

USING_NS_CC;

class GameFin:public Layer{
public:
    virtual bool init();
    CREATE_FUNC(GameFin);
    void saveMenuItem(Ref *pSender);
    void MapMenuItem(Ref *pSender);

    //SceneManager * tsm;

};
#endif /* GameFin_h */
