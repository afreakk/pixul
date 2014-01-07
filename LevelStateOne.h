#pragma once
#include "LevelState.h"
#include "Player.h"
#include "Ground.h"
#include "PixelData.h"
#include "PixelCanvas.h"
class LevelStateOne: public LevelState
{
    public:
        LevelStateOne()
        {
            LevelState::LevelID = LEVEL_ONE;
            m_pixelData.addPoints(m_ground.getAllPoints());
        }
        LevelEnums update()
        {
            m_player.update();
            m_player.hitTest(m_pixelData);
            m_pixelData.process();
            m_pixelCanvas.update(m_pixelData);
            return LEVEL_ONE;
        }
        void handleEvent(SDL_Event& evnt)
        {
            m_player.handleEvent(evnt);
        }
        void render()
        {
            m_player.draw();
            m_pixelCanvas.draw();
        }
    private:
        Player m_player;
        Ground m_ground;
        PixelData m_pixelData;
        PixelCanvas m_pixelCanvas;
        
};

