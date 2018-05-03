//
// Created by conor on 04/03/18.
//

#ifndef PROJ_ANDROID_STUDIO_DESPAWNLOCATION_H
#define PROJ_ANDROID_STUDIO_DESPAWNLOCATION_H


#include <ComponentInterface.h>

class DespawnLocation : public ComponentInterface {
private:
    int x;
    int y;
public:
    int getY() const;
    void setY(int y);

    int getX() const;
    void setX(int x);
};


#endif //PROJ_ANDROID_STUDIO_DESPAWNLOCATION_H
