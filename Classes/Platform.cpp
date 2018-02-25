//
// Created by conor on 25/02/18.
//

#include "Platform.h"

Platform::Platform(std::string platformLabel, Vec2 drawLocation, Vec2 stoppingLocation) {
    this->platformLabel = platformLabel;
    this->drawLocation = drawLocation;
    this->stoppingLocation = stoppingLocation;
}

std::string Platform::getPlatformLabel() {
    return this->platformLabel;
}

Vec2 Platform::getDrawLocation() {
    return this->drawLocation;
}

Vec2 Platform::getStoppingLocation() {
    return this->stoppingLocation;
}
