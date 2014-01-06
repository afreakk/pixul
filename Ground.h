#pragma once
#include <vector>
#include <SDL2/SDL.h>
using namespace std;
class Ground
{
    public:
        Ground():m_color{0,150,40,255}
        {
            injectCube(m_topGraphics,0,0, Engine::m_screenWidth, Engine::m_screenHeight/8);
            injectCube(m_bottomGraphics,0,Engine::m_screenHeight-Engine::m_screenHeight/8, Engine::m_screenWidth, Engine::m_screenHeight);
        }
        ~Ground()
        {
        }
        void draw()
        {
            SDL_SetRenderDrawColor(Engine::m_renderer, m_color.r, m_color.g, m_color.b, m_color.a);
            SDL_RenderDrawPoints( Engine::m_renderer, &m_topGraphics[0], m_topGraphics.size() );
            SDL_RenderDrawPoints( Engine::m_renderer, &m_bottomGraphics[0], m_bottomGraphics.size() );
        }
    private:
        vector <SDL_Point> m_topGraphics;
        vector <SDL_Point> m_bottomGraphics;
        SDL_Color m_color;
};
