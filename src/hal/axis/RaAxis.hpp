#pragma once

#include "RotationAxis.hpp"

class RaAxis : public RotationAxis
{
public:

    enum GuidingDirection
    {
        WEST = -1,
        NONE = 0,
        EAST = 1
    };

    RaAxis(const float transmission, Driver &driver, const float guidingSpeedFactor);

    void setTracking(const bool enabled);

    void setGuiding(const GuidingDirection mode);

private:
    void recalculateRotationSpeed();

    bool trackingEnabled;
    GuidingDirection guidingDirection;
    const float guidingSpeedFactor;
};
