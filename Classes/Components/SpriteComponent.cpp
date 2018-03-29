//
// Created by conor on 29/03/18.
//

#include <string>
#include "SpriteComponent.h"

void SpriteComponent::createSprite(std::string resource) {
    sprite = cocos2d::Sprite::create(resource);
}

cocos2d::Sprite* SpriteComponent::getSprite() {
    return sprite;
}
