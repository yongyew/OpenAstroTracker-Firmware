#pragma once

#include "RotationAxis.hpp"

/**
 * Tracking speed in arcsecs per second
 */
#define SECONDS_PER_DAY 86164.0905

class RaAxis : public RotationAxis
{
public:
    enum RaGuidingPulse
    {
        NONE,
        POSITIVE,
        NEGATIVE
    };

    RaAxis(const Driver &driver, const float transmission, const float guidingSpeedFactor);

    void setTracking(const bool enabled);

    void setGuiding(const RaGuidingPulse mode);

private:
    float getTrackingSpeed() const;
    void recalculateRotationSpeed();

    bool trackingEnabled;
    RaGuidingPulse guidingMode;
    const float guidingSpeedFactor;
};
