//
// Created by conor on 29/03/18.
//

#include "Sprite.h"

void Sprite::createSprite(std::string resource) {
    sprite = cocos2d::Sprite::create(resource);
}

cocos2d::Sprite* Sprite::getSprite() {
    return sprite;
}
