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
#include <Entities/ScoreEntity.h>
#include <Components/ScoreComponent.h>
#include <Systems/ScoreSystem.h>
#include "StationScene.h"
#include "SimpleAudioEngine.h"
#include "EntityManager.h"

USING_NS_CC;
using namespace std;
using namespace CocosDenshion;

//Scene* StationScene::createScene(string level)
//{
//    log("Creating StationScene");
//    this->setName(level);
//    return StationScene::create();
//}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool StationScene::init(string level)
{

    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    /**
     * Game System Registration
     */
    levelCreationSystem = new LevelCreationSystem();
    gameTimeSystem = new GameTimeSystem(this);
    scoreSystem = new ScoreSystem(this);
    trainManagementSystem = new TrainManagementSystem(this);
    stationRenderSystem = new StationRenderSystem(this);
    gameStorySystem = new GameStorySystem(this);

    /**
     * Initialise level from JSON file
     */
    levelCreationSystem->initLevel(level + ".json");

    /**
     * Create Station
     */
    levelCreationSystem->createStation();
    stationRenderSystem->drawStation();

    /**
     * Create Game Clock & set start and end times
     */
    levelCreationSystem->initGameClock();
    gameTimeSystem->setStartTime(levelCreationSystem->getStartTime());
//    gameTimeSystem->setEndTime(levelCreationSystem->getEndTime());
    gameTimeSystem->drawTimeFirst();

    /**
     * Create the Game Score
     */
    levelCreationSystem->initLevelScore();
    scoreSystem->drawScoreFirst();

    /**
     * Build the level's Timetable
     */
    trainManagementSystem->buildTimetable(level + ".json");

    /**
     * Register Game's touch events
     */
    auto touchListener = EventListenerTouchOneByOne::create();
    touchListener->setSwallowTouches(true);

    touchListener->onTouchBegan = CC_CALLBACK_2(StationScene::doorControl, this);
    touchListener->onTouchMoved = CC_CALLBACK_2(StationScene::moveCamera, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);

    /**
     * Set Background Audio
     */
    auto audio = SimpleAudioEngine::getInstance();
    audio->playBackgroundMusic(levelCreationSystem->getMusic().c_str(), true);

    /**
     * Show level story
     */
    levelCreationSystem->initLevelStory();
    gameStorySystem->drawStory();

    return true;
}

void StationScene::update(float delta) {
    gameTimeSystem->incrementTime(delta);
    gameTimeSystem->drawTime();
    Time* currentTime = gameTimeSystem->getTime();

    vector<TrainRecord> dueTrains = trainManagementSystem->fetchDueTrains(currentTime);

    for (vector<TrainRecord>::iterator record = dueTrains.begin(); record != dueTrains.end(); ++record) {

        if (trainManagementSystem->isPlatformClear(record->platform)) {

            trainManagementSystem->spawnTrain(*record);
        } else {

            trainManagementSystem->triggerWarningSign(*record);

        }

    }


    vector<TrainRecord> arrivedTrains = trainManagementSystem->fetchArrivedTrains();

    for (vector<TrainRecord>::iterator record = arrivedTrains.begin(); record != arrivedTrains.end(); ++record) {

        Train* trainEntity = record->train;
        SpriteComponent* spriteComponent = (SpriteComponent*)trainEntity->getComponent(6);
        Sprite* trainSprite = spriteComponent->getSprite();

//        bool atPlatform = (record->trainState == doorsOpen) || (record->trainState == doorsClosed) || (record->trainState == outbound);

        if (trainSprite->getNumberOfRunningActions() == 0 && record->trainState == inbound) {

            trainSprite->setTexture("Scotrail170-Action.png");

        }

    }

    vector<TrainRecord> readyToDepart = trainManagementSystem->fetchReadyToDepart(currentTime);

    for (vector<TrainRecord>::iterator record = readyToDepart.begin(); record != readyToDepart.end(); ++record) {

        Train* trainEntity = record->train;
        SpriteComponent* spriteComponent = (SpriteComponent*)trainEntity->getComponent(6);
        Sprite* trainSprite = spriteComponent->getSprite();

        trainSprite->setTexture("Scotrail170-Action.png");

    }

    bool endLevel = trainManagementSystem->isRemainingTrains();

    if (endLevel) {

        this->unscheduleUpdate();

        gameStorySystem->drawEndScreen(levelCreationSystem->getEndStory());

    }

}

