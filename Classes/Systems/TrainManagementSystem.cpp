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
#include <Entities/WarningSymbol.h>
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
//                cocos2d::log("%d, Arrival Time is: %s", nextRecord["complete"].GetBool(), nextRecord["arrivalTime"].GetString());
                return this->level["timetable"][i];
            }

        }


    } else {
        cocos2d::log("Timetable not is there");
        // TODO Error Handle

    }

}

void TrainManagementSystem::setActiveTrain(rapidjson::Value& trainRecord) {


//    cocos2d::log("Pre loop");
    for (SizeType i = 0; i < this->level["timetable"].Size(); i++) {

        rapidjson::Value& nextRecord = this->level["timetable"][i];
//        cocos2d::log("Got Record");

        if(nextRecord == trainRecord) {

            nextRecord["complete"].SetBool(true);
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


    auto trainArrived = CallFuncN::create( [] (Node* sender) {
        cocos2d::log("Arrived");
        sender->setColor(Color3B::BLUE);

        

    });


    this->scene->addChild(trainSprite);

    auto seq = Sequence::create(arrivalSequence->getMovement(), trainArrived, nullptr);

    trainSprite->runAction(seq);
    cocos2d::log("Train spawned & moving");
    this->addActiveTrain(platform, train);

}

TrainManagementSystem::TrainManagementSystem(cocos2d::Scene *scene) {
    this->scene = scene;
}

void TrainManagementSystem::addActiveTrain(const char *platform, Train* train) {

    ActiveTrain activeTrain;
    activeTrain.platform = platform;
    activeTrain.train = train;

    this->activeTrains.push_back(activeTrain);
    cocos2d::log("Active Train pushed");
}

bool TrainManagementSystem::isPlatformFull(const char *platform) {

    for (std::vector<ActiveTrain>::iterator it = activeTrains.begin() ; it != activeTrains.end() ; ++it) {

        cocos2d::log("ActiveTrain Platform: %s, passed in platform: %s | equal %d", (*it).platform, platform, strcmp((*it).platform, platform));

        if(strcmp((*it).platform, platform) == 0) {
            cocos2d::log("Platform %s is full", platform);
            return true;
        }

    }

    cocos2d::log("Platform %s is clear", platform);
    return false;

}

bool TrainManagementSystem::triggerPlatformWarning(const char *platform) {

    EntityManager* entityManager = EntityManager::getInstance();

    string warningTag = "Warning";
    string platformStr(platform);
    cocos2d::log("Placing %s%s", warningTag.c_str(), platformStr.c_str());

    WarningSymbol* warning = (WarningSymbol*)entityManager->getEntity(warningTag + platformStr);

    SpriteComponent* sprite = (SpriteComponent*)warning->getComponent(1);

    int x = this->level["platforms"][platform]["warningLocation"]["x"].GetInt();
    int y = this->level["platforms"][platform]["warningLocation"]["y"].GetInt();

    sprite->getSprite()->setPosition(Vec2(x, y));

    auto scaleUp = cocos2d::ScaleTo::create(0.5f, 1.2f);
    auto scaleDown = cocos2d::ScaleTo::create(0.5f, 1.0f);

    auto seq = cocos2d::Sequence::create(scaleUp, scaleDown, nullptr);
    auto pulse = cocos2d::RepeatForever::create(seq);

    sprite->getSprite()->runAction(pulse);
    this->scene->addChild(sprite->getSprite());

}