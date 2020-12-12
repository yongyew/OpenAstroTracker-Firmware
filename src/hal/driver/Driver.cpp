#include "Driver.hpp"

#include "AccelStepper.h"

Driver::Driver(const Stepper &stepper, const AccelStepper &accelstepper) : stepper(stepper),
                                                                           accelStepper(accelStepper)
{
    microstepping = 1; // init at full steps
}

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