#pragma once
#include "LevelState.h"
#include "Player.h"
#include "Ground.h"
#include "PixelCanvas.h"
#include "PixelDataHandler.h"
class LevelStateOne: public LevelState
{
    public:
        LevelStateOne():LevelState(LevelEnums::LEVEL_ONE)
        {
            m_pixelDataHandler.registerEditor(&m_player);
            m_pixelDataHandler.registerSubscriber(&m_pixelCanvas);
            m_pixelDataHandler.addPoints(m_ground.getAllPoints());
        }
        LevelEnums update() override
        {
            m_player.update();
            m_pixelDataHandler.write();
            return LevelEnums::LEVEL_ONE;
        }
        void handleEvent(const SDL_Event& evnt) override
        {
            m_player.handleEvent(evnt);
        }
        void render() override
        {
            m_player.draw();
            m_pixelCanvas.draw();
        }
    private:
        Player m_player;
        Ground m_ground;
        PixelCanvas m_pixelCanvas;
        PixelDataHandler m_pixelDataHandler;
        
};

