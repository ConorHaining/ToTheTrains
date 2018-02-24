//
// Created by conor on 24/02/18.
//

#ifndef PROJ_ANDROID_STUDIO_STATION_H
#define PROJ_ANDROID_STUDIO_STATION_H

#include "cocos2d.h"


class Station : public cocos2d::Scene{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    CREATE_FUNC(Station);

};


#endif //PROJ_ANDROID_STUDIO_STATION_H