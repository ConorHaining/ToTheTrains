//
// Created by conor on 29/03/18.
//

#ifndef PROJ_ANDROID_STUDIO_STATIONRENDERSYSTEM_H
#define PROJ_ANDROID_STUDIO_STATIONRENDERSYSTEM_H


#include <2d/CCScene.h>
#include <EntityInterface.h>

class StationRenderSystem {
private:
    cocos2d::Scene* scene;
    EntityInterface* station;
public:
    StationRenderSystem(cocos2d::Scene* scene, EntityInterface* station);
    void drawStation();
};


#endif //PROJ_ANDROID_STUDIO_STATIONRENDERSYSTEM_H
