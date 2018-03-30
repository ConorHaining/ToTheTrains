//
// Created by conor on 03/03/18.
//

#include "EntityManager.h"

EntityManager* EntityManager::instance = 0;

EntityManager::EntityManager() { }

EntityManager *EntityManager::getInstance() {

    if (instance == 0) {
        instance = new EntityManager();
    }

    return instance;


}

void EntityManager::createEntity(std::string tag, EntityInterface* entity) {

    // Create new struct
    EntityStorage entityStorage;

    entityStorage.tag = tag;
    entityStorage.entity = entity;

    // Store struct
    this->entities.push_back(entityStorage);

}

EntityInterface* EntityManager::getEntity(int id) {

    return this->entities[id];
}

void EntityManager::deleteEntity(int id) {

    EntityInterface* entity = this->getEntity(id);

    entity->markForDeletion();

    this->entities.erase(this->entities.begin() + id);

}

void EntityManager::createComponent(ComponentInterface* component) {
    int size = this->components.capacity();

    this->components[size] = component;
}

ComponentInterface* EntityManager::getComponent(int id) {

    return this->components[id];

}

void EntityManager::deleteComponent(int id) {

    ComponentInterface* component = this->getComponent(id);

//    delete component;

    this->entities.erase(this->entities.begin() + id);

}

void EntityManager::addEntityToComponent(EntityInterface* entity, ComponentInterface* component) {
    entity->attachComponent(component);
}
