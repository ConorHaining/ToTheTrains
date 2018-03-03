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

}

EntityInterface EntityManager::getEntity(int id) {
    return EntityInterface();
}

void EntityManager::deleteEntity(int id) {

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
