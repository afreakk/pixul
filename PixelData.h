#pragma once
#include <boost/lexical_cast.hpp>
#include <string>
#include <SDL2/SDL.h>
using namespace std;
string pointToString(const SDL_Point& point)
{
    return (boost::lexical_cast<string>(point.x)+"."+boost::lexical_cast<string>(point.y));
}
#include "Utils.h"
#include <vector>
#include <map>
class PixelData
{
    public:
        PixelData():m_minimalPixels(nullptr),m_didUpdate(false)
        {
        }
        ~PixelData()
        {
            delete[] m_minimalPixels;
        }
        void addPoints(const vector<SDL_Point>& points)
        {
            for(const auto point : points)
            {
                string entry = pointToString(point);
                m_pixelMap[ entry ] = point;
            }
            process();
        }
        void removePixel(const SDL_Point& coordinate)
        {
            string entry = pointToString(coordinate);
            m_pixelMap.erase(entry);
            process();
        }
        SDL_Point* getMinimalPixels() const
        {
           return m_minimalPixels; 
        }
        unsigned int getSize() const
        {
            return m_pixelMap.size();
        }
        bool didUpdate() const
        {
            return m_didUpdate;
        }
        void resetDidUpdate() 
        {
            m_didUpdate = false;
        }
    private:
        void process()
        {
            m_minimalPixels= new SDL_Point[m_pixelMap.size()];
            int i=0;
            for(auto pixelMapItterator : m_pixelMap)
                m_minimalPixels[i++] = pixelMapItterator.second;
            m_didUpdate = true;
        }

        map<string,SDL_Point>   m_pixelMap;
        SDL_Point*              m_minimalPixels;
        bool                    m_didUpdate;

};
