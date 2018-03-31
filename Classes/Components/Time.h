//
// Created by conor on 28/03/18.
//

#ifndef PROJ_ANDROID_STUDIO_TIME_H
#define PROJ_ANDROID_STUDIO_TIME_H


#include <ComponentInterface.h>

class Time: public ComponentInterface {
private:
    int hour;
    int minute;
    int second;
    float delta;
};


#endif //PROJ_ANDROID_STUDIO_TIME_H
