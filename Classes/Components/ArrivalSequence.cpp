//
// Created by conor on 28/03/18.
//

#include "ArrivalSequence.h"

cocos2d::EaseOut *ArrivalSequence::getMovement() const {
    return movement;
}

void ArrivalSequence::setMovement(StoppingLocation* stoppingLocation) {
    cocos2d::MoveTo* moving = cocos2d::MoveTo::create(3, cocos2d::Vec2(stoppingLocation->getX(), stoppingLocation->getY()));
    movement = cocos2d::EaseOut::create(moving->clone(), 1);
}