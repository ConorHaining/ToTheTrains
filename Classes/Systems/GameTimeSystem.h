//
// Created by conor on 03/04/18.
//

#ifndef PROJ_ANDROID_STUDIO_GAMETIMESYSTEM_H
#define PROJ_ANDROID_STUDIO_GAMETIMESYSTEM_H

#include <Entities/GameClock.h>
#include <Components/Time.h>
#include "cocos2d.h"

USING_NS_CC;
using namespace std;

class GameTimeSystem {
private:
    int multiplier = 100;
    Scene* scene;
    std::string zerofill(int i);
public:
    GameTimeSystem(Scene* scene);

    void setTime(int hour, int minute);
    void setStartTime(string startTime);
    void setEndTime(string endTime);


    GameClock* getClock();
    Time* getTime();
    void incrementTime(float delta);
    void drawTime();
    void drawTimeFirst();
    bool equalTime(const char* string);
};


#endif //PROJ_ANDROID_STUDIO_GAMETIMESYSTEM_H
