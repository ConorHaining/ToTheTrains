//
// Created by Conor Haining on 12/05/2018.
//

#include "TitleScene.h"
#include "SimpleAudioEngine.h"
#include "StationScene.h"
#include "Menu.h"

USING_NS_CC;

Scene* TitleScene::createScene()
{
    return TitleScene::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool TitleScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    background = Sprite::create("Title.png");
    background->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    this->addChild(background);

    play = Sprite::create("PlayBtn.png");
    play->setPosition(Vec2(visibleSize.width / 2 + origin.x, 300));
    this->addChild(play);

    rules = Sprite::create("RulesBtn.png");
    rules->setPosition(Vec2(visibleSize.width / 2 + origin.x, 200));
    this->addChild(rules);

    exit = Sprite::create("ExitBtn.png");
    exit->setPosition(Vec2(visibleSize.width / 2 + origin.x, 100));
    this->addChild(exit);

    auto touchListener = EventListenerTouchOneByOne::create();
    touchListener->setSwallowTouches(true);

    touchListener->onTouchBegan = CC_CALLBACK_2(TitleScene::onBeginTouch, this);

    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);

    return true;
}

bool TitleScene::onBeginTouch(Touch *touch, Event *event) {

    auto touchPoint = touch->getLocation();

    if ( play->getBoundingBox().containsPoint(touchPoint) ) {

        Scene* menu = MenuScene::createScene();

        // Transition Fade
        Director::getInstance()->replaceScene(TransitionFade::create(1, menu, Color3B(119,12,47)));


    } else if ( rules->getBoundingBox().containsPoint(touchPoint) ) {



    } else if (exit->getBoundingBox().containsPoint(touchPoint)) {

        Director::getInstance()->end();

    }

}
