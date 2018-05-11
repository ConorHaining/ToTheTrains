//
// Created by Conor Haining on 11/05/2018.
//

#ifndef PROJ_ANDROID_STUDIO_SCORECOMPONENT_H
#define PROJ_ANDROID_STUDIO_SCORECOMPONENT_H


#include <ComponentInterface.h>

class ScoreComponent : public ComponentInterface{
private:
    int score = 0;
public:
    int getScore() const;

    void setScore(int score);

};


#endif //PROJ_ANDROID_STUDIO_SCORECOMPONENT_H
