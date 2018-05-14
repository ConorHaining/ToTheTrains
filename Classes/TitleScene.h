//
// Created by Conor Haining on 12/05/2018.
//

#ifndef PROJ_ANDROID_STUDIO_TITLESCENE_H
#define PROJ_ANDROID_STUDIO_TITLESCENE_H


#include "cocos2d.h"

USING_NS_CC;

class TitleScene : public cocos2d::Scene
{
public:
    static Scene* createScene();

    virtual bool init();

    // implement the "static create()" method manually
    CREATE_FUNC(TitleScene);

private:
    Sprite* background;
    Sprite* play;
    Sprite* rules;
    Sprite* exit;

    bool onBeginTouch(Touch* touch, Event* event);
};


#endif //PROJ_ANDROID_STUDIO_TITLESCENE_H
