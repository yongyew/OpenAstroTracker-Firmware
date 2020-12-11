#pragma once

#include "RotationAxis.hpp"

/**
 * Tracking speed in arcsecs per second
 */
#define SECONDS_PER_DAY 86164.0905
#define TRACKING_SPEED(RA_CIRC, PULLEY_CIRC, STEPEPR_SPR, MICROSTEPPING) \
    (RA_CIRC * STEPEPR_SPR * MICROSTEPPING / (SECONDS_PER_DAY * PULLEY_CIRC))

class RaAxis : public RotationAxis
{
public:
    enum RaGuideMode
    {
        DISABLED,
        POSITIVE,
        NEGATIVE
    };

    RaAxis(const Driver &driver, const float circumference);

    void setTracking(const bool enabled);

    void setGuiding(const RaGuideMode mode);

private:
    void recalculateRotationSpeed();

    bool trackingEnabled;
    const float trackingSpeed;
    RaGuideMode guidingMode;
    const float guidingSpeed;
};
