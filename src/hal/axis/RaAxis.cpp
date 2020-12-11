#include "RaAxis.hpp"

#include "../../inc/Config.hpp"

RaAxis::RaAxis(const Driver &driver, const float circumference) : 
    RotationAxis(driver, circumference),
    trackingEnabled(false),
    trackingSpeed(
        TRACKING_SPEED(
            circumference, 
            driver.getPulleyCircumference(), 
            driver.getStepperSPR(),
            driver.getMicrostepping())
            ),
    guidingMode(DISABLED),
    guidingSpeed(trackingEnabled * RA_PULSE_MULTIPLIER)
{
}

void RaAxis::setTracking(const bool enable)
{
    trackingEnabled = enable;
}

void RaAxis::setGuiding(const RaGuideMode mode)
{
    guidingMode = mode;
}

void RaAxis::recalculateRotationSpeed()
{
    float speed = 0.0f;

    if (trackingEnabled) {
        speed += trackingSpeed;
    }

    switch (guidingMode)
    {
    case POSITIVE:
        speed += guidingSpeed;
        break;
    case NEGATIVE:
        speed -= guidingSpeed;
        break;
    case DISABLED:
    default:
        break;
    }

    setRotationSpeed(speed);
}