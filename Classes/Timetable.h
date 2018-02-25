//
// Created by conor on 25/02/18.
//

#ifndef PROJ_ANDROID_STUDIO_TIMETABLE_H
#define PROJ_ANDROID_STUDIO_TIMETABLE_H


#include <vector>

class Timetable {
public:
    std::vector<Stop> stops;

    Stop invokeNextStop();
    bool checkNextStop();
    void prepareNextStop();
    void removeStop();
};


#endif //PROJ_ANDROID_STUDIO_TIMETABLE_H
