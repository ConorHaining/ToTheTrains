//
// Created by conor on 04/03/18.
//

#include "StoppingLocation.h"

int StoppingLocation::getLength() const {
    return length;
}

void StoppingLocation::setLength(int length) {
    StoppingLocation::length = length;
}

const std::string &StoppingLocation::getTrainClass() const {
    return trainClass;
}

void StoppingLocation::setTrainClass(const std::string &trainClass) {
    StoppingLocation::trainClass = trainClass;
}
