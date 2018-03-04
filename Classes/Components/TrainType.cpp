//
// Created by conor on 04/03/18.
//

#include "TrainType.h"

int TrainType::getLength() const {
    return length;
}

void TrainType::setLength(int length) {
    TrainType::length = length;
}

const std::string &TrainType::getTrainClass() const {
    return trainClass;
}

void TrainType::setTrainClass(const std::string &trainClass) {
    TrainType::trainClass = trainClass;
}
