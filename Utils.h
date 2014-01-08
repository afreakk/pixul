#ifndef _UTILS_H_
#define _UTILS_H_

////////////////////////////////////////////////////////////////////////

#include <vector>
#include <math.h>
using namespace std;
struct fPoint
{
    float x;
    float y;
    fPoint():x(0),y(0){}
    fPoint(float xx, float yy):x(xx),y(yy){}
};
int floatToInt(float f)
{
    return static_cast<int>(round(f));
}
int doubleToInt(double f)
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
#include <SDL2/SDL.h>
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
int sumOfPoints(SDL_Point* pointArr, int size)
{
    int sum = 0;
    for(int i=0; i<size; i++)
    {
        sum += pointArr->x;
        sum += pointArr->y;
        pointArr++;
    }
    return sum;
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

////////////////////////////////////////////////////////////////////////

#endif /*UTILS_H*/
