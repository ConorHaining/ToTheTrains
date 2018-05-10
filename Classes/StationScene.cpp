#include <Entities/Station.h>
#include <Components/SpriteComponent.h>
#include <Systems/StationRenderSystem.h>
#include <Entities/GameClock.h>
#include <Components/Time.h>
#include <Components/LabelComponent.h>
#include <Systems/GameTimeSystem.h>
#include <Systems/TrainManagementSystem.h>
#include <Entities/WarningSymbol.h>
#include <Components/DepartureSequence.h>
#include <Components/SpawnLocation.h>
#include <Components/StoppingLocation.h>
#include <Components/ArrivalSequence.h>
#include "StationScene.h"
#include "SimpleAudioEngine.h"
#include "EntityManager.h"

USING_NS_CC;
using namespace std;

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
    entityManager = EntityManager::getInstance();
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
    string level = "level.json";
    trainManagementSystem->loadInLevel(level);
    cocos2d::log("Level Loaded");

    cocos2d::log("Registering Touch Events");
    auto touchListener = EventListenerTouchOneByOne::create();
    touchListener->setSwallowTouches(true);

    touchListener->onTouchBegan = CC_CALLBACK_2(StationScene::doorControl, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);

    this->scheduleUpdate();

    return true;
}

void StationScene::update(float delta) {
    gameTimeSystem->incrementTime(delta);
    gameTimeSystem->drawTime();
    Time* currentTime = gameTimeSystem->getTime();

    vector<TrainRecord> dueTrains = trainManagementSystem->fetchDueTrains(currentTime);

    for (vector<TrainRecord>::iterator record = dueTrains.begin(); record != dueTrains.end(); ++record) {

//        cocos2d::log("Train(s) are due");
        if (trainManagementSystem->isPlatformClear(record->platform)) {

            trainManagementSystem->spawnTrain(*record);
            cocos2d::log("...");
        } else {

            trainManagementSystem->queueTrain(*record);
            trainManagementSystem->triggerWarningSign(*record);

        }

    }



}

bool StationScene::doorControl(Touch *touch, Event *event) {

    vector<TrainRecord> arrivedTrains = trainManagementSystem->fetchArrivedTrains();

    auto touchPoint = touch->getLocation();
    for (vector<TrainRecord>::iterator record = arrivedTrains.begin(); record != arrivedTrains.end(); ++record) {

        Train* trainEntity = record->train;
        SpriteComponent* spriteComponent = (SpriteComponent*)trainEntity->getComponent(6);
        Sprite* trainSprite = spriteComponent->getSprite();


        if ( trainSprite->getBoundingBox().containsPoint(touchPoint)) {

            if (trainSprite->getNumberOfRunningActions() == 0 && record->trainState == inbound) {

                // Open Doors
                trainSprite->setColor(Color3B::BLUE);
                trainManagementSystem->setTrainState(*record, TrainState::doorsOpen);

            } else if (trainSprite->getNumberOfRunningActions() == 0 && record->trainState == doorsOpen) {

                // Close Doors
                trainSprite->setColor(Color3B::ORANGE);
                trainManagementSystem->setTrainState(*record, TrainState::doorsClosed);

            } else if  (trainSprite->getNumberOfRunningActions() == 0 && record->trainState == doorsClosed) {

                int x = record->platform.despawnLocation.x;
                int y = record->platform.despawnLocation.y;

                MoveTo* action = MoveTo::create(3, Vec2(x, y));

                // Depart Train
                trainSprite->setColor(Color3B::MAGENTA);
                trainManagementSystem->setTrainState(*record, TrainState::departed);

                trainSprite->runAction(action);

                trainManagementSystem->despawnTrain(*record);


            } else {

                trainSprite->setColor(Color3B::RED);

            }

        }


    }

    return true;

}
