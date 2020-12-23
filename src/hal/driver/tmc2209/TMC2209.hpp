#pragma once

#include "../Driver.hpp"

#include "stdint.h"
#include "TMCStepper.h"

class TMC2209 : public Driver
{
public:
    TMC2209(const StepperSpecs &stepper, Stream *serial, const uint8_t address, uint8_t stepPin);

    void setup() override;

    uint16_t getAvailableMicrosteppingModes() const override;

    uint16_t getMaxSpeed() const override;

    void step() override;

protected:
    void updateMicrostepping(const uint16_t microstepping) override;

private:
    TMC2209Stepper tmcStepper;
};
