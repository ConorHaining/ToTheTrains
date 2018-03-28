//
// Created by conor on 28/03/18.
//

#include "DepartureTime.h"

int DepartureTime::getHour() const {
    return hour;
}

void DepartureTime::setHour(int hour) {
    DepartureTime::hour = hour;
}

int DepartureTime::getMinute() const {
    return minute;
}

void DepartureTime::setMinute(int minute) {
    DepartureTime::minute = minute;
}

int DepartureTime::getSecond() const {
    return second;
}

void DepartureTime::setSecond(int second) {
    DepartureTime::second = second;
}
