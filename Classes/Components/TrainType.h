//
// Created by conor on 04/03/18.
//

#ifndef PROJ_ANDROID_STUDIO_STOPPINGLOCATION_H
#define PROJ_ANDROID_STUDIO_STOPPINGLOCATION_H


#include <string>

class TrainType {
private:
    int length;
    std::string trainClass;
public:
    const std::string &getTrainClass() const;
    void setTrainClass(const std::string &trainClass);

    int getLength() const;
    void setLength(int length);
};


#endif //PROJ_ANDROID_STUDIO_STOPPINGLOCATION_H
