//
// Created by conor on 24/02/18.
//

#ifndef PROJ_ANDROID_STUDIO_STATION_H
#define PROJ_ANDROID_STUDIO_STATION_H

#include "cocos2d.h"
#include "Platform.h"
#include "Timetable.h"


class Station : public cocos2d::Scene{
public:
    static cocos2d::Scene* createScene();
    bool setBackground(char* resourceName);
    virtual bool init();
    CREATE_FUNC(Station);
private:
    std::map<std::string, Platform> platforms;
    cocos2d::Sprite* background;
    Timetable* timetable;

    void buildBackground();

};


#endif //PROJ_ANDROID_STUDIO_STATION_H