#pragma once
#include <vector>
#include <SDL2/SDL.h>
using namespace std;
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
        vector <SDL_Point>& getAllPoints()
        {
            return m_allPoints;
        }
    private:
        void initBorders()
        {
            vector <SDL_Point> m_topGraphics;
            vector <SDL_Point> m_bottomGraphics;
            vector <SDL_Point> m_leftGraphics;
            vector <SDL_Point> m_rightGraphics;
            injectCube(m_topGraphics    ,0,0                                                , Engine::m_screenWidth, Engine::m_screenHeight/50); //top
            injectCube(m_bottomGraphics ,0,Engine::m_screenHeight-Engine::m_screenHeight/50 , Engine::m_screenWidth, Engine::m_screenHeight);//bottom

            injectCube(m_leftGraphics   ,0                                              ,0, Engine::m_screenWidth/50, Engine::m_screenHeight); //left
            injectCube(m_rightGraphics  ,Engine::m_screenWidth-Engine::m_screenWidth/50 ,0, Engine::m_screenWidth   , Engine::m_screenHeight); 

            for(auto itt = m_bottomGraphics.begin(); itt != m_bottomGraphics.end(); ++itt)
                m_allPoints.push_back(*itt);
            for(auto itt = m_topGraphics.begin(); itt != m_topGraphics.end(); ++itt)
                m_allPoints.push_back(*itt);
            for(auto itt = m_leftGraphics.begin(); itt != m_leftGraphics.end(); ++itt)
                m_allPoints.push_back(*itt);
            for(auto itt = m_rightGraphics.begin(); itt != m_rightGraphics.end(); ++itt)
                m_allPoints.push_back(*itt);
        }
        vector <SDL_Point> m_allPoints;
};
