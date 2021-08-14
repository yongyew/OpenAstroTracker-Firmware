#include "SteppingHelper.hpp"

#include <Arduino.h>

SteppingHelper::SteppingHelper() = default;

void SteppingHelper::setSpeed(const float sps)
{
    if (this->_sps != sps)
    {
        this->_sps = sps;
        this->_steppingInterval =  static_cast<unsigned long>(1000000UL / sps);
    }
}

bool SteppingHelper::step()
{
    if (_sps == 0.0f)
        return false;

    if (micros() - _lastStepTime >= _steppingInterval)
    {
        _lastStepTime += _steppingInterval;

        if (_sps < 0)
            _position--;
        else
            _position++;

        return true;
    }

    return false;
}

long SteppingHelper::getPosition() const
{
    return _position;
}