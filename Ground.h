#pragma once
#include <vector>
#include <SDL2/SDL.h>
class Ground
{
    public:
        Ground()
        {
            initBorders();
        }
        ~Ground()
        {
        }
        std::vector <SDL_Point>& getAllPoints()
        {
            return m_allPoints;
        }
    private:
        void initBorders()
        {
            std::vector <SDL_Point> m_topGraphics;
            std::vector <SDL_Point> m_bottomGraphics;
            std::vector <SDL_Point> m_leftGraphics;
            std::vector <SDL_Point> m_rightGraphics;
            unsigned screenWidth = Engine::getInstance()->getScreenWidth();
            unsigned screenHeight= Engine::getInstance()->getScreenHeight();
            injectCube(m_topGraphics    ,0,0                                                , screenWidth, screenHeight/50);
            injectCube(m_bottomGraphics ,0,screenHeight-screenHeight/50 , screenWidth, screenHeight);

            injectCube(m_leftGraphics   ,0                                              ,0, screenWidth/50, screenHeight); 
            injectCube(m_rightGraphics  ,screenWidth-screenWidth/50 ,0, screenWidth   , screenHeight);

            for(auto itt = m_bottomGraphics.begin(); itt != m_bottomGraphics.end(); ++itt)
                m_allPoints.push_back(*itt);
            for(auto itt = m_topGraphics.begin(); itt != m_topGraphics.end(); ++itt)
                m_allPoints.push_back(*itt);
            for(auto itt = m_leftGraphics.begin(); itt != m_leftGraphics.end(); ++itt)
                m_allPoints.push_back(*itt);
            for(auto itt = m_rightGraphics.begin(); itt != m_rightGraphics.end(); ++itt)
                m_allPoints.push_back(*itt);
        }
        std::vector <SDL_Point> m_allPoints;
};
