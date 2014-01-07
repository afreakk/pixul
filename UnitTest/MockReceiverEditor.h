#pragma once
#include "../PixelDataHandler.h"
enum class EditorEnums
{
    REMOVE,
    ADD
};

class mockReceiver: public PixelDataReceiver
{
    public:
        mockReceiver():m_arraySize(-1)
        {
        }
        void receivePixelData(const PixelData& pixelData) override
        {
            m_points = pixelData.getMinimalPixels();
            m_arraySize = pixelData.getSize();
        }
        SDL_Point* getPixelArray()
        {
            return m_points;
        }
        int getArraySize()
        {
            return m_arraySize;
        }
    private:
        int m_arraySize;
        SDL_Point* m_points;
};

class mockEditor:public PixelDataEditor
{

    public:
        mockEditor():m_mode(EditorEnums::ADD)
        {
        }
        void editPixelData(PixelData& pixelData) override
        {
            switch(m_mode)
            {
                case EditorEnums::REMOVE:
                    for(auto itt : m_points)
                    {
                        pixelData.removePixel(itt);
                    }
                    break;
                case EditorEnums::ADD:
                    pixelData.addPoints(m_points);
                    break;
            }
        }
        void removePoints(vector<SDL_Point> points)
        {
            m_points = points;
            m_mode = EditorEnums::REMOVE;
        }
        void addPoints(vector<SDL_Point> points)
        {
            m_points = points;
            m_mode = EditorEnums::ADD;
        }
    private:
        vector<SDL_Point> m_points;
        EditorEnums m_mode;
};

