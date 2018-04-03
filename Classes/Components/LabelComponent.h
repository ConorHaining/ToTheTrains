//
// Created by conor on 03/04/18.
//

#ifndef PROJ_ANDROID_STUDIO_LABELCOMPONENT_H
#define PROJ_ANDROID_STUDIO_LABELCOMPONENT_H

#include "cocos2d.h"
#include "../ComponentInterface.h"

USING_NS_CC;

class LabelComponent : public ComponentInterface{
private:
    Label* label;
public:
    void createLabel(std::string text);
    Label* getLabel();
};


#endif //PROJ_ANDROID_STUDIO_LABELCOMPONENT_H
