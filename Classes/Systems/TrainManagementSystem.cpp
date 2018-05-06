//
// Created by conor on 14/04/18.
//

#include <Components/SpawnLocation.h>
#include <Components/StoppingLocation.h>
#include <Components/ArrivalSequence.h>
#include <Components/DepartureSequence.h>
#include <EntityManager.h>
#include <Components/SpriteComponent.h>
#include <fstream>
#include <iostream>
#include <Entities/Train.h>
#include "cocos2d.h"
#include "TrainManagementSystem.h"

USING_NS_CC;

void TrainManagementSystem::loadInLevel(string fileName) {

    string fileContents;
    fileContents = cocos2d::FileUtils::getInstance()->getStringFromFile("level.json");

    const char* fileContentsCstring;
    fileContentsCstring = fileContents.c_str();
    cocos2d::log("JSON is: %s", fileContentsCstring);

    this->level.Parse(fileContentsCstring);
    cocos2d::log("Document is parsed");
}

rapidjson::Value& TrainManagementSystem::checkNextTrain() {

    if (this->level.HasMember("timetable") && this->level["timetable"].IsArray()) {

        for (SizeType i = 0; i < this->level["timetable"].Size(); i++) {

            rapidjson::Value& nextRecord = this->level["timetable"][i];

            if(!nextRecord["complete"].GetBool()) {
                cocos2d::log("%d, Arrival Time is: %s", nextRecord["complete"].GetBool(), nextRecord["arrivalTime"].GetString());
                return this->level["timetable"][i];
            }

        }


    } else {
        cocos2d::log("Timetable not is there");
        // TODO Error Handle

    }

}

void TrainManagementSystem::setActiveTrain() {


//    cocos2d::log("Pre loop");
    for (SizeType i = 0; i < this->level["timetable"].Size(); i++) {

        rapidjson::Value& nextRecord = this->level["timetable"][i];
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

void TrainManagementSystem::spawnTrain(rapidjson::Value &timetableRecord) {

    // Get Spawn Location
    const char * platform = timetableRecord["platform"].GetString();
    rapidjson::Value& platformDetails = this->level["platforms"][platform];

    SpawnLocation* spawnLocation = new SpawnLocation();
    spawnLocation->setX(platformDetails["spawnLocation"]["x"].GetInt());
    spawnLocation->setY(platformDetails["spawnLocation"]["y"].GetInt());

    // Get Stop Location
    StoppingLocation* stoppingLocation = new StoppingLocation();
    stoppingLocation->setX(platformDetails["stoppingLocation"]["x"].GetInt());
    stoppingLocation->setY(platformDetails["stoppingLocation"]["y"].GetInt());

    // Get Despawn Location
    DespawnLocation* despawnLocation = new DespawnLocation();
    despawnLocation->setX(platformDetails["despawnLocation"]["x"].GetInt());
    despawnLocation->setY(platformDetails["despawnLocation"]["y"].GetInt());

    // Create Arrival Sequence
    ArrivalSequence* arrivalSequence = new ArrivalSequence();
    arrivalSequence->setMovement(stoppingLocation);

    // Create Departure sequence
    DepartureSequence* departureSequence = new DepartureSequence();
    departureSequence->setMovement(despawnLocation);

    // Create Train Component
    SpriteComponent* spawningTrain = new SpriteComponent();
    spawningTrain->createSprite("Scotrail170.png");

    // Create New Train Entity
    EntityManager* entityManager = EntityManager::getInstance();
    Train* train = new Train();
    entityManager->createEntity("train", train);
    entityManager->addEntityToComponent(train, spawnLocation);
    entityManager->addEntityToComponent(train, stoppingLocation);
    entityManager->addEntityToComponent(train, despawnLocation);
    entityManager->addEntityToComponent(train, arrivalSequence);
    entityManager->addEntityToComponent(train, departureSequence);
    entityManager->addEntityToComponent(train, spawningTrain);

    cocos2d::Sprite* trainSprite = spawningTrain->getSprite();
    trainSprite->setPosition(spawnLocation->getX(), spawnLocation->getY());

    this->scene->addChild(trainSprite);
    trainSprite->runAction(arrivalSequence->getMovement());
}

TrainManagementSystem::TrainManagementSystem(cocos2d::Scene *scene) {
    this->scene = scene;
}