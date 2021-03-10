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

private:
    void updateRotationSpeed();

    bool mTrackingEnabled;
    Direction mGuidingDirection;
    const float mGuidingSpeedFactor;
};
