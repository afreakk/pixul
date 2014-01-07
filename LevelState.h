#pragma once
enum class LevelEnums
{
    LEVEL_ONE,
    LEVEL_TWO,
    LEVEL_THREE
};
class LevelState
{
    public:
        LevelState(const LevelEnums ID):LevelID(ID)
        {
        }
        virtual LevelEnums update()=0;
        virtual void handleEvent(const SDL_Event& evnt)=0;
        virtual void render()=0;
        ~LevelState()
        {
        }
        const LevelEnums LevelID;
        
};

