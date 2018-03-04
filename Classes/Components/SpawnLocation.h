//
// Created by conor on 04/03/18.
//

#ifndef PROJ_ANDROID_STUDIO_SPAWNLOCATION_H
#define PROJ_ANDROID_STUDIO_SPAWNLOCATION_H


class SpawnLocation {
private:
    int x;
    int y;
public:
    int getY() const;
    void setY(int y);

    int getX() const;
    void setX(int x);
};


#endif //PROJ_ANDROID_STUDIO_SPAWNLOCATION_H
