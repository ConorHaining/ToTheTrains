//
// Created by conor on 14/04/18.
//

#ifndef PROJ_ANDROID_STUDIO_TIMETABLESYSTEM_H
#define PROJ_ANDROID_STUDIO_TIMETABLESYSTEM_H

#include "Entities/Train.h"
#include "include/rapidjson/document.h"

using namespace std;
using namespace rapidjson;

struct ActiveTrain {
    const char * platform;
    Train* train;
};

class TrainManagementSystem {
public:
    void loadInLevel(string fileName);
    rapidjson::Value & checkNextTrain();
    void setActiveTrain();
    TrainManagementSystem(cocos2d::Scene *scene);
    void spawnTrain(rapidjson::Value &timetableRecord);
    bool isPlatformFull(const char* platform);
private:
    Document level;
    cocos2d::Scene *scene;
    std::vector<ActiveTrain> activeTrains {};
    void addActiveTrain(const char* platform, Train* train);
    void removeActiveTrain(Train* train);

};


#endif //PROJ_ANDROID_STUDIO_TIMETABLESYSTEM_H