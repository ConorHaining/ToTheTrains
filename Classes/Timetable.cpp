//
// Created by conor on 25/02/18.
//

#include "Timetable.h"

Timetable *Timetable::create() {
    if(instance == 0){
        instance = new Timetable();
    }

    return instance;
}

Stop Timetable::invokeNextStop() {
    return Stop();
}

bool Timetable::checkNextStop() {
    return false;
}

void Timetable::prepareNextStop() {

}

void Timetable::removeStop() {

}

void Timetable::addStop(Stop s) {
    // Push to the end of the stops queue
    this->stops.push_back(s);
}
