#include "RaAxis.hpp"

#include "../../inc/Config.hpp"

RaAxis::RaAxis(const Driver &driver, const float transmission, const float guidingSpeedFactor) : 
    RotationAxis(driver, new AccelStepper(), transmission),
    trackingEnabled(false),
    guidingMode(NONE),
    guidingSpeedFactor(guidingSpeedFactor)
{
}

void RaAxis::setTracking(const bool enable)
{
    trackingEnabled = enable;
    recalculateRotationSpeed();
}

void RaAxis::setGuiding(const RaGuidingPulse mode)
{
    guidingMode = mode;
    recalculateRotationSpeed();
}

float RaAxis::getTrackingSpeed() const
{
    return transmission * driver.getStepperSPR() * driver.getMicrostepping() / SECONDS_PER_DAY;
}

void RaAxis::recalculateRotationSpeed()
{
    float speed = 0.0f;

    if (trackingEnabled) {
        speed += getTrackingSpeed();
    }

    switch (guidingMode)
    {
    case POSITIVE:
        speed += guidingSpeedFactor;
        break;
    case NEGATIVE:
        speed -= guidingSpeedFactor;
        break;
    case NONE:
    default:
        break;
    }

    setRotationSpeed(speed);
}