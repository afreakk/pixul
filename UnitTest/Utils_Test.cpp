#include "../PixelDataHandler.h"
#include "MockReceiverEditor.h"
#include <UnitTest++.h>
using namespace std;
namespace
{
    TEST(TEST_PixelDataV2)
    {
        const int sample_count = 100000;

        vector<SDL_Point> points;
        points.resize(sample_count);
        for(int i=0; i<sample_count; i++)
            points[i] = SDL_Point{i, i};

        PixelDataHandler pHandler;

        mockEditor mEditor;
        mockReceiver mReceiver;

        pHandler.registerEditor(&mEditor);
        pHandler.registerSubscriber(&mReceiver);

        mEditor.addPoints(points);
        pHandler.write();

        CHECK_EQUAL( points.size(), mReceiver.getArraySize());
        CHECK_EQUAL( sumOfPoints( &points[0], points.size()), 
                sumOfPoints( mReceiver.getPixelArray(), mReceiver.getArraySize()) );
        
        mEditor.removePoints(points);
        pHandler.write();
        CHECK_EQUAL(0,mReceiver.getArraySize());
    }
    TEST(TEST_PixelData)
    {
        const int sample_count = 100000;
        vector<SDL_Point> points;
        points.resize(sample_count);
        for(int i=0; i<sample_count; i++)
            points[i] = SDL_Point{i, i};
        PixelDataHandler pHandler;
        pHandler.addPoints(points);
        CHECK_EQUAL( points.size(), pHandler.getPixelData().getSize());
        CHECK_EQUAL( sumOfPoints( &points[0], points.size()), 
                sumOfPoints( pHandler.getPixelData().getMinimalPixels(), pHandler.getPixelData().getSize()) );
    }
    TEST(TEST_PointToString)
    {
        int size = 4;
        SDL_Point p[size];
        string a[size];
        p[0].x = 10,p[0].y = 15;
        a[0] = "10.15";

        p[1].x = 0,p[1].y = 0;
        a[1] = "0.0";

        p[2].x = -20,p[2].y = -100;
        a[2] = "-20.-100";

        p[3].x = -20000,p[3].y = 330000;
        a[3] = "-20000.330000";
        for(int i=0; i<size; i++)
        {
            cout <<"Testing: "<< p[i].x << " - " << p[i].y << endl;
            CHECK_EQUAL(a[i], pointToString(p[i]) );
        }
    }
}
