//
// Created by conor on 25/02/18.
//

#ifndef PROJ_ANDROID_STUDIO_STOP_H
#define PROJ_ANDROID_STUDIO_STOP_H


class Stop {
private:

    Platform platform;
    GameTime scheduledArrivalTime;
    GameTime scheduledDepartureTime;
    GameTime actualArrivalTime;
    GameTime actualDepartureTime;
    Train train;
    Disruption disruption;

public:

    bool isDisruption();
};


#endif //PROJ_ANDROID_STUDIO_STOP_H
