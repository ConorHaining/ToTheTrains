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
            (*it).entity->markForDeletion();
        }

    }

}

void EntityManager::createComponent(std::string tag, ComponentInterface* component) {

    // Create new struct
    ComponentStorage componentStorage;
    componentStorage.tag = tag;
    componentStorage.component = component;

    // Store struct
    components.push_back(componentStorage);
}

ComponentInterface* EntityManager::getComponent(std::string tag) {

    for (std::vector<ComponentStorage>::iterator it = components.begin() ; it != components.end(); ++it) {

        if((*it).tag == tag) {
            return (*it).component;
        }

    }

    return nullptr;

}

void EntityManager::deleteComponent(std::string tag) {

    for (std::vector<ComponentStorage>::iterator it = components.begin() ; it != components.end(); ++it) {

        if((*it).tag == tag) {
            //TODO Delete Components
            (*it).component;
        }

    }

}

void EntityManager::addEntityToComponent(EntityInterface* entity, ComponentInterface* component) {
    entity->attachComponent(component);
}
