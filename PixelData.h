#pragma once
#include "Utils.h"
#include <vector>
#include <map>
#include <string>
using namespace std;
class PixelData
{
    public:
        PixelData():m_minimalPixels(nullptr)
        {
        }
        ~PixelData()
        {
            delete[] m_minimalPixels;
        }
        void addPoint(const SDL_Point point)
        {
            string entry = pointToString(point);
            m_pixelMap[ entry ] = point;
        }
        void addPoints(const vector<SDL_Point>& points)
        {
            for(const auto point : points)
            {
                string entry = pointToString(point);
                m_pixelMap[ entry ] = point;
            }
        }
        void process()
        {
            m_minimalPixels= new SDL_Point[m_pixelMap.size()];
            int i=0;
            for(auto pixelMapItterator : m_pixelMap)
                m_minimalPixels[i++] = pixelMapItterator.second;
        }
        void removePixel(const SDL_Point& coordinate)
        {
            string entry = pointToString(coordinate);
            m_pixelMap.erase(entry);
        }

        SDL_Point* getMinimalPixels() const
        {
           return m_minimalPixels; 
        }
        unsigned int getSize() const
        {
            return m_pixelMap.size();
        }
    private:
        map<string,SDL_Point> m_pixelMap;
        SDL_Point* m_minimalPixels;
};
