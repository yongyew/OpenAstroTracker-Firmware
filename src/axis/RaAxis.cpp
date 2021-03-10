#include "RaAxis.hpp"

#include "Constants.hpp"

RaAxis::RaAxis(
    const float transmission,
    Driver* driver,
    const float guidingSpeedFactor)
    : RotationAxis(transmission, driver),
      mTrackingEnabled(false),
      mGuidingDirection(NONE),
      mGuidingSpeedFactor(guidingSpeedFactor)
{
}

void RaAxis::setTracking(const bool enable)
{
    mTrackingEnabled = enable;
    updateRotationSpeed();
}

void RaAxis::setGuiding(const Direction mode)
{
    mGuidingDirection = mode;
    updateRotationSpeed();
}

void RaAxis::updateRotationSpeed()
{
    float speed = 0.0f;

    if (mTrackingEnabled)
    {
        speed += EARTH_ROTATION_SPEED;
    }

    speed += static_cast<float>(mGuidingDirection) * mGuidingSpeedFactor * EARTH_ROTATION_SPEED;

    setSpeed(speed);
}