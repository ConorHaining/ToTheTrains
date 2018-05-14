//
// Created by Conor Haining on 11/05/2018.
//

#include <EntityManager.h>
#include <Entities/ScoreEntity.h>
#include <Components/LabelComponent.h>
#include <Components/ScoreComponent.h>
#include "ScoreSystem.h"

void ScoreSystem::updateScore(Time *currentTime, Time departureTime) {

    int differenceInHour = (currentTime->hour - departureTime.hour) * 60;
    int differenceInMinute = currentTime->minute - departureTime.minute;
    int difference = abs(differenceInHour + differenceInMinute);

    int score;
    if(difference > 20 || 20 < difference) {
        score = 0;
    } else {
        double p = pow(difference, 2);
        double q = 0.25 * p;
        double t = 100 - q;
        score = (int)round(t);

    }

    EntityManager* entityManager = EntityManager::getInstance();
    ScoreEntity* scoreEntity = (ScoreEntity*)entityManager->getEntity("score");

    ScoreComponent* scoreComponent = (ScoreComponent*)scoreEntity->getComponent(1);
    scoreComponent->setScore(score);

}

void ScoreSystem::drawScoreFirst() {
    EntityManager* entityManager = EntityManager::getInstance();
    ScoreEntity* scoreEntity = (ScoreEntity*)entityManager->getEntity("score");

    LabelComponent* labelComponent = (LabelComponent*)scoreEntity->getComponent(2);

    drawScore();

    int x = 220;
    int y = 20;

    Label* label = labelComponent->getLabel();
    label->setColor(Color3B(248,232,154));

    label->setPosition(Vec2(x, y));
    this->scene->addChild(label, 999);
}

ScoreSystem::ScoreSystem(Scene *scene) {
    this->scene = scene;
}

void ScoreSystem::drawScore() {
    EntityManager* entityManager = EntityManager::getInstance();
    ScoreEntity* scoreEntity = (ScoreEntity*)entityManager->getEntity("score");

    ScoreComponent* scoreComponent = (ScoreComponent*)scoreEntity->getComponent(1);
    int score = scoreComponent->getScore();

    LabelComponent* label = (LabelComponent*)scoreEntity->getComponent(2);

    stringstream ss;
    ss << "Score: " << score;

    label->getLabel()->setString(ss.str().c_str());
}
