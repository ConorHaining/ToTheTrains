//
// Created by conor on 01/03/18.
//

#ifndef PROJ_ANDROID_STUDIO_ENTITYINTERFACE_H
#define PROJ_ANDROID_STUDIO_ENTITYINTERFACE_H


#include <vector>
#include "ComponentInterface.h"

class EntityInterface {
private:
    int EntityID;
    bool markedForDeletion;
    std::vector<ComponentInterface*> attachedComponents;

public:
    EntityInterface();
    virtual ~EntityInterface();
    virtual int getID();
    virtual void markForDeletion();
    virtual bool isMarkedForDeletion();
    void attachComponent(ComponentInterface* component);
    ComponentInterface* getComponent(int id);
};


#endif //PROJ_ANDROID_STUDIO_ENTITYINTERFACE_H
