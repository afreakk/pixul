#pragma once

#include "PixelData.h"
class PixelDataReceiver
{
    public:
        virtual void receivePixelData(const PixelData& pixelData)=0;
};
