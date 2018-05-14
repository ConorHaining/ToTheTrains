//
// Created by Conor Haining on 12/05/2018.
//

#ifndef PROJ_ANDROID_STUDIO_MENU_H
#define PROJ_ANDROID_STUDIO_MENU_H


#include "cocos2d.h"

USING_NS_CC;

class MenuScene : public cocos2d::Scene
{
public:
    static Scene* createScene();

    virtual bool init();

    // implement the "static create()" method manually
    CREATE_FUNC(MenuScene);

private:
    Sprite* background;
    Sprite* btn1;
    Sprite* btn2;
    Sprite* btn3;
    Sprite* btn4;
    Sprite* btn5;
    Sprite* btn6;
    Sprite* btn7;
    Sprite* btn8;
    Sprite* btn9;

    bool onBeginTouch(Touch* touch, Event* event);
};


#endif //PROJ_ANDROID_STUDIO_MENU_H
