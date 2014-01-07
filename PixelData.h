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
        void addPoint(SDL_Point point)
        {
            string entry = pointToString(point);
            m_pixelMap[ entry ] = point;
        }
        void addPoints(vector<SDL_Point>& points)
        {
            for(int i=0; i<points.size(); i++)
            {
                string entry = pointToString(points[i]);
                auto it = m_pixelMap.find(entry);
                if(it != m_pixelMap.end())
                    cout << "duplicate: "<<entry<<" - " <<  it->first  << endl; 
                m_pixelMap[ entry ] = points[i];
            }
        }
        SDL_Point* getMinimalPixels()
        {
           return m_minimalPixels; 
        }
        void process()
        {
            m_minimalPixels= new SDL_Point[m_pixelMap.size()];
            auto itt = begin(m_pixelMap);
            for(int i=0; i<m_pixelMap.size(); i++)
            {
                m_minimalPixels[i] = itt->second;
                itt++;
            }

        }
        void removePixel(SDL_Point& coordinate)
        {
            string entry = pointToString(coordinate);
            m_pixelMap.erase(entry);
        }
        unsigned int getSize()
        {
            return m_pixelMap.size();
        }
    private:
        map<string,SDL_Point> m_pixelMap;
        SDL_Point* m_minimalPixels;
};
