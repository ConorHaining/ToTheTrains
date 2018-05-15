//
// Created by Conor Haining on 13/05/2018.
//

#ifndef PROJ_ANDROID_STUDIO_LEVELCREATIONSYSTEM_H
#define PROJ_ANDROID_STUDIO_LEVELCREATIONSYSTEM_H

#include <string>
#include <StationScene.h>
#include "include/rapidjson/document.h"
#include "cocos2d.h"

USING_NS_CC;
using namespace std;
using namespace rapidjson;

class StationScene;

class LevelCreationSystem {
private:
    Document levelJSON;
    StationScene* scene;

    string stationName;
    string startTime;
    string endTime;
    string story;
    string endStory;
    string nextLevel;
    string music;

public:
    void createStation();
    void initGameClock();
    void initLevelScore();
    void initLevelStory();

    const string &getStartTime() const;
    const string &getEndTime() const;
    const string &getStory() const;
    string &getEndStory();
    string &getNextLevel();
    string &getMusic();

    void initLevel(string filename);
};


#endif //PROJ_ANDROID_STUDIO_LEVELCREATIONSYSTEM_H
