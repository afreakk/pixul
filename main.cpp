#include "Engine.h"
#include "LevelManager.h"
#include "Timer.h"
#include "setFPS.h"
int main()
{
    //init
    Engine* engine = Engine::getInstance();
    Timer* timer = Timer::getInstance();
    SDL_Color backgroundColor;
    backgroundColor.r = 100, backgroundColor.g = 50, backgroundColor.b = 100, backgroundColor.a = 255;
    int SDL_RETURN_VALUE = engine->init(backgroundColor,640,480);
    if(SDL_RETURN_VALUE)
        return SDL_RETURN_VALUE;
    LevelManager levelManager;

    //start stateManager
    levelManager.go();

    //cleanup
    engine->kill();
    Engine::destroyInstance();
    Timer::destroyInstance();

    return 0;
}
