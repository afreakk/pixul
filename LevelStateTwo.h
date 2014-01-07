
class LevelStateTwo: public LevelState
{
    public:
        LevelStateTwo():LevelState(LevelEnums::LEVEL_TWO)
        {
        }
        LevelEnums update() override
        {
            return LevelEnums::LEVEL_TWO;
        }
        void handleEvent(const SDL_Event& evnt) override
        {
        }
        void render() override
        {
        }
};
class LevelStateThree: public LevelState
{
    public:
        LevelStateThree():LevelState(LevelEnums::LEVEL_THREE)
        {
        }
        LevelEnums update() override
        {
            return LevelEnums::LEVEL_THREE;
        }
        void handleEvent(const SDL_Event& evnt) override
        {
        }
        void render() override
        {
        }
};
