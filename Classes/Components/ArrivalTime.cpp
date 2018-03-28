//
// Created by conor on 28/03/18.
//

#include "ArrivalTime.h"

int ArrivalTime::getHour() const {
    return hour;
}

void ArrivalTime::setHour(int hour) {
    ArrivalTime::hour = hour;
}

int ArrivalTime::getMinute() const {
    return minute;
}

void ArrivalTime::setMinute(int minute) {
    ArrivalTime::minute = minute;
}

int ArrivalTime::getSecond() const {
    return second;
}

void ArrivalTime::setSecond(int second) {
    ArrivalTime::second = second;
}
