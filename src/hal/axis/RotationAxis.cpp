#include "RotationAxis.hpp"

#include "Arduino.h"

RotationAxis::RotationAxis(
    const Driver &driver,
    AccelStepper *accellStepper,
    const float transmission) : driver(driver),
                                 transmission(transmission),
                                 accelStepper(accellStepper) {}

void RotationAxis::setup()
{
    driver.setup();
}

void RotationAxis::loop()
{
    /**
     * also concider run to position and return to the tracking speed if necessary
     */
    accelStepper->runSpeed();
}

void RotationAxis::setRotationSpeed(const float speed)
{

    /* 
    * perform conversion from arcsecs to steps. Take in account:
    * - stepper degs per step
    * - transmission (ring radius, pulley etc.)
    */
}

float RotationAxis::getFullStepsPerDeg() const
{
    return transmission * (driver.getStepperSPR() / 360.0f);
}