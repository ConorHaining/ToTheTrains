//
// Created by conor on 01/03/18.
//

#include "EntityInterface.h"

EntityInterface::EntityInterface() {
    // Generate new ID number

    this->markedForDeletion = false;
}

EntityInterface::~EntityInterface() {

}

int EntityInterface::getID() {
    return this->EntityID;
}

void EntityInterface::markForDeletion() {
    this->markedForDeletion = true;
}

bool EntityInterface::isMarkedForDeletion() {
    return this->markedForDeletion;
}