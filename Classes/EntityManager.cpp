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
    int size = this->components.capacity();

    this->components[size] = component;
}

ComponentInterface EntityManager::getComponent(int id) {

    return this->components[id];

}

void EntityManager::deleteComponent(int id) {

    ComponentInterface component = this->getComponent(id);

    delete component;

    this->components[id] = nullptr;

}

void EntityManager::addEntityToComponent(EntityInterface entity, ComponentInterface component) {

}
