//
// Created by conor on 03/03/18.
//

#ifndef PROJ_ANDROID_STUDIO_ENTITYMANAGER_H
#define PROJ_ANDROID_STUDIO_ENTITYMANAGER_H


#include <vector>
#include <string>
#include "EntityInterface.h"
#include "ComponentInterface.h"

struct EntityStorage{
    std::string tag;
    EntityInterface* entity;
};

struct ComponentStorage{
    std::string tag;
    ComponentInterface* component;
};

class EntityManager {
private:
    /**
     * Make the manager a singleton to avoid any possible confusion
     * which may arise with multiple managers.
     */
    static EntityManager* instance;
    EntityManager();

    std::vector<EntityStorage> entities {};
    std::vector<ComponentStorage> components {};

public:

    static EntityManager* getInstance();

    void createEntity(std::string tag, EntityInterface* entity);
    EntityInterface* getEntity(std::string tag);
    void deleteEntity(std::string tag);

    void createComponent(std::string tag, ComponentInterface* component);
    ComponentInterface* getComponent(std::string tag);
    void deleteComponent(std::string tag);


    void addEntityToComponent(EntityInterface* entity, ComponentInterface* component);
};



#endif //PROJ_ANDROID_STUDIO_ENTITYMANAGER_H
