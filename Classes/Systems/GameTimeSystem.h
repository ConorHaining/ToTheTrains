//
// Created by conor on 03/04/18.
//

#ifndef PROJ_ANDROID_STUDIO_GAMETIMESYSTEM_H
#define PROJ_ANDROID_STUDIO_GAMETIMESYSTEM_H

#include "cocos2d.h"

USING_NS_CC;

class GameTimeSystem {
private:
    const int multiplier = 600;
    Scene* scene;
    std::string zerofill(int i);
public:
    GameTimeSystem(Scene* scene);
    void setTime(int hour, int minute);
    void incrementTime(float delta);
    void drawTime();
};


#endif //PROJ_ANDROID_STUDIO_GAMETIMESYSTEM_H
