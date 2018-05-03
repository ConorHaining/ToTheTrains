//
// Created by conor on 03/05/18.
//

#ifndef PROJ_ANDROID_STUDIO_TRAINSPAWNSYSTEM_H
#define PROJ_ANDROID_STUDIO_TRAINSPAWNSYSTEM_H

#include <vector>
#include <Entities/Train.h>
#include <include/rapidjson/document.h>

using namespace std;

class TrainSpawnSystem {
private:
    vector<Train> activeTrains;
    cocos2d::Scene *scene;
public:
    TrainSpawnSystem(cocos2d::Scene *scene);
    void spawnTrain(rapidjson::Value& timetableRecord);
};


#endif //PROJ_ANDROID_STUDIO_TRAINSPAWNSYSTEM_H
