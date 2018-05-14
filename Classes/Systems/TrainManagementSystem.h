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
#include <Entities/Train.h>
#include <string>
#include <Components/Time.h>
#include "cocos2d.h"
#include "include/rapidjson/document.h"

using namespace std;
USING_NS_CC;
using namespace rapidjson;

enum TrainState{
    enroute,
    queued,
    inbound,
    atPlatform,
    doorsOpen,
    doorsClosed,
    outbound,
    departed
};

struct Location {
    float x;
    float y;
};

struct Platform{
    string number;
    Location spawnLocation;
    Location stoppingLocation;
    Location despawnLocation;
    Location warningLocation;
    Sprite* warningSymbol;
};

struct TrainRecord {
    Time arrivalTime;
    Time departureTime;
    Platform platform;
    bool complete;
    Train* train;
    TrainState trainState;
};

class TrainManagementSystem {
public:

    TrainManagementSystem(Scene* scene);

    void buildTimetable(string fileName);

    vector<TrainRecord> fetchDueTrains(Time* currentTime);
    vector<TrainRecord> fetchReadyToDepart(Time* currentTime);
    vector<TrainRecord> fetchArrivedTrains();

    bool isPlatformClear(Platform platform);
    bool isPlatformFull(Platform platform);

    bool isRemainingTrains();

    void spawnTrain(TrainRecord trainRecord);
    void despawnTrain(TrainRecord trainRecord);
    void triggerWarningSign(TrainRecord trainRecord);

    void setTrainState(TrainRecord record, TrainState state);

    void setCameraChange(float change);

private:
    Scene* scene;

    vector<TrainRecord> timetable {};

    vector<Platform> platforms {};

    Document levelJSON;

    void buildTrainRecords();
    Time buildTime(rapidjson::Value& currentRecord, const char* type);
    Platform buildPlatform(rapidjson::Value& currentRecord);
    Location buildLocation(rapidjson::Value& currentRecord, const char* type);
};


#endif //PROJ_ANDROID_STUDIO_TIMETABLESYSTEM_H