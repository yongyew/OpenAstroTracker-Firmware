#include "RotationAxis.hpp"

#include <Arduino.h>

RotationAxis::RotationAxis(
    const float transmission,
    Driver &driver) : transmission(transmission),
                      driver(driver) {}

void RotationAxis::setup()
{
    driver.setup();
}

void RotationAxis::loop()
{
    driver.loop();
}

void RotationAxis::setSpeed(const float degPerSecond)
{
    driver.setSpeed(degPerSecond);
}

void RotationAxis::moveTo(const float degrees)
{
    degsToTarget = degrees - currentPosition;
}

void RotationAxis::moveBy(const float degrees)
{
    degsToTarget = degrees;
}

void RotationAxis::onTargetReached()
{
    // stub implementation for the case if the specific axis implementation does not need this callback
}

float RotationAxis::getStepsPerDeg() const
{
    return 1.0f / getDegPerStep();
}

float RotationAxis::getCurrentPosition() const
{
    return currentPosition;
}

void RotationAxis::setCurrentPosition(float degrees)
{
    currentPosition = degrees;
}