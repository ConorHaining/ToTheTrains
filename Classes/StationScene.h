#ifndef __STATION_SCENE_H__
#define __STATION_SCENE_H__

#include <Systems/GameStorySystem.h>
#include "cocos2d.h"
#include "Systems/GameTimeSystem.h"
#include "Systems/TrainManagementSystem.h"
#include "Systems/ScoreSystem.h"
#include "Systems/StationRenderSystem.h"
#include "Systems/LevelCreationSystem.h"
#include "EntityManager.h"

class LevelCreationSystem;

class StationScene : public cocos2d::Scene
{
private:

    GameTimeSystem* gameTimeSystem;
    TrainManagementSystem* trainManagementSystem;
    ScoreSystem* scoreSystem;
    LevelCreationSystem* levelCreationSystem;
    StationRenderSystem* stationRenderSystem;
    GameStorySystem* gameStorySystem;

public:

    virtual bool init(string level);
    void update(float delta) override;

    bool doorControl(Touch *touch, Event *event);
    bool startGame(Touch *touch, Event *event);
    void moveCamera(Touch* touch, Event* event);

    static StationScene* create(string level);
};

#endif // __STATION_SCENE_H__
