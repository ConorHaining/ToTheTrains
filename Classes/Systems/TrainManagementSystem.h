//
// Created by conor on 14/04/18.
//

#ifndef PROJ_ANDROID_STUDIO_TIMETABLESYSTEM_H
#define PROJ_ANDROID_STUDIO_TIMETABLESYSTEM_H

//class TrainManagementSystem {
//public:
//    void loadInLevel(string fileName);
//    rapidjson::Value & checkNextTrain();
//    void setActiveTrain(rapidjson::Value& trainRecord);
//    TrainManagementSystem(cocos2d::Scene *scene);
//    void spawnTrain(rapidjson::Value &timetableRecord);
//    bool isPlatformFull(const char* platform);
//    bool triggerPlatformWarning(const char* platform);
//private:
//    Document level;
//    cocos2d::Scene *scene;
//    std::vector<ActiveTrain> activeTrains {};
//    void addActiveTrain(const char* platform, Train* train);
//    void removeActiveTrain(Train* train);
//    void trainArrived(Node* sender);
//};

#include <Entities/GameClock.h>
#include <string>
#include "cocos2d.h"

using namespace std;
USING_NS_CC;

struct Location {
    int x;
    int y;
};

struct Platform{
    string number;
    Location* spawnLocation;
    Location* stoppingLocation;
    Location* despawnLocation;
    Location* warningLocation;
};

struct TrainRecord {
    GameClock* arrivalTime;
    GameClock* departureTime;
    Platform* platform;
    bool complete;
};

class TrainManagementSystem {
public:

    TrainManagementSystem(Scene* scene);

    void loadInLevel(string fileName);

    vector<TrainRecord> fetchDueTrains(GameClock* currentTime);

    bool isPlatformClear(Platform* platform);
    bool isPlatformFull(Platform* platform);

    void spawnTrain(TrainRecord trainRecord);
    void triggerWarningSign(TrainRecord trainRecord);

private:
    Scene* scene;

    vector<TrainRecord> timetable {};
    vector<TrainRecord> activeTrains {};
    vector<TrainRecord> queuedTrains {};

};


#endif //PROJ_ANDROID_STUDIO_TIMETABLESYSTEM_H