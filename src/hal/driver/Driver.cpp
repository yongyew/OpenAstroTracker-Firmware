#include "Driver.hpp"

#include "AccelStepper.h"

Driver::Driver(
    const StepperSpecs &stepper,
    const uint16_t microstepping,
    const Direction direction) : stepper(stepper),
                                   microstepping(microstepping),
                                   direction(direction) {}

const StepperSpecs& Driver::getStepperSpecs() const
{
    return stepper;
}

void Driver::setDirection(const Direction direction)
{
    if (direction != this->direction) {
        this->direction = direction;
        onDirectionChanged();
    }
}

const uint16_t Driver::getMicrostepping() const
{
    return microstepping;
}

void Driver::onDirectionChanged()
{
    // nothing to do here
}