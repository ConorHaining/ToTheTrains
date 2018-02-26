//
// Created by conor on 24/02/18.
//

#include "Station.h"
#include "Train.h"
#include "Platform.h"
#include "Timetable.h"

USING_NS_CC;

Sprite* background = NULL;

Scene* Station::createScene() {
    return Station::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

bool Station::init() {
    /**
     * Firstly, super init()
     */
    if ( !Scene::init() ){
        return false;
    }

    /**
     * Initiate Station Builder
     * ==============================
     *
     * This creates everything the Station class requires to function,
     * including it's Timetable and the Stops. Platforms available at this
     * station, creation of Trains and such.
     */

    /**
     * Add station background
     */
    this->setBackground("CroyStation.png");

    if(this->background != NULL) {
        this->buildBackground();
    } else {
        problemLoading("Problem Loading Station");
    }

    /**
     * DEV
     * Load the Stations's Timetable
     */
    this->timetable = Timetable::getInstance();

    /**
     * DEV
     * Create Train
     */
    auto train = Train::create("Scotrail170.png");
    train->setPosition(135, -200);
    train->setScale(1.2);
    this->addChild(train, 1);

    train->moveOntoPlatform();

    return true;
}

bool Station::setBackground(char* resourceName) {
    Sprite* backgroundSprite = Sprite::create(resourceName);

    if (backgroundSprite == nullptr) {
        return false;
    } else {
        this->background = backgroundSprite;
    }
}

void Station::buildBackground() {

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    background->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    background->setVisible(true);
    this->addChild(background, 1);
}