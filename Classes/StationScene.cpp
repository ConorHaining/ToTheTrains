#include <Entities/Station.h>
#include <Components/SpriteComponent.h>
#include <Systems/StationRenderSystem.h>
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
    entityManager->createEntity(stationEntity);
    log("Created Station Entity");

    // Attach Components
    SpriteComponent* sprite = new SpriteComponent();
    sprite->createSprite("CroyStation.png");
    entityManager->addEntityToComponent(stationEntity, sprite);
    log("Created Sprite Components");

    // Run StationRenderSystem
    StationRenderSystem* stationRenderSystem = new StationRenderSystem(this, stationEntity);
    stationRenderSystem->drawStation();

    return true;
}