#pragma once

#include "LevelState.h"
#include "Engine.h"
#include "LevelStateOne.h"
class LevelManager
{
    public:
        LevelManager()
        {
            m_state = new LevelStateOne();
        }
        void update()
        {
            LevelEnums nextLevel = m_state->update();
            if(nextLevel!=m_state->LevelID)
                changeLevelState(nextLevel);
        }
        void render()
        {
            m_state->render();
        }
        ~LevelManager()
        {
            delete m_state;
        }
        int go()
        {
            while(!m_quit)
            {
                Engine::m_timer.update();
                while(SDL_PollEvent(&Engine::m_event) != 0)
                    handleEvent(Engine::m_event);
                update();
                SDL_SetRenderDrawColor(Engine::m_renderer, bgColor.r, bgColor.g, bgColor.b, bgColor.a);
                SDL_RenderClear(Engine::m_renderer);
                render();
                SDL_RenderPresent(Engine::m_renderer);
            }
            return 0;
        }
        static bool m_quit;
        static SDL_Color bgColor;
    private:
        void changeLevelState(LevelEnums newLevelID)
        {
            delete m_state;
            switch(newLevelID)
            {
                case LEVEL_ONE:   m_state = new LevelStateOne();   break;
                case LEVEL_TWO:   m_state = new LevelStateTwo();   break;
                case LEVEL_THREE: m_state = new LevelStateThree(); break;
            }
        }
        void handleEvent(SDL_Event& evnt)
        {
            m_state->handleEvent(evnt);
            if(evnt.key.keysym.sym == SDLK_ESCAPE)
                m_quit = true;
            switch(evnt.type)
            {
                case SDL_QUIT: m_quit = true; break;
            }
        }
        LevelState* m_state;
};
bool        LevelManager::m_quit{false};
SDL_Color   LevelManager::bgColor{255,255,255,255};
