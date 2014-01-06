#pragma once

#include <SDL2/SDL.h>
#include <iostream>
#include "Timer.h"
class Engine
{
    public:
        Engine()
        {
        }
        ~Engine()
        {
            SDL_Quit();
        }
        int init()
        {
            if (SDL_Init(SDL_INIT_EVERYTHING) == -1){
                std::cout << SDL_GetError() << std::endl;
                return 1;
            }

            m_window = SDL_CreateWindow(" ~ ", SDL_WINDOWPOS_CENTERED, 
                SDL_WINDOWPOS_CENTERED, m_screenWidth, m_screenHeight, SDL_WINDOW_SHOWN);
            if (m_window == nullptr){
                std::cout << SDL_GetError() << std::endl;
                return 2;
            }
            m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED 
                | SDL_RENDERER_PRESENTVSYNC);
            if (m_renderer == nullptr){
                std::cout << SDL_GetError() << std::endl;
                return 3;
            }
            return 0;
        }
        static const int m_screenWidth{640};
        static const int m_screenHeight{480};
        static SDL_Window *m_window;
        static SDL_Renderer *m_renderer;
        static SDL_Event m_event;
        static Timer m_timer;
    private:
 
};
SDL_Window* Engine::m_window{nullptr};
SDL_Renderer* Engine::m_renderer{nullptr};
SDL_Event Engine::m_event;
Timer Engine::m_timer;
