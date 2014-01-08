#include "../PixelDataPublisher.h"
#include "MockReceiverEditor.h"
#include <UnitTest++.h>
using namespace std;
namespace
{
    TEST(TEST_PixelDataV2)
    {
        const int sample_count = 10000;

        vector<SDL_Point> points;
        points.resize(sample_count);
        for(int i=0; i<sample_count; i++)
            points[i] = SDL_Point{i, i};

        PixelDataPublisher pPublisher;

        mockEditor mEditor;
        mockReceiver mReceiver;

        pPublisher.registerEditor(&mEditor);
        pPublisher.registerSubscriber(&mReceiver);

        mEditor.addPoints(points);
        pPublisher.updateData();

        CHECK_EQUAL( points.size(), mReceiver.getArraySize());
        CHECK_EQUAL( sumOfPoints( &points[0], points.size()), sumOfPoints( mReceiver.getPixelArray(), mReceiver.getArraySize()) );
        
        mEditor.removePoints(points);
        pPublisher.updateData();
        CHECK_EQUAL(0,mReceiver.getArraySize());

        mEditor.addPoints(points);
        pPublisher.updateData();
        
        vector<SDL_Point> almostAll(points.begin()+1,points.end());
        vector<SDL_Point> first(points.begin(), points.begin()+1);
        mEditor.removePoints(almostAll);
        pPublisher.updateData();

        CHECK_EQUAL( first.size(), mReceiver.getArraySize());
        CHECK_EQUAL( sumOfPoints( &first[0], first.size()), sumOfPoints( mReceiver.getPixelArray(), mReceiver.getArraySize()) );


    }
    TEST (FIRST_SECOND_HALF_PUBLISHER_TEST)
    {
        const int sample_count = 10000;

        PixelDataPublisher pPublisher;

        mockEditor mEditor;
        mockReceiver mReceiver;

        pPublisher.registerEditor(&mEditor);
        pPublisher.registerSubscriber(&mReceiver);

        vector<SDL_Point> points;
        points.resize(sample_count);
        for(int i=0; i<sample_count; i++)
            points[i] = SDL_Point{i, i};

        mEditor.addPoints(points);
        pPublisher.updateData();

        int half = doubleToInt(static_cast<double>(points.size()-1)/2.0);
        vector<SDL_Point> firstHalf(points.begin(),points.begin()+half);
        vector<SDL_Point> secondHalf(points.begin()+half, points.end());

        mEditor.removePoints(firstHalf);

        pPublisher.updateData();

        CHECK_EQUAL( secondHalf.size(), mReceiver.getArraySize());
        CHECK_EQUAL( sumOfPoints( &secondHalf[0], secondHalf.size()), sumOfPoints( mReceiver.getPixelArray(), mReceiver.getArraySize()) );
    }
    TEST(TEST_PixelData)
    {
        const int sample_count = 100000;
        vector<SDL_Point> points;
        points.resize(sample_count);
        for(int i=0; i<sample_count; i++)
            points[i] = SDL_Point{i, i};
        PixelDataPublisher pPublisher;
        pPublisher.addPoints(points);
        CHECK_EQUAL( points.size(), pPublisher.getPixelData().getSize());
        CHECK_EQUAL( sumOfPoints( &points[0], points.size()), 
                sumOfPoints( pPublisher.getPixelData().getMinimalPixels(), pPublisher.getPixelData().getSize()) );
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
            CHECK_EQUAL(a[i], pointToString(p[i]) );
        }
    }
}
