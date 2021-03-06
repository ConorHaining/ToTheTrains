//
// Created by conor on 28/03/18.
//

#ifndef PROJ_ANDROID_STUDIO_DEPARTURESEQUENCE_H
#define PROJ_ANDROID_STUDIO_DEPARTURESEQUENCE_H


#include <ComponentInterface.h>
#include "cocos2d.h"
#include "DespawnLocation.h"

class DepartureSequence : public ComponentInterface {
private:
    cocos2d::MoveTo* movement;
public:
    void setMovement(DespawnLocation* despawnLocation);

    cocos2d::MoveTo *getMovement() const;

};


#endif //PROJ_ANDROID_STUDIO_DEPARTURESEQUENCE_H
