#include <Entities/Station.h>
#include <Components/SpriteComponent.h>
#include <Systems/StationRenderSystem.h>
#include <Entities/GameClock.h>
#include <Components/Time.h>
#include <Components/LabelComponent.h>
#include <Systems/GameTimeSystem.h>
#include <Systems/TrainManagementSystem.h>
#include <Entities/WarningSymbol.h>
#include "StationScene.h"
#include "SimpleAudioEngine.h"
#include "EntityManager.h"

USING_NS_CC;

Scene* StationScene::createScene()
{
    log("Creating StationScene");
    return StationScene::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool StationScene::init()
{

    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    // Create EntityManager
    log("Creating EntityManager");
    EntityManager* entityManager = EntityManager::getInstance();
    log("Created EntityManager");

    // Load in Entities
    log("Creating Station Entity");
    Station* stationEntity = new Station();
    log("Adding Station Entity");
    entityManager->createEntity("Croy", stationEntity);
    log("Created Station Entity");

    // Attach Components
    SpriteComponent* sprite = new SpriteComponent();
    sprite->createSprite("CroyStation.png");
    entityManager->addEntityToComponent(stationEntity, sprite);
    log("Created Sprite Components");

    // Run StationRenderSystem
    StationRenderSystem* stationRenderSystem = new StationRenderSystem(this);
    stationRenderSystem->drawStation();
    log("Station Draw");

    log("Creating Game Clock");
    GameClock* gameClock = new GameClock();
    entityManager->createEntity("clock", gameClock);
    Time* time = new Time();
    entityManager->addEntityToComponent(gameClock, time);
    LabelComponent* labelComponent = new LabelComponent;
    labelComponent->createLabel("12:00");
    entityManager->addEntityToComponent(gameClock, labelComponent);
    gameTimeSystem = new GameTimeSystem(this);
    gameTimeSystem->setTime(12, 0);
    gameTimeSystem->drawTimeFirst();
    log("Created Game Clock");

    trainManagementSystem = new TrainManagementSystem(this);
    trainManagementSystem->loadInLevel("hello");

    this->scheduleUpdate();

    return true;
}

void StationScene::update(float delta) {
    gameTimeSystem->incrementTime(delta);
    gameTimeSystem->drawTime();

    // Check Time
    rapidjson::Value& nextTrain = trainManagementSystem->checkNextTrain();
    bool isTrainDue = gameTimeSystem->equalTime(nextTrain["arrivalTime"].GetString());

    if (isTrainDue) {
        cocos2d::log("%s is due", nextTrain["arrivalTime"].GetString());

        // Spawn and move train
        if (!trainManagementSystem->isPlatformFull(nextTrain["platform"].GetString())) {
            trainManagementSystem->spawnTrain(nextTrain);
            // Update Timetable
            trainManagementSystem->setActiveTrain(nextTrain);
        } else {
            EntityManager* entityManager = EntityManager::getInstance();
            cocos2d::log("To make warning symbol");
            WarningSymbol* warningSymbol = new WarningSymbol();

            string warningTag = "Warning";
            string platform(nextTrain["platform"].GetString());
            cocos2d::log("%s %s", warningTag.c_str(), platform.c_str());

            entityManager->createEntity(warningTag + platform, warningSymbol);

            cocos2d::log("Warning Entity created");
            SpriteComponent* sprite = new SpriteComponent();
            sprite->createSprite("Warning.png");
            entityManager->addEntityToComponent(warningSymbol, sprite);

            trainManagementSystem->triggerPlatformWarning(nextTrain["platform"].GetString());
        }


    } else {
//        cocos2d::log("No train due");
    }

}