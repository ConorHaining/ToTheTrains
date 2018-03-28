//
// Created by conor on 28/03/18.
//

#include "Satisfaction.h"

float Satisfaction::getTimeliness() const {
    return timeliness;
}

void Satisfaction::setTimeliness(float timeliness) {
    Satisfaction::timeliness = timeliness;
}

float Satisfaction::getHappiness() const {
    return happiness;
}

void Satisfaction::setHappiness(float happiness) {
    Satisfaction::happiness = happiness;
}

float Satisfaction::getInformation() const {
    return information;
}

void Satisfaction::setInformation(float information) {
    Satisfaction::information = information;
}
