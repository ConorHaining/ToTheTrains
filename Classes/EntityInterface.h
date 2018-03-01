//
// Created by conor on 01/03/18.
//

#ifndef PROJ_ANDROID_STUDIO_ENTITYINTERFACE_H
#define PROJ_ANDROID_STUDIO_ENTITYINTERFACE_H


class EntityInterface {
private:
    int EntityID;
    bool markedForDeletion;

public:
    EntityInterface();
    virtual ~EntityInterface();
    virtual int getID();
    virtual void markForDeletion();
    virtual bool isMarkedForDeletion();
};


#endif //PROJ_ANDROID_STUDIO_ENTITYINTERFACE_H
