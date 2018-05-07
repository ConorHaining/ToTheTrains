//
// Created by Conor Haining on 07/05/2018.
//

#ifndef PROJ_ANDROID_STUDIO_WARNINGPOSITION_H
#define PROJ_ANDROID_STUDIO_WARNINGPOSITION_H


#include "../ComponentInterface.h"

class WarningPosition : public ComponentInterface{
private:
    int x;
public:
    int getX() const;

    void setX(int x);

    int getY() const;

    void setY(int y);

private:
    int y;
};


#endif //PROJ_ANDROID_STUDIO_WARNINGPOSITION_H
