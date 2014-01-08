#pragma once
#include "LevelState.h"
#include "Player.h"
#include "Ground.h"
#include "PixelCanvas.h"
#include "PixelDataPublisher.h"
class LevelStateOne: public LevelState
{
    public:
        LevelStateOne():LevelState(LevelEnums::LEVEL_ONE)
        {
            m_pixelDataPublisher.registerEditor(&m_player);
            m_pixelDataPublisher.registerSubscriber(&m_pixelCanvas);
            m_pixelDataPublisher.addPoints(m_ground.getAllPoints());
        }
        LevelEnums update() override
        {
            m_player.update();
            m_pixelDataPublisher.updateData();
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
        PixelDataPublisher m_pixelDataPublisher;
        
};

