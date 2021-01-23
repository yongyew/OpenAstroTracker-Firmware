#include "Driver.hpp"

#include "AccelStepper.h"

Driver::Driver(
    const StepperSpecs &stepper) : stepper(stepper),
                                   microstepping(1),
                                   direction(CLOCKWISE) {}

const StepperSpecs& Driver::getStepperSpecs() const
{
    return stepper;
}

void Driver::setMicrostepping(uint16_t microstepping)
{
    if (microstepping == this->microstepping)
        return;

    // only update microstepping if it is supported by the driver
    if (getAvailableMicrosteppingModes() & microstepping)
    {
        this->microstepping = microstepping;
        onMicrosteppingChanged();
    }
    else
    {
        // TODO: log a warning about wrong microstepping mode
    }
}

void Driver::setDirection(const Direction direction)
{
    if (direction != this->direction) {
        this->direction = direction;
        onDirectionChanged();
    }
}

uint16_t Driver::getMicrostepping() const
{
    return microstepping;
}

void Driver::onMicrosteppingChanged()
{
    // nothing to do here
}

void Driver::onDirectionChanged()
{
    // nothing to do here
}