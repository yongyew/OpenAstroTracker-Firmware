#pragma once

#include "RotationAxis.hpp"

class RaAxis : public RotationAxis
{
public:

    enum Direction
    {
        WEST = -1,
        NONE = 0,
        EAST = 1
    };

    RaAxis() = delete;

    RaAxis(RaAxis& other) = delete;

    RaAxis(float transmission, Driver* driver, float guidingSpeedFactor);

    void setTracking(bool enabled);

    void setGuiding(Direction direction);

    void setSlewingRate(float rate);

private:
    void updateRotationSpeed();

    bool _isTrackingEnabled;

    Direction _guidingDirection;

    const float _guidingSpeedFactor;

    float _slewingRate;
};
