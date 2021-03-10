#include "Driver.hpp"

#include <Arduino.h>

Driver::Driver(
    const StepperSpecs &stepper,
    const uint16_t microstepping) : mStepper(stepper),
                                    mMicrostepping(microstepping) {}

float Driver::setSpeed(const float degPerSec)
{
    if (degPerSec != this->mSpeed)
    {
        this->mSpeed = constrain(degPerSec, -mStepper.getMaxSpeed(), mStepper.getMaxSpeed());
    }

    return this->mSpeed;
}
float Driver::getSpeed() const
{
    return this->mSpeed;
}