bool StationScene::doorControl(Touch *touch, Event *event) {

    EntityManager* entityManager = EntityManager::getInstance();
    auto touchPoint = touch->getLocation();

    SpriteComponent* btn = (SpriteComponent*)entityManager->getEntity("story")->getComponent(2);
    Sprite* sprite = btn->getSprite();

    if (sprite->getBoundingBox().containsPoint(touchPoint)) {

        if (sprite->getTag() == 1) {

            gameStorySystem->removeStory();

            /**
             * Schedule Update Loop
             */
            this->scheduleUpdate();

        } else {

            EntityManager::resetInstance();

            Scene* level = StationScene::create(levelCreationSystem->getNextLevel());
            Director::getInstance()->replaceScene(TransitionFade::create(1, level, Color3B(119,12,47)));

        }
        return true;

    }

    vector<TrainRecord> arrivedTrains = trainManagementSystem->fetchArrivedTrains();


    for (vector<TrainRecord>::iterator record = arrivedTrains.begin(); record != arrivedTrains.end(); ++record) {

        Train* trainEntity = record->train;
        SpriteComponent* spriteComponent = (SpriteComponent*)trainEntity->getComponent(6);
        Sprite* trainSprite = spriteComponent->getSprite();


        if ( trainSprite->getBoundingBox().containsPoint(touchPoint)) {

            if (trainSprite->getNumberOfRunningActions() == 0 && record->trainState == inbound) {

                // Open Doors
                trainSprite->setTexture("Scotrail170-DoorsOpen.png");
                trainManagementSystem->setTrainState(*record, TrainState::doorsOpen);

                auto hold = MoveBy::create(1, Vec2(0, 0));
                trainSprite->runAction(hold);

                return true;

            } else if (trainSprite->getNumberOfRunningActions() == 0 && record->trainState == doorsOpen) {

                // Close Doors
                trainSprite->setTexture("Scotrail170-DoorsClosed.png");
                trainManagementSystem->setTrainState(*record, TrainState::doorsClosed);

                auto hold = MoveBy::create(1, Vec2(0, 0));
                trainSprite->runAction(hold);

                return true;

            } else if  (trainSprite->getNumberOfRunningActions() == 0 && record->trainState == doorsClosed) {

                int x = record->platform.despawnLocation.x;
                int y = record->platform.despawnLocation.y;

                MoveTo* action = MoveTo::create(3, Vec2(x, y));

                // Depart Train
                trainSprite->setTexture("Scotrail170.png");
                trainManagementSystem->setTrainState(*record, TrainState::outbound);

                TrainRecord r = *record;

                auto cb = CallFunc::create( [this, r] () {
                    this->trainManagementSystem->despawnTrain(r);
                });

                auto seq = Sequence::create(action, cb, nullptr);

                trainSprite->runAction(seq);
                Time* currentTime = gameTimeSystem->getTime();
                scoreSystem->updateScore(currentTime, record->departureTime);
                scoreSystem->drawScore();
                return true;

            }
        }


    }

}

void StationScene::moveCamera(Touch *touch, Event *event) {

    EntityManager* entityManager = EntityManager::getInstance();
    SpriteComponent* sprite = (SpriteComponent*)entityManager->getEntity("Station")->getComponent(1);

    auto dirs = Director::getInstance();
    Size visibleSize = dirs->getVisibleSize();
    Vec2 origin = dirs->getVisibleOrigin();

    float leftEdgeScreen = origin.x;
    float rightEdgeScreen = origin.x + visibleSize.width;

    float leftSideStation = (sprite->getSprite()->getPosition().x) - (sprite->getSprite()->getContentSize().width / 2);
    float rightSideStation = (sprite->getSprite()->getPosition().x) + (sprite->getSprite()->getContentSize().width / 2);

    log("Screen L: %f R: %f Station L: %f R: %F || D: %f", leftEdgeScreen, rightEdgeScreen, leftSideStation, rightSideStation, touch->getDelta().x);

    if ((ceil(leftSideStation) >= leftEdgeScreen) && (touch->getDelta().x > 0)) {

        return;

    } else if ((floor(rightSideStation) <= rightEdgeScreen) && (touch->getDelta().x < 0)) {

        return;

    }

    float x = this->getPositionX() + touch->getDelta().x;
    this->setPositionX(x);

    trainManagementSystem->setCameraChange(touch->getDelta().x);

    Vector<Node*> nodes = this->getChildren();

    for (auto node : nodes) {

        if (node->getTag() != 1) {

            x = node->getPositionX() + touch->getDelta().x;
            node->setPositionX(x);

        }

    }

}

StationScene *StationScene::create(string level) {

    StationScene *pRet = new(std::nothrow) StationScene();
    if (pRet && pRet->init(level))
    {
        pRet->autorelease();
        return pRet;
    }
    else
    {
        delete pRet;
        pRet = NULL;
        return NULL;
    }

}