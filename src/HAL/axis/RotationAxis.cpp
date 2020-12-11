#include "RotationAxis.hpp"

#include "Arduino.h"

RotationAxis::RotationAxis(
    const Driver &driver,
    const float circumference) : driver(driver),
                                 circumference(circumference),
                                 accelstepper(AccelStepper()) {}

void RotationAxis::setup()
{
    driver.setup();
}

void RotationAxis::loop()
{
    /**
     * also concider run to position and return to the tracking speed if necessary
     */
    accelstepper.runSpeed();
}

void RotationAxis::setRotationSpeed(const float speed)
{

    /* 
    * perform conversion from arcsecs to steps. Take in account:
    * - stepper degs per step
    * - reduction (ring radius, pulley etc.)
    */
}

float RotationAxis::getFullStepsPerDeg() const
{
    return (circumference / driver.getPulleyCircumference()) * (driver.getStepperSPR() / 360.0f);
}