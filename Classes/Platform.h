//
// Created by conor on 25/02/18.
//

#ifndef PROJ_ANDROID_STUDIO_PLATFORM_H
#define PROJ_ANDROID_STUDIO_PLATFORM_H

#include "cocos2d.h"
#include <string>

USING_NS_CC;

class Platform {
private:
    std::string platformLabel;
    Vec2 drawLocation;
    Vec2 stoppingLocation;

public:
    Platform(std::string platformLabel, Vec2 drawLocation, Vec2 stoppingLocation);
    std::string getPlatformLabel();
    Vec2 getDrawLocation();
    Vec2 getStoppingLocation();
};


#endif //PROJ_ANDROID_STUDIO_PLATFORM_H
