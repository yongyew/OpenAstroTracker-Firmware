#include "RotationAxis.hpp"


RotationAxis::RotationAxis(
    const float transmission,
    Driver* driver)
    : mTransmission(transmission),
      mDriver(driver)
{
}

void RotationAxis::setup()
{
    mDriver->setup();
}

void RotationAxis::loop()
{
    mDriver->loop();
}

void RotationAxis::setSpeed(const float degPerSecond)
{
    mDriver->setSpeed(degPerSecond * mTransmission);
}

void RotationAxis::moveTo(const float degrees)
{
    mDegsToTarget = degrees - mPositionDeg;
}

void RotationAxis::moveBy(const float degrees)
{
    mDegsToTarget = degrees;
}

void RotationAxis::onTargetReached()
{
    // stub implementation for the case if the specific axis implementation does not need this callback
}

float RotationAxis::getCurrentDegrees() const
{
    return mPositionDeg;
}

void RotationAxis::setCurrentPosition(float degrees)
{
    mPositionDeg = degrees;
}