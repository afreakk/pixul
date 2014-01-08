#pragma once
#include "Singleton.h"
#include <SDL2/SDL.h>
#include <iostream>
using namespace std;
class Engine : public Singleton<Engine>
{
    public:
        int init(SDL_Color bgColor, unsigned screenWidth, unsigned screenHeight)
        {
            m_bgColor = bgColor;
            m_screenWidth = screenWidth;
            m_screenHeight = screenHeight;

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
        void kill()
        {
            SDL_Quit();
        }
        void clearScreen()
        {
            SDL_SetRenderDrawColor(m_renderer, m_bgColor.r, m_bgColor.g, m_bgColor.b, m_bgColor.a);
            SDL_RenderClear(m_renderer);
        }
        const SDL_Window* getWindow()
        {
            return m_window;
        }
        SDL_Renderer* getRenderer()
        {
            return m_renderer;
        }
        SDL_Event& getEvent()
        {
            return m_event;
        }
        SDL_Color& getBgColor()
        {
            return m_bgColor;
        }
        unsigned getScreenWidth()
        {
            return m_screenWidth;
        }
        unsigned getScreenHeight()
        {
            return m_screenHeight;
        }
        void setWindowTitle(const char* title)
        {
            cout << "nowTitle: "<< title<< endl;
            SDL_SetWindowTitle(m_window,title);
        }
    private:
        unsigned m_screenWidth;
        unsigned m_screenHeight;
        SDL_Color m_bgColor;
        SDL_Event m_event;

        SDL_Window *m_window;
        SDL_Renderer *m_renderer;

        Engine():m_window{nullptr}, m_renderer{nullptr},m_screenWidth(0),m_screenHeight(0)
        {
        }

        friend class Singleton<Engine>;
 
};

