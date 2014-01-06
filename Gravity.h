#pragma once
class Gravity
{
    public:
        Gravity()
        {
        }
        Gravity(SDL_Point* point,float acceleration,float maxVelocity)
            :m_point(point),m_downPull(true),m_absVelocity(1.0f)
             ,m_acceleration(acceleration), m_maxVelocity(maxVelocity),m_currentVelocity(1.0f)
        {
            m_fPoint.x = intToFloat(m_point->x);
            m_fPoint.y = intToFloat(m_point->y);
        }
        void update()
        {
            increaseABSVelocity();
            setCurrentVelocity();
            applyGravity();
        }
        void setDownPull(bool downpull)
        {
            m_absVelocity = 1.0f;
            m_downPull = downpull;
        }
        ~Gravity()
        {
        }
    private:
        void setCurrentVelocity()
        {
            switch(m_downPull)
            {
                case true: m_currentVelocity = m_absVelocity;break;
                case false: m_currentVelocity = -m_absVelocity;break;
            }
        }
        void increaseABSVelocity()
        {
            if(m_absVelocity < m_maxVelocity)
                m_absVelocity += m_acceleration*Engine::m_timer.deltaTimeD();
        }
        void applyGravity()
        {
            m_fPoint.y += m_currentVelocity*Engine::m_timer.deltaTimeD();
            m_point->y = floatToInt(m_fPoint.y);
        }
        SDL_Point* m_point;
        fPoint m_fPoint;
        bool m_downPull;
        float m_absVelocity;
        float m_currentVelocity;
        float m_maxVelocity;
        float m_acceleration;
};
