//
// Created by Conor Haining on 11/05/2018.
//

#ifndef PROJ_ANDROID_STUDIO_SCORESYSTEM_H
#define PROJ_ANDROID_STUDIO_SCORESYSTEM_H


#include <Components/Time.h>
#include "TrainManagementSystem.h"

class ScoreSystem {
public:
    void updateScore(Time* currentTime, Time departureTime);
    ScoreSystem(Scene* scene);
    void drawScore();
    void drawScoreFirst();

private:
    Scene* scene;
};


#endif //PROJ_ANDROID_STUDIO_SCORESYSTEM_H
