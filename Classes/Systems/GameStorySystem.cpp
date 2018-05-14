//
// Created by Conor Haining on 13/05/2018.
//

#include <EntityManager.h>
#include <Components/LabelComponent.h>
#include <Components/SpriteComponent.h>
#include "GameStorySystem.h"

GameStorySystem::GameStorySystem(Scene *scene) {
    this->scene = scene;
}

void GameStorySystem::drawStory() {

    EntityManager* entityManager = EntityManager::getInstance();
    LabelComponent* label = (LabelComponent*)entityManager->getEntity("story")->getComponent(1);
    SpriteComponent* btn = (SpriteComponent*)entityManager->getEntity("story")->getComponent(2);
    SpriteComponent* background = (SpriteComponent*)entityManager->getEntity("story")->getComponent(3);

    auto dirs = Director::getInstance();
    Size visibleSize = dirs->getVisibleSize();
    Vec2 origin = dirs->getVisibleOrigin();

    label->getLabel()->setDimensions(300, 0);
    label->getLabel()->setScale(0.8);
    label->getLabel()->setHorizontalAlignment(TextHAlignment::CENTER);

    label->getLabel()->setPosition(Vec2(origin.x + visibleSize.width/2,
                                        origin.y + visibleSize.height/2));

    btn->getSprite()->setScale(0.6);
    btn->getSprite()->setPosition(Vec2(origin.x + visibleSize.width/2, 460));
    btn->getSprite()->setTag(1);

    background->getSprite()->setPosition(Vec2(origin.x + visibleSize.width/2,
                                 origin.y + visibleSize.height/2));

    this->scene->addChild(label->getLabel(), 1000);
    this->scene->addChild(btn->getSprite(), 1001);
    this->scene->addChild(background->getSprite(), 999);
}

void GameStorySystem::removeStory() {

    EntityManager* entityManager = EntityManager::getInstance();
    LabelComponent* label = (LabelComponent*)entityManager->getEntity("story")->getComponent(1);
    SpriteComponent* btn = (SpriteComponent*)entityManager->getEntity("story")->getComponent(2);
    SpriteComponent* background = (SpriteComponent*)entityManager->getEntity("story")->getComponent(3);

    auto fadeOut = FadeOut::create(2.0f);

    label->getLabel()->runAction(fadeOut->clone());
    btn->getSprite()->runAction(fadeOut->clone());
    background->getSprite()->runAction(fadeOut->clone());

}

void GameStorySystem::drawEndScreen(string text) {

    EntityManager* entityManager = EntityManager::getInstance();
    LabelComponent* label = (LabelComponent*)entityManager->getEntity("story")->getComponent(1);
    SpriteComponent* btn = (SpriteComponent*)entityManager->getEntity("story")->getComponent(2);
    SpriteComponent* background = (SpriteComponent*)entityManager->getEntity("story")->getComponent(3);

    auto fadeIn = FadeIn::create(2.0f);

    label->getLabel()->runAction(fadeIn->clone());
    btn->getSprite()->runAction(fadeIn->clone());
    background->getSprite()->runAction(fadeIn->clone());
    btn->getSprite()->setTag(2);

    label->getLabel()->setString(text);

}
