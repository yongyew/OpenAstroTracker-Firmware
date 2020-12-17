#include "RaAxis.hpp"

#include "../../inc/Config.hpp"

RaAxis::RaAxis(
    const float transmission,
    Driver &driver,
    const float guidingSpeedFactor) : RotationAxis(transmission, driver),
                                      trackingEnabled(false),
                                      guidingDirection(NONE),
                                      guidingSpeedFactor(guidingSpeedFactor)
{
}

void RaAxis::setTracking(const bool enable)
{
    trackingEnabled = enable;
    recalculateRotationSpeed();
}

void RaAxis::setGuiding(const GuidingDirection mode)
{
    guidingDirection = mode;
    recalculateRotationSpeed();
}

void RaAxis::recalculateRotationSpeed()
{
    float speed = 0.0f;

    if (trackingEnabled)
    {
        speed += EARTH_ROTATION_SPEED;
    }

    speed += guidingDirection * guidingSpeedFactor * EARTH_ROTATION_SPEED;

    rotate(speed);
}