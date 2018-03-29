//
// Created by conor on 03/03/18.
//

#ifndef PROJ_ANDROID_STUDIO_ENTITYMANAGER_H
#define PROJ_ANDROID_STUDIO_ENTITYMANAGER_H


#include <vector>
#include "EntityInterface.h"
#include "ComponentInterface.h"

class EntityManager {
private:
    /**
     * Make the manager a singleton to avoid any possible confusion
     * which may arise with multiple managers.
     */
    static EntityManager* instance;
    EntityManager();

    std::vector<EntityInterface*> entities;
    std::vector<ComponentInterface> components;

public:

    static EntityManager* getInstance();

    int createEntity(EntityInterface* entity);
    EntityInterface* getEntity(int id);
    void deleteEntity(int id);

    void createComponent(ComponentInterface component);
    ComponentInterface getComponent(int id);
    void deleteComponent(int id);


    void addEntityToComponent(EntityInterface entity, ComponentInterface component);
};



#endif //PROJ_ANDROID_STUDIO_ENTITYMANAGER_H
