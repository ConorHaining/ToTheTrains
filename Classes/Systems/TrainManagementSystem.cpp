//
// Created by conor on 14/04/18.
//

#include <fstream>
#include <iostream>
#include "cocos2d.h"
#include "TrainManagementSystem.h"

USING_NS_CC;

void TrainManagementSystem::loadInTimetable(string fileName) {

    string fileContents;
    fileContents = cocos2d::FileUtils::getInstance()->getStringFromFile("level.json");

    const char* fileContentsCstring;
    fileContentsCstring = fileContents.c_str();
    cocos2d::log("JSON is: %s", fileContentsCstring);

    this->timetable.Parse(fileContentsCstring);
    cocos2d::log("Document is parsed");

}

rapidjson::Value& TrainManagementSystem::checkNextTrain() {

    if (this->timetable.HasMember("timetable") && this->timetable["timetable"].IsArray()) {

        rapidjson::Value& actualTimetable = this->timetable["timetable"];

        for (SizeType i = 0; i < actualTimetable.Size(); i++) {

            rapidjson::Value& nextRecord = actualTimetable[i];

            if(!nextRecord["complete"].GetBool()) {
                cocos2d::log("%d, Arrival Time is: %s", nextRecord["complete"].GetBool(), nextRecord["arrivalTime"].GetString());
                return actualTimetable[i];
            }

        }


    } else {
        cocos2d::log("Timetable not is there");
        // TODO Error Handle

    }

}

void TrainManagementSystem::markAsComplete() {

    rapidjson::Value& actualTimetable = this->timetable["timetable"];
//    cocos2d::log("Pre loop");
    for (SizeType i = 0; i < actualTimetable.Size(); i++) {

        rapidjson::Value& nextRecord = actualTimetable[i];
//        cocos2d::log("Got Record");

        if(!nextRecord["complete"].GetBool()) {
//            cocos2d::log("if not bool");
//            cocos2d::log("%d, Arrival Time is: %s", nextRecord["complete"].GetBool(), nextRecord["arrivalTime"].GetString());
            nextRecord["complete"].SetBool(true);
//            cocos2d::log("%d, Arrival Time is: %s", nextRecord["complete"].GetBool(), nextRecord["arrivalTime"].GetString());
//            cocos2d::log("Changed value");
            return;
        }

    }

}
