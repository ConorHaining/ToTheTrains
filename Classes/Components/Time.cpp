//
// Created by conor on 28/03/18.
//

#include "Time.h"

bool Time::operator==(Time* otherTime) const{

    if((this->hour == otherTime->hour) && (this->minute == otherTime->minute)) {
        return true;
    } else {
        return false;
    }

}