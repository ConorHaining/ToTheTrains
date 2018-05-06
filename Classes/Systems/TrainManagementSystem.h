//
// Created by conor on 14/04/18.
//

#ifndef PROJ_ANDROID_STUDIO_TIMETABLESYSTEM_H
#define PROJ_ANDROID_STUDIO_TIMETABLESYSTEM_H

#include "include/rapidjson/document.h"

using namespace std;
using namespace rapidjson;

class TrainManagementSystem {
public:
    void loadInLevel(string fileName);
    rapidjson::Value & checkNextTrain();
    void setActiveTrain();
    TrainManagementSystem(cocos2d::Scene *scene);
    void spawnTrain(rapidjson::Value &timetableRecord);
private:
    Document level;
    cocos2d::Scene *scene;
};


#endif //PROJ_ANDROID_STUDIO_TIMETABLESYSTEM_H