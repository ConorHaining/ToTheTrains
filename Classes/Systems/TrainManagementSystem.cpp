#include <Components/SpawnLocation.h>
#include <Components/StoppingLocation.h>
#include <Components/DespawnLocation.h>
#include <Components/ArrivalSequence.h>
#include <Components/DepartureSequence.h>
#include <Components/SpriteComponent.h>
#include <EntityManager.h>
#include <Entities/Train.h>
#include <Entities/WarningSymbol.h>
#include "TrainManagementSystem.h"

TrainManagementSystem::TrainManagementSystem(Scene *scene) {
    this->scene = scene;
}

void TrainManagementSystem::loadInLevel(string fileName) {

    string fileContents;
    fileContents = FileUtils::getInstance()->getStringFromFile(fileName);

    this->levelJSON.Parse(fileContents.c_str());
    cocos2d::log("Document Parsed");

    this->buildTrainRecords();
    cocos2d::log("Train Records Built");
}

vector<TrainRecord> TrainManagementSystem::fetchDueTrains(Time *time) {

    vector<TrainRecord> records {};

    for (vector<TrainRecord>::iterator record = this->timetable.begin(); record != this->timetable.end(); ++record) {

        if (record->arrivalTime == time && !record->complete) {
            records.push_back(*record);
        }

    }

    return records;

}

bool TrainManagementSystem::isPlatformClear(Platform platform) {

    return !isPlatformFull(platform);

}

bool TrainManagementSystem::isPlatformFull(Platform platform) {

    for (vector<TrainRecord>::iterator record = activeTrains.begin(); record != activeTrains.end(); ++record) {

        if (record->platform.number == platform.number) {
            return true;
        }

    }

    return false;

}

void TrainManagementSystem::spawnTrain(TrainRecord trainRecord) {

    // Get Spawn Location

    SpawnLocation* spawnLocation = new SpawnLocation();
    spawnLocation->setX(trainRecord.platform.spawnLocation.x);
    spawnLocation->setY(trainRecord.platform.spawnLocation.y);

    // Get Stop Location
    StoppingLocation* stoppingLocation = new StoppingLocation();
    stoppingLocation->setX(trainRecord.platform.stoppingLocation.x);
    stoppingLocation->setY(trainRecord.platform.stoppingLocation.y);

    // Get Despawn Location
    DespawnLocation* despawnLocation = new DespawnLocation();
    despawnLocation->setX(trainRecord.platform.despawnLocation.x);
    despawnLocation->setY(trainRecord.platform.despawnLocation.y);

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
    string tag;

    tag = "train" + trainRecord.platform.number;

    entityManager->createEntity(tag, (EntityInterface*)train);
    entityManager->addEntityToComponent(train, spawnLocation);
    entityManager->addEntityToComponent(train, stoppingLocation);
    entityManager->addEntityToComponent(train, despawnLocation);
    entityManager->addEntityToComponent(train, arrivalSequence);
    entityManager->addEntityToComponent(train, departureSequence);
    entityManager->addEntityToComponent(train, spawningTrain);

    cocos2d::Sprite* trainSprite = spawningTrain->getSprite();
    trainSprite->setPosition(spawnLocation->getX(), spawnLocation->getY());

    this->scene->addChild(trainSprite);

    auto seq = Sequence::create(arrivalSequence->getMovement(), nullptr);
    trainSprite->runAction(seq);

    for (vector<TrainRecord>::iterator record = this->timetable.begin(); record != this->timetable.end(); ++record) {
        bool equalMinute = record->arrivalTime.minute == trainRecord.arrivalTime.minute;
        bool equalHour = record->arrivalTime.hour == trainRecord.arrivalTime.hour;
        bool equalPlatform = record->platform.number == trainRecord.platform.number;

        if (equalHour && equalMinute && equalPlatform) {
            record->complete = true;
            record->train = trainSprite;
            activeTrains.push_back(*record);
            continue;
        }

    }

    cocos2d::log("Train spawned & moving");

}

