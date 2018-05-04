//
// Created by conor on 14/04/18.
//

#include <fstream>
#include <iostream>
#include "cocos2d.h"
#include "TimetableSystem.h"

USING_NS_CC;

void TimetableSystem::loadInTimetable(string fileName) {

    string fileContents;
    fileContents = cocos2d::FileUtils::getInstance()->getStringFromFile("level.json");

    const char* fileContentsCstring;
    fileContentsCstring = fileContents.c_str();
    cocos2d::log("JSON is: %s", fileContentsCstring);

    this->timetable.Parse(fileContentsCstring);
    cocos2d::log("Document is parsed");

}

rapidjson::Value& TimetableSystem::checkNextTrain() {

    if (this->timetable.HasMember("timetable") && this->timetable["timetable"].IsArray()) {
        cocos2d::log("Timetable is there");

        const rapidjson::Value& actualTimetable = this->timetable["timetable"];

        for (SizeType i = 0; i < actualTimetable.Size(); i++) {

            if(!actualTimetable[i]["complete"].GetBool()) {

                return (rapidjson::Value&) actualTimetable[i];

            }

        }


    } else {
        cocos2d::log("Timetable not is there");
        // TODO Error Handle

    }

}

void TimetableSystem::markAsComplete() {



}
