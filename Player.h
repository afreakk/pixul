#pragma once

#include <SDL2/SDL.h>
#include "Utils.h"
#include <vector>
#include "Engine.h"
#include "Gravity.h"
#include "PixelData.h"
using namespace std;
class Player
{
    public: 
        Player():m_radius(10), m_position{Engine::m_screenWidth/2, Engine::m_screenHeight/2}, m_color{255, 150, 140, 255}, downPull(true)
        {
            m_playerGravity = Gravity(&m_position, 100.0f, 1000.0f);
        }
        ~Player()
        {
        }
        void handleEvent(SDL_Event& evnt)
        {
            switch(evnt.type)
            {
                case SDL_KEYDOWN: keyDown(evnt.key.keysym.sym); break;
            }
        }
        void update()
        {
            m_playerGravity.update();
            circle(m_position.x, m_position.y, m_radius, m_graphics);
        }
        void draw()
        {
            SDL_SetRenderDrawColor(Engine::m_renderer, m_color.r, m_color.g, m_color.b, m_color.a);
            SDL_RenderDrawPoints( Engine::m_renderer, &m_graphics[0], m_graphics.size() );
        }
        void hitTest(PixelData& pixelData)
        {
            for(auto pixel = m_graphics.begin(); pixel != m_graphics.end(); ++pixel)
            {
                pixelData.removePixel(*pixel);
            }
        }
    private:
        void keyDown(SDL_Keycode button)
        {
            bool copyOfInvertGravity = downPull;
            switch(button)
            {
                case SDLK_w: downPull=false; break;
                case SDLK_s: downPull=true; break;
            }
            if(copyOfInvertGravity != downPull)
                m_playerGravity.setDownPull(downPull);
        }
        vector <SDL_Point> m_graphics;
        bool downPull;
        SDL_Point m_position;
        SDL_Color m_color;
        Gravity m_playerGravity;
        int m_radius;


};
