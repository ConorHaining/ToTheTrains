//
// Created by Conor Haining on 13/05/2018.
//

#include <EntityManager.h>
#include <Entities/Station.h>
#include <Components/SpriteComponent.h>
#include <Systems/LevelCreationSystem.h>
#include <Components/LabelComponent.h>
#include <Entities/ScoreEntity.h>
#include <Components/ScoreComponent.h>
#include <Entities/GameStory.h>
#include "Systems/GameTimeSystem.h"
#include "Systems/TrainManagementSystem.h"
#include "Systems/ScoreSystem.h"
#include "Systems/StationRenderSystem.h"

void LevelCreationSystem::initLevel(string filename) {

    string fileContents;
    fileContents = FileUtils::getInstance()->getStringFromFile(filename);

    this->levelJSON.Parse(fileContents.c_str());
    cocos2d::log("Document Parsed");

    string station(levelJSON["settings"]["station"].GetString());
    this->stationName = station;

    string startTime (levelJSON["settings"]["startTime"].GetString());
    this->startTime = startTime;

    string endTime (levelJSON["settings"]["endTime"].GetString());
    this->endTime = endTime;

    string winScreen (levelJSON["settings"]["winScreen"].GetString());
    this->endStory = winScreen;

    string next (levelJSON["settings"]["nextLevel"].GetString());
    this->nextLevel = next;

    string storyJSON (levelJSON["settings"]["story"].GetString());
    this->story = storyJSON;

    string music (levelJSON["settings"]["music"].GetString());
    this->music = music;

}

void LevelCreationSystem::createStation() {

    EntityManager* entityManager = EntityManager::getInstance();

    Station* stationEntity = new Station();
    entityManager->createEntity("Station", stationEntity);

    SpriteComponent* sprite = new SpriteComponent();
    sprite->createSprite(this->stationName + "Station.png");
    entityManager->addEntityToComponent(stationEntity, sprite);
}

void LevelCreationSystem::initGameClock() {

    EntityManager* entityManager = EntityManager::getInstance();

    GameClock* gameClock = new GameClock();
    entityManager->createEntity("clock", gameClock);

    Time* time = new Time();
    entityManager->addEntityToComponent(gameClock, time);

    LabelComponent* labelComponent = new LabelComponent;
    labelComponent->createLabel(this->startTime, true);
    entityManager->addEntityToComponent(gameClock, labelComponent);
}

const string &LevelCreationSystem::getStartTime() const {
    return startTime;
}

const string &LevelCreationSystem::getEndTime() const {
    return endTime;
}

const string &LevelCreationSystem::getStory() const {
    return story;
}


void LevelCreationSystem::initLevelScore() {

    EntityManager* entityManager = EntityManager::getInstance();

    ScoreEntity* scoreEntity = new ScoreEntity();
    entityManager->createEntity("score", scoreEntity);

    ScoreComponent* scoreComponent = new ScoreComponent();
    LabelComponent* scoreLabel = new LabelComponent();
    scoreLabel->createLabel("Score: ", true);
    scoreComponent->setScore(0);

    entityManager->addEntityToComponent(scoreEntity, scoreComponent);
    entityManager->addEntityToComponent(scoreEntity, scoreLabel);

}

void LevelCreationSystem::initLevelStory() {
    EntityManager* entityManager = EntityManager::getInstance();

    GameStory* gameStory = new GameStory();
    entityManager->createEntity("story", gameStory);

    LabelComponent* storyLabel = new LabelComponent();
    storyLabel->createLabel(story, true);

    SpriteComponent* btn = new SpriteComponent();
    btn->createSprite("PlayBtn.png");

    SpriteComponent* background = new SpriteComponent();
    background->createSprite("Background.png");

    entityManager->addEntityToComponent(gameStory, storyLabel);
    entityManager->addEntityToComponent(gameStory, btn);
    entityManager->addEntityToComponent(gameStory, background);

}

string &LevelCreationSystem::getEndStory() {
    return endStory;
}

string &LevelCreationSystem::getNextLevel(){
    return nextLevel;
}

string &LevelCreationSystem::getMusic() {
    return music;
}
