//
// Created by Conor Haining on 11/05/2018.
//

#include "ScoreComponent.h"

int ScoreComponent::getScore() const {
    return score;
}

void ScoreComponent::setScore(int score) {
    ScoreComponent::score = score;
}
