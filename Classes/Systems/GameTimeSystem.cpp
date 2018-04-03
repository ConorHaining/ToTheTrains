    //
// Created by conor on 03/04/18.
//

#include <EntityManager.h>
#include <Components/Time.h>
#include <Entities/GameClock.h>
#include <cmath>
#include <Components/LabelComponent.h>
#include "GameTimeSystem.h"

GameTimeSystem::GameTimeSystem(Scene* scene) {
    this->scene = scene;
}

void GameTimeSystem::setTime(int hour, int minute) {
    EntityManager* entityManager = EntityManager::getInstance();
    GameClock* gameClock = (GameClock*)entityManager->getEntity("clock");

    Time* time = (Time*)gameClock->getComponent(1);

    time->hour = hour;
    time->minute = minute;
    time->second = 0;
    time->delta = 0;
}

void GameTimeSystem::incrementTime(float delta) {
    EntityManager* entityManager = EntityManager::getInstance();
    GameClock* gameClock = (GameClock*)entityManager->getEntity("clock");

    Time* time = (Time*)gameClock->getComponent(1);

    // todo Store the leftover float to make time more accurate
    float increaseInMinutes = this->multipler * delta;
    time->minute += rint(increaseInMinutes);

    if (time->minute > 60) {
        time->minute -= 60;
    }
}

void GameTimeSystem::drawTime() {
    EntityManager* entityManager = EntityManager::getInstance();
    GameClock* gameClock = (GameClock*)entityManager->getEntity("clock");

    Time* time = (Time*)gameClock->getComponent(1);
    LabelComponent* label = (LabelComponent*)gameClock->getComponent(2);

    auto dirs = Director::getInstance();
    Size visibleSize = dirs->getVisibleSize();
    Vec2 origin = dirs->getVisibleOrigin();

    label->getLabel()->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

    this->scene->addChild(label);

}
