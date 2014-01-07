#pragma once
#include "Utils.h"
#include <vector>
#include <map>
#include <string>
using namespace std;
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
            m_didUpdate = true;
        }
        void removePixel(const SDL_Point& coordinate)
        {
            string entry = pointToString(coordinate);
            if(!m_didUpdate && m_pixelMap.find( entry ) != m_pixelMap.end())
            {
                m_didUpdate = true;
                m_pixelMap.erase(entry);
            }
            else
            {
                m_pixelMap.erase(entry);
            }
        }
        SDL_Point* getMinimalPixels() const
        {
           return m_minimalPixels; 
        }
        unsigned int getSize() const
        {
            return m_pixelMap.size();
        }
        bool didUpdate()
        {
            m_didUpdate = !m_didUpdate;
            return !m_didUpdate;
        }
    private:
        map<string,SDL_Point>   m_pixelMap;
        SDL_Point*              m_minimalPixels;
        bool                    m_didUpdate;

        void process()
        {
            m_minimalPixels= new SDL_Point[m_pixelMap.size()];
            int i=0;
            for(auto pixelMapItterator : m_pixelMap)
                m_minimalPixels[i++] = pixelMapItterator.second;
        }
};
