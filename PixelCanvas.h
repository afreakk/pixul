#pragma once

#include <SDL2/SDL.h>
#include "PixelData.h"
using namespace std;
class PixelCanvas
{
    public:
        PixelCanvas():m_color{0,150,40,255}
        {
        }
        ~PixelCanvas()
        {
        }
        void update(PixelData& pixelData)
        {
            m_graphics = pixelData.getMinimalPixels();
            m_size = pixelData.getSize();
        }
        void draw()
        {
            SDL_SetRenderDrawColor(Engine::m_renderer, m_color.r, m_color.g, m_color.b, m_color.a);
            SDL_RenderDrawPoints( Engine::m_renderer, m_graphics, m_size );
        }
    private:
        SDL_Color m_color;
        SDL_Point* m_graphics;
        unsigned int m_size;

};
