#include "Driver.hpp"

#include "AccelStepper.h"

Driver::Driver(
    const Stepper &stepper,
    AccelStepper::MotorInterfaceType interfaceType,
    uint8_t pin1,
    uint8_t pin2,
    uint8_t pin3,
    uint8_t pin4) : stepper(stepper),
                    accelStepper(AccelStepper(interfaceType, pin1, pin2, pin3, pin4)),
                    microstepping(1) {}

uint16_t Driver::getStepperSPR() const
{
    return stepper.getSPR();
}

void Driver::setMicrostepping(uint16_t microstepping)
{
    if (microstepping == this->microstepping)
        return;

    if (getAvailableMicrosteppingModes() & microstepping)
    {
        this->microstepping = microstepping;
        updateMicrostepping(microstepping);
    }
}

uint16_t Driver::getMicrostepping() const
{
    return microstepping;
}