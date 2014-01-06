#pragma once
enum LevelEnums
{
    LEVEL_ONE,
    LEVEL_TWO,
    LEVEL_THREE
};
class LevelState
{
    public:
        LevelState()
        {
        }
        virtual LevelEnums update()=0;
        virtual void handleEvent(SDL_Event& evnt)=0;
        virtual void render()=0;
        ~LevelState()
        {
        }
        LevelEnums LevelID;
        
};

