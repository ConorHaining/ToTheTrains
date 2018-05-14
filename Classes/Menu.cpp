//
// Created by Conor Haining on 12/05/2018.
//

#include "Menu.h"
#include "SimpleAudioEngine.h"
#include "StationScene.h"

USING_NS_CC;

Scene* MenuScene::createScene()
{
    return MenuScene::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool MenuScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    background = Sprite::create("TitleMenu.png");
    background->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    this->addChild(background);

    btn1 = Sprite::create("1.png");
    btn1->setPosition(Vec2((visibleSize.width / 2 + origin.x) - 100, 300));
    this->addChild(btn1);

    btn2 = Sprite::create("2.png");
    btn2->setPosition(Vec2(visibleSize.width / 2 + origin.x, 300));
    this->addChild(btn2);

    btn3 = Sprite::create("3.png");
    btn3->setPosition(Vec2((visibleSize.width / 2 + origin.x) + 100, 300));
    this->addChild(btn3);

    btn4 = Sprite::create("4.png");
    btn4->setPosition(Vec2((visibleSize.width / 2 + origin.x) - 100, 170));
    this->addChild(btn4);

    btn5 = Sprite::create("5.png");
    btn5->setPosition(Vec2(visibleSize.width / 2 + origin.x, 170));
    this->addChild(btn5);

    btn6 = Sprite::create("6.png");
    btn6->setPosition(Vec2((visibleSize.width / 2 + origin.x) + 100, 170));
    this->addChild(btn6);

    btn7 = Sprite::create("7.png");
    btn7->setPosition(Vec2((visibleSize.width / 2 + origin.x) - 100, 60));
    this->addChild(btn7);

    btn8 = Sprite::create("8.png");
    btn8->setPosition(Vec2(visibleSize.width / 2 + origin.x, 60));
    this->addChild(btn8);

    btn9 = Sprite::create("9.png");
    btn9->setPosition(Vec2((visibleSize.width / 2 + origin.x) + 100, 60));
    this->addChild(btn9);

    auto touchListener = EventListenerTouchOneByOne::create();
    touchListener->setSwallowTouches(true);

    touchListener->onTouchBegan = CC_CALLBACK_2(MenuScene::onBeginTouch, this);

    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);

    return true;
}

bool MenuScene::onBeginTouch(Touch *touch, Event *event) {

    auto touchPoint = touch->getLocation();


    if (btn1->getBoundingBox().containsPoint(touchPoint)) {

        Scene* level = StationScene::create("level1");
        Director::getInstance()->replaceScene(TransitionFade::create(1, level, Color3B(119,12,47)));

    } else if (btn2->getBoundingBox().containsPoint(touchPoint)) {

        Scene* level = StationScene::create("level2");
        Director::getInstance()->replaceScene(TransitionFade::create(1, level, Color3B(119,12,47)));

    } else if (btn3->getBoundingBox().containsPoint(touchPoint)) {

        Scene* level = StationScene::create("level3");
        Director::getInstance()->replaceScene(TransitionFade::create(1, level, Color3B(119,12,47)));

    } else if (btn4->getBoundingBox().containsPoint(touchPoint)) {

//        Scene* level = StationScene::create("level4");
//        Director::getInstance()->replaceScene(TransitionFade::create(1, level, Color3B(119,12,47)));

    } else if (btn5->getBoundingBox().containsPoint(touchPoint)) {

    } else if (btn6->getBoundingBox().containsPoint(touchPoint)) {

    } else if (btn7->getBoundingBox().containsPoint(touchPoint)) {

    } else if (btn8->getBoundingBox().containsPoint(touchPoint)) {

    } else if (btn9->getBoundingBox().containsPoint(touchPoint)) {

    }



}
