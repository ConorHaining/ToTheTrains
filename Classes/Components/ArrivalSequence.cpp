//
// Created by conor on 28/03/18.
//

#include "ArrivalSequence.h"

cocos2d::MoveTo *ArrivalSequence::getMovement() const {
    return movement;
}

void ArrivalSequence::setMovement(StoppingLocation stoppingLocation) {
    movement = cocos2d::MoveTo::create(3, cocos2d::Vec2(stoppingLocation.getX(), stoppingLocation.getY()));
}