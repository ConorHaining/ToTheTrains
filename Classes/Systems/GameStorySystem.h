//
// Created by Conor Haining on 13/05/2018.
//

#ifndef PROJ_ANDROID_STUDIO_GAMESTORYSYSTEM_H
#define PROJ_ANDROID_STUDIO_GAMESTORYSYSTEM_H

#include "cocos2d.h"
#include <string>

USING_NS_CC;
using namespace std;

class GameStorySystem {
private:
    Scene* scene;
public:
    void drawStory();
    void removeStory();
    void drawEndScreen(string text);

    GameStorySystem(Scene* scene);
};


#endif //PROJ_ANDROID_STUDIO_GAMESTORYSYSTEM_H
