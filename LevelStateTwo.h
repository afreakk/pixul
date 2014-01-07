
class LevelStateTwo: public LevelState
{
    public:
        LevelStateTwo()
        {
            LevelState::LevelID = LEVEL_TWO;
        }
        LevelEnums update()
        {
            return LEVEL_TWO;
        }
        void handleEvent(SDL_Event& evnt)
        {
        }
        void render()
        {
        }
};
class LevelStateThree: public LevelState
{
    public:
        LevelStateThree()
        {
            LevelState::LevelID = LEVEL_THREE;
        }
        LevelEnums update()
        {
            return LEVEL_THREE;
        }
        void handleEvent(SDL_Event& evnt)
        {
        }
        void render()
        {
        }
};
