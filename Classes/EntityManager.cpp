//
// Created by conor on 03/03/18.
//

#include "EntityManager.h"

EntityManager::instance = nullptr;

EntityManager::EntityManager() {

}

EntityManager *EntityManager::getInstance() {

    if (EntityManager::instance == nullptr) {
        EntityManager::instance = new EntityManager();
    }


}

int EntityManager::createEntity(EntityInterface entity) {

    int size = this->entities.capacity();

    this->entities[size] = entity;

}

EntityInterface EntityManager::getEntity(int id) {

    return this->entities[id];
}

void EntityManager::deleteEntity(int id) {

    EntityInterface entity = this->getEntity(id);

    entity.markForDeletion();

    this->entities[id] = nullptr;

}

void EntityManager::createComponent(ComponentInterface component) {

}

ComponentInterface EntityManager::getComponent(int id) {
    return ComponentInterface();
}

void EntityManager::deleteComponent(int id) {

}

void EntityManager::addEntityToComponent(EntityInterface entity, ComponentInterface component) {

}
