#include "RaAxis.hpp"

#include "../../../Constants.hpp"

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
    updateRotationSpeed();
}

void RaAxis::setGuiding(const Direction mode)
{
    guidingDirection = mode;
    updateRotationSpeed();
}

void RaAxis::updateRotationSpeed()
{
    float speed = 0.0f;

    if (trackingEnabled)
    {
        speed += EARTH_ROTATION_SPEED;
    }

    speed += guidingDirection * guidingSpeedFactor * EARTH_ROTATION_SPEED;

    rotate(speed);
}