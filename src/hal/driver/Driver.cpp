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
        updateMicrostepping(microstepping);
    }
    else
    {
        // TODO: log a warning about wrong microstepping mode
    }
}

uint16_t Driver::getMicrostepping() const
{
    return microstepping;
}