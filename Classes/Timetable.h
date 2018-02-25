//
// Created by conor on 25/02/18.
//

#ifndef PROJ_ANDROID_STUDIO_TIMETABLE_H
#define PROJ_ANDROID_STUDIO_TIMETABLE_H


#include <vector>
#include "Stop.h"

class Timetable {
private:

    std::vector<Stop> stops;

    /**
     * Singleton
     */
    static Timetable* instance;
    Timetable();

public:

    static Timetable* create();

    Stop invokeNextStop();
    bool checkNextStop();
    void prepareNextStop();
    void removeStop();

    void addStop(Stop s);
};


#endif //PROJ_ANDROID_STUDIO_TIMETABLE_H
