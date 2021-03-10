#include "SteppingHelper.hpp"

#include <Arduino.h>

SteppingHelper::SteppingHelper() = default;

void SteppingHelper::setSpeed(const float sps)
{
    if (this->mSps != sps)
    {
        this->mSps = sps;
        this->mSteppingInterval =  static_cast<unsigned long>(1000000UL / sps);
    }
}

bool SteppingHelper::step()
{
    if (mSps == 0.0f)
        return false;

    if (micros() - mLastStepTime >= mSteppingInterval)
    {
        mLastStepTime += mSteppingInterval;

        if (mSps < 0)
            mPosition--;
        else
            mPosition++;

        return true;
    }

    return false;
}

long SteppingHelper::getPosition() const
{
    return mPosition;
}