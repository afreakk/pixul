#pragma once
#include "Singleton.h"
#include <SDL2/SDL.h>
#include "Utils.h"
class Timer : public Singleton<Timer>
{
    public:
        void update()
        {
            Uint32 lastTime = m_currentTime;
            m_currentTime = SDL_GetTicks();
            m_deltaTime = m_currentTime-lastTime;

            m_dCurrentTime = intToDouble(m_currentTime)/1000.0;
            m_dDeltaTime = intToDouble(m_deltaTime)/1000.0;
        }
        Uint32 deltaTime()
        {
            return m_deltaTime;
        }
        Uint32 currentTime()
        {
            return m_currentTime;
        }
        double deltaTimeD()
        {
            return m_dDeltaTime;
        }
        double currentTimeD()
        {
            return m_dCurrentTime;
        }

    private:
        Timer():m_currentTime(0),m_deltaTime(0)
        {
        }
        Uint32 m_currentTime;
        Uint32 m_deltaTime;
        double m_dDeltaTime;
        double m_dCurrentTime;
        friend class Singleton<Timer>;
};
