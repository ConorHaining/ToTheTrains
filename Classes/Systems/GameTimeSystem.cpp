    //
// Created by conor on 03/04/18.
//

#include "GameTimeSystem.h"
#include <EntityManager.h>
#include <Components/Time.h>
#include <Entities/GameClock.h>
#include <cmath>
#include <Components/LabelComponent.h>
#include <sstream>
#include <string>

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
    EntityManager *entityManager = EntityManager::getInstance();
    GameClock *gameClock = (GameClock *) entityManager->getEntity("clock");

    Time *time = (Time *) gameClock->getComponent(1);

    time->delta += delta * this->multiplier;

    if (time->delta >= 1) {
        time->second += time->delta;
        time->delta = 0;
    }

    if (time->second >= 60) {
        time->second = 0;
        time->minute++;
    }

    if (time->minute >= 60) {
        time->minute = 0;
        time->hour++;
    }

    if (time->hour >= 24) {
        time->hour = 0;
    }
}

void GameTimeSystem::drawTime() {
    EntityManager* entityManager = EntityManager::getInstance();
    GameClock* gameClock = (GameClock*)entityManager->getEntity("clock");

    Time* time = (Time*)gameClock->getComponent(1);
    LabelComponent* label = (LabelComponent*)gameClock->getComponent(2);

    std::stringstream ss;
    ss << zerofill(time->hour) << ":" << zerofill(time->minute);
    std::string timeText = ss.str();

    label->getLabel()->setString(timeText);

}

void GameTimeSystem::drawTimeFirst() {
    EntityManager* entityManager = EntityManager::getInstance();
    GameClock* gameClock = (GameClock*)entityManager->getEntity("clock");

    LabelComponent* label = (LabelComponent*)gameClock->getComponent(2);

    drawTime();

    auto dirs = Director::getInstance();
    Size visibleSize = dirs->getVisibleSize();
    Vec2 origin = dirs->getVisibleOrigin();

    label->getLabel()->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

    this->scene->addChild(label->getLabel());
}

std::string GameTimeSystem::zerofill(int i) {
    std::stringstream ss;

    if (i < 10) {
        ss << "0" << i;
    } else {
        ss << i;
    }

    return ss.str();
}

GameClock *GameTimeSystem::getTime() {
    EntityManager* entityManager = EntityManager::getInstance();
    GameClock* gameClock = (GameClock*)entityManager->getEntity("clock");

    return gameClock;
}

bool GameTimeSystem::equalTime(const char* time) {
    GameClock* gameClock = this->getTime();
    Time *gameTime = (Time *) gameClock->getComponent(1);

    // Time is in format HH:MM
    std::string timeString(time);

    std::string hour = timeString.substr(0, 2);
    std::string minute = timeString.substr(3, 2);

    int hourInt = std::atoi(hour.c_str());
    int minuteInt = std::atoi(minute.c_str());

    return (gameTime->hour == hourInt) && (gameTime->minute == minuteInt);

}
