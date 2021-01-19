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

    RaAxis(const float transmission, Driver &driver, const float guidingSpeedFactor);

    void setTracking(const bool enabled);

    void setGuiding(const Direction direction);

private:
    void updateRotationSpeed();

    bool trackingEnabled;
    Direction guidingDirection;
    const float guidingSpeedFactor;
};
