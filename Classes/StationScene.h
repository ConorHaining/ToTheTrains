#ifndef __STATION_SCENE_H__
#define __STATION_SCENE_H__

#include "cocos2d.h"

class StationScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(StationScene);
};

#endif // __STATION_SCENE_H__
