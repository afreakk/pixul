#include "Engine.h"
#include "LevelManager.h"
int main()
{
    Engine engine;
    int SDL_RETURN_VALUE = engine.init();
    if(SDL_RETURN_VALUE)
        return SDL_RETURN_VALUE;
    LevelManager levelManager;
    return levelManager.go();
 
}
