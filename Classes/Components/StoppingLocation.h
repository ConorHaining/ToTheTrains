//
// Created by conor on 04/03/18.
//

#ifndef PROJ_ANDROID_STUDIO_STOPPINGLOCATION_H
#define PROJ_ANDROID_STUDIO_STOPPINGLOCATION_H


#include <ComponentInterface.h>

class StoppingLocation : public ComponentInterface {
private:
    int x;
    int y;
public:
    int getX() const;
    void setX(int x);

    int getY() const;
    void setY(int y);
};


#endif //PROJ_ANDROID_STUDIO_STOPPINGLOCATION_H
