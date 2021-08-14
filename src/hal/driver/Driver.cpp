#include "Driver.hpp"

#include <Arduino.h>

Driver::Driver(
    const StepperSpecs &stepper,
    const uint16_t microstepping) : _stepper(stepper),
                                    _ms(microstepping) {}

float Driver::setSpeed(const float degPerSec)
{
    if (degPerSec != this->_speed)
    {
        this->_speed = constrain(degPerSec, -_stepper.getMaxSpeed(), _stepper.getMaxSpeed());
    }

    return this->_speed;
}
float Driver::getSpeed() const
{
    return this->_speed;
}
