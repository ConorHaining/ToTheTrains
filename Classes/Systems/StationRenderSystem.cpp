//
// Created by conor on 29/03/18.
//

#include "cocos2d.h"
#include <EntityManager.h>
#include "StationRenderSystem.h"
#include "../Components/SpriteComponent.h"

USING_NS_CC;

StationRenderSystem::StationRenderSystem(cocos2d::Scene *scene, EntityInterface *station) {
    this->scene = scene;
    this->station = station;
    log("Assigned Scene & Staton to System");
}

void StationRenderSystem::drawStation() {
    SpriteComponent* sprite = (SpriteComponent*)this->station->getComponent(1);
    log("Got Sprite");
    auto dirs = Director::getInstance();
    Size visibleSize = dirs->getVisibleSize();

    sprite->getSprite()->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));

    this->scene->addChild(sprite->getSprite());
}
