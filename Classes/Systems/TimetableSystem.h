//
// Created by conor on 14/04/18.
//

#ifndef PROJ_ANDROID_STUDIO_TIMETABLESYSTEM_H
#define PROJ_ANDROID_STUDIO_TIMETABLESYSTEM_H

#include "include/rapidjson/document.h"

using namespace std;
using namespace rapidjson;

class TimetableSystem {
public:
    void loadInTimetable(string fileName);
    rapidjson::Value & checkNextTrain();
    void popNextTrain();
private:
    Document timetable;
    Document pastTrains;

    void moveTimetableForDepartedTrain();
};


#endif //PROJ_ANDROID_STUDIO_TIMETABLESYSTEM_H
