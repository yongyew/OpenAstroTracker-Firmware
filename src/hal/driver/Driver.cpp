#include "Driver.hpp"

#include <Arduino.h>

Driver::Driver(
    const StepperSpecs &stepper,
    const uint16_t microstepping) : stepper(stepper),
                                    microstepping(microstepping) {}

float Driver::setSpeed(const float degPerSec)
{
    if (degPerSec != this->speed)
    {
        this->speed = constrain(degPerSec, -stepper.getMaxSpeed(), stepper.getMaxSpeed());
    }

    return this->speed;
}