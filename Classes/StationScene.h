#ifndef __STATION_SCENE_H__
#define __STATION_SCENE_H__

#include "cocos2d.h"
#include "Systems/GameTimeSystem.h"

class StationScene : public cocos2d::Scene
{
private:
    GameTimeSystem* gameTimeSystem;
    TimetableSystem* timetableSystem;
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    void update(float delta) override;
    
    // implement the "static create()" method manually
    CREATE_FUNC(StationScene);
};

#endif // __STATION_SCENE_H__
