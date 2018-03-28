//
// Created by conor on 28/03/18.
//

#ifndef PROJ_ANDROID_STUDIO_ARRIVALSEQUENCE_H
#define PROJ_ANDROID_STUDIO_ARRIVALSEQUENCE_H


#include "cocos2d.h"
#include "StoppingLocation.h"

class ArrivalSequence {
private:
    cocos2d::MoveTo* movement;
public:
    void setMovement(StoppingLocation stoppingLocation);

    cocos2d::MoveTo *getMovement() const;

};


#endif //PROJ_ANDROID_STUDIO_ARRIVALSEQUENCE_H
