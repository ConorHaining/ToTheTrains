//
// Created by conor on 28/03/18.
//

#ifndef PROJ_ANDROID_STUDIO_ARRIVALSEQUENCE_H
#define PROJ_ANDROID_STUDIO_ARRIVALSEQUENCE_H


#include <ComponentInterface.h>
#include "cocos2d.h"
#include "StoppingLocation.h"

class ArrivalSequence : public ComponentInterface {
private:
    cocos2d::EaseOut* movement;
public:
    void setMovement(StoppingLocation* stoppingLocation);

    cocos2d::EaseOut *getMovement() const;

};


#endif //PROJ_ANDROID_STUDIO_ARRIVALSEQUENCE_H
