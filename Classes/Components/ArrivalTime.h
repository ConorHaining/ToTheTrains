//
// Created by conor on 28/03/18.
//

#ifndef PROJ_ANDROID_STUDIO_ARRIVALTIME_H
#define PROJ_ANDROID_STUDIO_ARRIVALTIME_H


class ArrivalTime {
private:
    int hour;
    int minute;
    int second;

public:
    int getHour() const;

    void setHour(int hour);

    int getMinute() const;

    void setMinute(int minute);

    int getSecond() const;

    void setSecond(int second);

};


#endif //PROJ_ANDROID_STUDIO_ARRIVALTIME_H
