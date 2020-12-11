#include "TMC2209.hpp"

#include "AccelStepper.h"

TMC2209::TMC2209(const Stepper &stepper) : Driver(stepper, AccelStepper(AccelStepper::DRIVER, 0, 0, 0, 0))
{
}

void TMC2209::setup() const {}

float TMC2209::getDegPerFullStep() const
{
    return stepper.getSPR();
}

uint16_t TMC2209::getAvailableMicrosteppingModes() const
{
    // TMC2209 supports all microstepping modes from 1 to 256
    return 1 | 2 | 4 | 8 | 16 | 32 | 64 | 128 | 256;
}

uint16_t TMC2209::getMaxSpeed() const
{
    return stepper.getMaxStepsPerSecond();
}

void TMC2209::updateMicrostepping(uint16_t microstepping) {
    // TODO
}