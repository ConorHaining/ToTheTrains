//
// Created by conor on 28/03/18.
//

#include "DepartureSequence.h"

cocos2d::MoveTo* DepartureSequence::getMovement(){
    return movement;
}

void DepartureSequence::setMovement(DespawnLocation* despawnLocation) {
    movement = cocos2d::MoveTo::create(3, cocos2d::Vec2(despawnLocation->getX(), despawnLocation->getY()));
}