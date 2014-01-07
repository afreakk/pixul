#pragma once

#include "LevelState.h"
#include "Engine.h"
#include "LevelStateOne.h"
#include "LevelStateTwo.h"
class LevelManager
{
    public:
        LevelManager()
        {
            m_state = new LevelStateOne();
        }
        ~LevelManager()
        {
            delete m_state;
        }
        int go()
        {
            while(!m_quit)
                systemLoop();
            return 0;
        }
        static bool m_quit;
    private:
        void systemLoop()
        {
            Timer::getInstance()->update();
            systemHandleEvent(Engine::getInstance()->getEvent());
            systemUpdate();
            systemRender();
        }
        void systemUpdate()
        {
            LevelEnums nextLevel = m_state->update();
            if(nextLevel!=m_state->LevelID)
                changeLevelState(nextLevel);
        }
        void systemRender()
        {
            Engine::getInstance()->clearScreen();
            m_state->render();
            SDL_RenderPresent(Engine::getInstance()->getRenderer());
        }
        void systemHandleEvent(SDL_Event& evnt)
        {
            while(SDL_PollEvent(&evnt) != 0)
            {
                m_state->handleEvent(evnt);
                if(evnt.key.keysym.sym == SDLK_ESCAPE)
                    m_quit = true;
                switch(evnt.type)
                {
                    case SDL_QUIT: m_quit = true; break;
                }
            }
        }
        void changeLevelState(const LevelEnums newLevelID)
        {
            delete m_state;
            switch(newLevelID)
            {
                case LevelEnums::LEVEL_ONE:   m_state = new LevelStateOne();   break;
                case LevelEnums::LEVEL_TWO:   m_state = new LevelStateTwo();   break;
                case LevelEnums::LEVEL_THREE: m_state = new LevelStateThree(); break;
            }
        }
        LevelState* m_state;
};
bool        LevelManager::m_quit{false};
