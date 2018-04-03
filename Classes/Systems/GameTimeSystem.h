//
// Created by conor on 03/04/18.
//

#ifndef PROJ_ANDROID_STUDIO_GAMETIMESYSTEM_H
#define PROJ_ANDROID_STUDIO_GAMETIMESYSTEM_H


class GameTimeSystem {
private:
    const int multipler = 60;
public:
    void setTime(int hour, int minute);
    void incrementTime(float delta);
    void drawTime();
};


#endif //PROJ_ANDROID_STUDIO_GAMETIMESYSTEM_H
