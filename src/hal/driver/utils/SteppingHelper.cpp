#include "SteppingHelper.hpp"

#include <Arduino.h>

SteppingHelper::SteppingHelper() {}

void SteppingHelper::setSpeed(const float sps)
{
    if (this->sps != sps)
    {
        this->sps = sps;
        this->steppingInterval = (unsigned long)1000000UL / sps;
    }
}

bool SteppingHelper::step()
{
    if (sps == 0.0f)
        return false;

    if (micros() - lastStepTime >= steppingInterval)
    {
        lastStepTime += steppingInterval;

        if (sps < 0)
            position--;
        else
            position++;

        return true;
    }

    return false;
}

const long SteppingHelper::getPosition() const
{
    return position;
}