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

EntityManager *EntityManager::resetInstance() {
    delete instance;
    instance = NULL;
}

void EntityManager::createEntity(std::string tag, EntityInterface* entity) {

    // Create new struct
    EntityStorage entityStorage;
    entityStorage.tag = tag;
    entityStorage.entity = entity;

    // Store struct
    entities.push_back(entityStorage);

}

EntityInterface* EntityManager::getEntity(std::string tag) {

    for (std::vector<EntityStorage>::iterator it = entities.begin() ; it != entities.end(); ++it) {

        if((*it).tag == tag) {
            return (*it).entity;
        }

    }

    return nullptr;
}

void EntityManager::deleteEntity(std::string tag) {

    for (std::vector<EntityStorage>::iterator it = entities.begin() ; it != entities.end(); ++it) {

        if((*it).tag == tag) {
            int i = 1 + 1;
            entities.erase(it);
            return;
        }

    }

}

ComponentInterface* EntityManager::getComponent(std::string tag) {

    for (std::vector<ComponentStorage>::iterator it = components.begin() ; it != components.end(); ++it) {

        if((*it).tag == tag) {
            return (*it).component;
        }

    }

    return nullptr;

}

void EntityManager::addEntityToComponent(EntityInterface* entity, ComponentInterface* component) {
    entity->attachComponent(component);
}
