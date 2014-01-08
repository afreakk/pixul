#include "Engine.h"
#include "Timer.h"
Uint32 setFPSinTitle(Uint32 interval, void *param)
{
    double deltaTime = Timer::getInstance()->deltaTimeD();
    if(deltaTime != 0)
    {
        double fps = 1.0/deltaTime;
        if(fps)
        {
            string fpsText = "FPS: " + boost::lexical_cast<string>(fps); 
            Engine::getInstance()->setWindowTitle( fpsText.c_str() );
        }
    }
    return (interval);
}
int delay = 1500;
SDL_TimerID FPS_TIMER_ID = SDL_AddTimer(delay, setFPSinTitle, nullptr);
