#pragma once
#include "PixelDataReceiver.h"
#include "PixelDataEditor.h"
#include "PixelData.h"
using namespace std;
class PixelDataPublisher
{
    public:
        PixelDataPublisher()
        {
        }
        ~PixelDataPublisher()
        {
        }
        void registerSubscriber(PixelDataReceiver* subscriber)
        {
            m_subscribers.push_back(subscriber);
        }
        void registerEditor(PixelDataEditor* editor)
        {
            m_editors.push_back(editor);
        }
        void updateData()
        {
            for(auto editor:m_editors)
                editor->editPixelData(m_pixelData);
            broadcast();
        }
        void addPoints(const vector<SDL_Point>& points)
        {
            m_pixelData.addPoints(points);
            broadcast();
        }
        const PixelData& getPixelData()
        {
            return m_pixelData;
        }
    private:
        void broadcast()
        {
            if(m_pixelData.didUpdate())
            {
                for(auto subscriber : m_subscribers)
                    subscriber->receivePixelData(m_pixelData);
                m_pixelData.resetDidUpdate();
            }
        }
        PixelData m_pixelData;
        vector<PixelDataReceiver*> m_subscribers;
        vector<PixelDataEditor*> m_editors;
};
