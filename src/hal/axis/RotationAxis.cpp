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
    if (speed)
    {
        unsigned long time = micros();
        if (time - lastStepTime >= steppingInterval)
        {
            driver.step();
            lastStepTime = time;

            currentPosition += getDegPerStep() * driver.getDirection();

            if (degsToTarget)
            {
                degsToTarget += driver.getDirection() * getDegPerStep();

                if (abs(degsToTarget) <= getDegPerStep())
                {
                    degsToTarget = 0.0f;
                    onTargetReached();
                }
            }
        }
    }
}

void RotationAxis::setSpeed(const float degPerSecond)
{
    if (this->speed == degPerSecond)
        return;

    float maxSpeed = driver.getMaxSteppingRate() * getDegPerStep();
    this->speed = constrain(degPerSecond, -maxSpeed, maxSpeed);

    if (this->speed == 0.0f)
    {
        this->steppingInterval = 0.0f;
    }
    else
    {
        this->steppingInterval = 1000000.0f / this->speed;
    }

    if (this->speed > 0)
    {
        driver.setDirection(Driver::Direction::CLOCKWISE);
    }
    else
    {
        driver.setDirection(Driver::Direction::ANTICLOCKWISE);
    }
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
    return 1 / getDegPerStep();
}

float RotationAxis::getCurrentPosition() const
{
    return currentPosition;
}

void RotationAxis::setCurrentPosition(float degrees)
{
    currentPosition = degrees;
}

const float RotationAxis::getDegPerStep() const
{
    return transmission * driver.getDegPerStep();
}