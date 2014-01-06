#pragma once
#include "LevelState.h"
#include "Player.h"
#include "Ground.h"
class LevelStateOne: public LevelState
{
    public:
        LevelStateOne()
        {
            LevelState::LevelID = LEVEL_ONE;
        }
        LevelEnums update()
        {
            m_player.update();
            return LEVEL_ONE;
        }
        void handleEvent(SDL_Event& evnt)
        {
            m_player.handleEvent(evnt);
        }
        void render()
        {
            m_player.draw();
            m_ground.draw();
        }
    private:
        Player m_player;
        Ground m_ground;
        
};

class LevelStateTwo: public LevelState
{
    public:
        LevelStateTwo()
        {
            LevelState::LevelID = LEVEL_TWO;
        }
        LevelEnums update()
        {
            return LEVEL_TWO;
        }
        void handleEvent(SDL_Event& evnt)
        {
        }
        void render()
        {
        }
};
class LevelStateThree: public LevelState
{
    public:
        LevelStateThree()
        {
            LevelState::LevelID = LEVEL_THREE;
        }
        LevelEnums update()
        {
            return LEVEL_THREE;
        }
        void handleEvent(SDL_Event& evnt)
        {
        }
        void render()
        {
        }
};
