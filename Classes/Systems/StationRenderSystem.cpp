//
// Created by conor on 29/03/18.
//

#include "cocos2d.h"
#include <EntityManager.h>
#include "StationRenderSystem.h"
#include "../Components/SpriteComponent.h"

USING_NS_CC;

StationRenderSystem::StationRenderSystem(cocos2d::Scene *scene) {
    this->scene = scene;
    log("Assigned Scene & Staton to System");
}

void StationRenderSystem::drawStation() {

    EntityManager* entityManager = EntityManager::getInstance();
    SpriteComponent* sprite = (SpriteComponent*)entityManager->getEntity("Croy")->getComponent(1);
    log("Got Sprite");

    auto dirs = Director::getInstance();
    Size visibleSize = dirs->getVisibleSize();
    Vec2 origin = dirs->getVisibleOrigin();

    sprite->getSprite()->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

    this->scene->addChild(sprite->getSprite());
}
