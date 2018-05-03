//
// Created by conor on 28/03/18.
//

#ifndef PROJ_ANDROID_STUDIO_SATISFACTION_H
#define PROJ_ANDROID_STUDIO_SATISFACTION_H


#include <ComponentInterface.h>

class Satisfaction : public ComponentInterface {
private:
    float timeliness;
    float happiness;
    float information;

public:
    float getTimeliness() const;

    void setTimeliness(float timeliness);

    float getHappiness() const;

    void setHappiness(float happiness);

    float getInformation() const;

    void setInformation(float information);

};


#endif //PROJ_ANDROID_STUDIO_SATISFACTION_H
