//
// Created by conor on 29/03/18.
//

#include <string>
#include <iostream>
#include "SpriteComponent.h"

void SpriteComponent::createSprite(std::string resource) {
    sprite = Sprite::create(resource);
    std::cout << resource << std::endl;
}

Sprite* SpriteComponent::getSprite() {
    return sprite;
}
