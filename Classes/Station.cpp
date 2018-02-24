//
// Created by conor on 24/02/18.
//

#include "Station.h"

USING_NS_CC;

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

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /**
     * Add station background
     */
    auto background = Sprite::create("CroyStation.png");

    if(background == nullptr) {
        problemLoading("CroyStation.png");
    } else {
        problemLoading("no null");

        background->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

        auto visibleRect = Director::getInstance()->getOpenGLView()->getVisibleRect();
        float scaleY = visibleRect.size.height / background->getContentSize().height;
        float scaleX = visibleRect.size.width / background->getContentSize().width;

        if(scaleX > scaleY) {
            background->setScale(scaleX);
        } else {
            background->setScale(scaleY);
        }

        background->setVisible(true);
        this->addChild(background, 1);
    }

    return true;
}