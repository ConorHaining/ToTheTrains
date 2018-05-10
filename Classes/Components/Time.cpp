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

Time* Time::operator+(int i) {

    Time* newTime = new Time();
    newTime->delta = this->delta;
    newTime->second = this->second;
    newTime->minute = this->minute + i;
    newTime->hour = this->hour;

    if (newTime->minute >= 60) {
        newTime->minute = 0;
        newTime->hour++;
    }

    if (newTime->hour >= 24) {
        newTime->hour = 0;
    }

    return newTime;
}

bool Time::operator<=(Time *otherTime) const {
    if((this->hour <= otherTime->hour) && (this->minute <= otherTime->minute)) {
        return true;
    } else {
        return false;
    }
}
