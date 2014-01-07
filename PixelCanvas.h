#pragma once

#include <SDL2/SDL.h>
#include "PixelDataReceiver.h"
class PixelCanvas : public PixelDataReceiver
{
    public:
        PixelCanvas():m_color{0,150,40,255}
        {
        }
        ~PixelCanvas()
        {
        }
        void receivePixelData(const PixelData& pixelData) override
        {
            m_graphics = pixelData.getMinimalPixels();
            m_size = pixelData.getSize();
        }
        void draw()
        {
            SDL_SetRenderDrawColor(Engine::getInstance()->getRenderer(), m_color.r, m_color.g, m_color.b, m_color.a);
            SDL_RenderDrawPoints( Engine::getInstance()->getRenderer(), m_graphics, m_size );
        }
    private:
        SDL_Color m_color;
        SDL_Point* m_graphics;
        unsigned int m_size;

};
