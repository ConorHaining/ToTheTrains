//
// Created by conor on 29/03/18.
//

#ifndef PROJ_ANDROID_STUDIO_SPRITECOMPONENT_H
#define PROJ_ANDROID_STUDIO_SPRITECOMPONENT_H


#include "cocos2d.h";
#include "../ComponentInterface.h"

class SpriteComponent : public ComponentInterface{
private:
    cocos2d::Sprite* sprite;

public:
    void createSprite(std::string resource);
    cocos2d::Sprite* getSprite();
};


#endif //PROJ_ANDROID_STUDIO_SPRITE_H
