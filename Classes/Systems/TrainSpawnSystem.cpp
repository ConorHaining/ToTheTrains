//
// Created by conor on 03/05/18.
//

#include <Components/SpawnLocation.h>
#include <Components/StoppingLocation.h>
#include <Components/ArrivalSequence.h>
#include <Components/DepartureSequence.h>
#include <EntityManager.h>
#include <Components/SpriteComponent.h>
#include "TrainSpawnSystem.h"

void TrainSpawnSystem::spawnTrain(rapidjson::Value &timetableRecord) {
    // Get Spawn Location

    // TODO unhardcode these values
    SpawnLocation* spawnLocation = new SpawnLocation();
    spawnLocation->setX(182);
    spawnLocation->setY(750);

    // Get Stop Location
    StoppingLocation* stoppingLocation = new StoppingLocation();
    stoppingLocation->setX(182);
    stoppingLocation->setY(250);

    // Get Despawn Location
    DespawnLocation* despawnLocation = new DespawnLocation();
    despawnLocation->setX(182);
    despawnLocation->setY(1000);

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

TrainSpawnSystem::TrainSpawnSystem(cocos2d::Scene *scene) {
    this->scene = scene;
}
