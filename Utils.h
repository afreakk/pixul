#pragma once
#include <vector>
#include <math.h>
using namespace std;
int floatToInt(float f)
{
    return static_cast<int>(round(f));
}
float intToFloat(int i)
{
    return floor(static_cast<float>(i));
}
float intToDouble(int i)
{
    return floor(static_cast<double>(i));
}
struct fPoint
{
    float x;
    float y;
    fPoint():x(0),y(0){}
    fPoint(float xx, float yy):x(xx),y(yy){}
};
void injectCube( vector<SDL_Point>& array,int startWidth, int startHeight, int endWidth,int endHeight)
{
    for(int x=startWidth; x< endWidth; x++)
    {
        for(int y=startHeight; y<endHeight; y++)
        {
            array.push_back( SDL_Point{x,y} );
        }
    }
}
void circle(int n_cx, int n_cy, int radius, vector<SDL_Point>& array)
{
    double error = (double)-radius;
    double x = (double)radius -0.5;
    double y = (double)0.5;
    double cx = n_cx - 0.5;
    double cy = n_cy - 0.5;
    array.clear();
    while (x >= y)
    {
        array.push_back(SDL_Point{ (int)(cx + x), (int)(cy + y) });
        array.push_back(SDL_Point{ (int)(cx + y), (int)(cy + x) });
 
        if (x != 0)
        {
            array.push_back(SDL_Point{ (int)(cx - x), (int)(cy + y) });
            array.push_back(SDL_Point{ (int)(cx + y), (int)(cy - x) });
        }
 
        if (y != 0)
        {
            array.push_back(SDL_Point{ (int)(cx + x), (int)(cy - y) });
            array.push_back(SDL_Point{ (int)(cx - y), (int)(cy + x) });
        }
 
        if (x != 0 && y != 0)
        {
            array.push_back(SDL_Point{ (int)(cx - x), (int)(cy - y) });
            array.push_back(SDL_Point{ (int)(cx - y), (int)(cy - x) });
        }
 
        error += y;
        ++y;
        error += y;
 
        if (error >= 0)
        {
            --x;
            error -= x;
            error -= x;
        }
    }
}
