//
// Created by conor on 01/03/18.
//

#include "EntityInterface.h"

EntityInterface::EntityInterface() {
    // Generate new ID number

    this->markedForDeletion = false;

    this->attachedComponents.reserve(12);
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

void EntityInterface::attachComponent(ComponentInterface* component) {
//    attachedComponents.push_back(component);
    attachedComponents.push_back(component);
}

ComponentInterface *EntityInterface::getComponent(int id) {
    return attachedComponents[id - 1];
}
