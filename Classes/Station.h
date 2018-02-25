//
// Created by conor on 24/02/18.
//

#ifndef PROJ_ANDROID_STUDIO_STATION_H
#define PROJ_ANDROID_STUDIO_STATION_H

#include "cocos2d.h"


class Station : public cocos2d::Scene{
public:
    static cocos2d::Scene* createScene();
    bool setBackground(char* resourceName);
    virtual bool init();
    CREATE_FUNC(Station);
private:

    cocos2d::Sprite* background;

    void buildBackground();

};


#endif //PROJ_ANDROID_STUDIO_STATION_H