void TrainManagementSystem::triggerWarningSign(TrainRecord trainRecord) {

    EntityManager* entityManager = EntityManager::getInstance();

    if (entityManager->getEntity("warning" + trainRecord.platform.number) == nullptr) {

        WarningSymbol* warningSymbol = new WarningSymbol();
        entityManager->createEntity("warning" + trainRecord.platform.number, warningSymbol);

        SpriteComponent* sprite = new SpriteComponent();
        sprite->createSprite("Warning.png");
        entityManager->addEntityToComponent(warningSymbol, sprite);

        int x = trainRecord.platform.warningLocation.x;
        int y = trainRecord.platform.warningLocation.y;

        sprite->getSprite()->setPosition(Vec2(x, y));

        auto scaleUp = cocos2d::ScaleTo::create(0.5f, 1.2f);
        auto scaleDown = cocos2d::ScaleTo::create(0.5f, 1.0f);

        auto seq = cocos2d::Sequence::create(scaleUp, scaleDown, nullptr);
        auto pulse = cocos2d::RepeatForever::create(seq);

        sprite->getSprite()->runAction(pulse);
        this->scene->addChild(sprite->getSprite());

    }

}

void TrainManagementSystem::buildTrainRecords() {

    if(this->levelJSON.HasMember("timetable") && this->levelJSON["timetable"].IsArray()) {

        for (SizeType i = 0; i < this->levelJSON["timetable"].Size(); i++) {

            rapidjson::Value& currentRecord = this->levelJSON["timetable"][i];

            TrainRecord trainRecord;

            Time arrivalTime = this->buildTime(currentRecord, "arrivalTime");
            Time departureTime = this->buildTime(currentRecord, "departureTime");
            Platform platform = this->buildPlatform(currentRecord);

            trainRecord.arrivalTime = arrivalTime;
            trainRecord.departureTime = departureTime;
            trainRecord.platform = platform;
            trainRecord.complete = false;

            this->timetable.push_back(trainRecord);

        }

    } else {

        // TODO error handle

    }

}

Time TrainManagementSystem::buildTime(rapidjson::Value& currentRecord, const char* type) {
    Time time;
    string timeString(currentRecord[type].GetString());

    std::string hour = timeString.substr(0, 2);
    std::string minute = timeString.substr(3, 2);

    int hourInt = std::atoi(hour.c_str());
    int minuteInt = std::atoi(minute.c_str());

    time.hour = hourInt;
    time.minute = minuteInt;

    return time;
}

Platform TrainManagementSystem::buildPlatform(rapidjson::Value& currentRecord) {

    string currentPlatformNumber(currentRecord["platform"].GetString());

    for (vector<Platform>::iterator record = this->platforms.begin(); record != this->platforms.end(); ++record) {

        if (record->number == currentPlatformNumber) {
            return *record;
        }

    }

    rapidjson::Value& currentPlatform = this->levelJSON["platforms"][currentPlatformNumber.c_str()];

    Platform platform;
    platform.number = currentPlatformNumber;
    platform.spawnLocation = this->buildLocation(currentPlatform, "spawnLocation");
    platform.stoppingLocation = this->buildLocation(currentPlatform, "stoppingLocation");
    platform.despawnLocation = this->buildLocation(currentPlatform, "despawnLocation");
    platform.warningLocation = this->buildLocation(currentPlatform, "warningLocation");

    this->platforms.push_back(platform);
    return platform;
    
}

Location TrainManagementSystem::buildLocation(rapidjson::Value &currentRecord, const char *type) {
    
    Location location;
    location.x = currentRecord[type]["x"].GetInt();
    location.y = currentRecord[type]["y"].GetInt();
    
    return location;
    
}

vector<TrainRecord> TrainManagementSystem::fetchArrivedTrains() {

//    vector<TrainRecord> records {};
//
//    for (vector<TrainRecord>::iterator record = this->activeTrains.begin(); record != this->activeTrains.end(); ++record) {
//
////        Time* platformTime = record->arrivalTime + 3;
//
//        if ((record->arrivalTime.minute + 4) == currentTime->minute) {
//
//            records.push_back(*record);
//
//        }
//
//    }
//
//    return records;

    return activeTrains;

}