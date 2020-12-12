#pragma once

#include "../Driver.hpp"

#include "stdint.h"
#include "TMCStepper.h"

class TMC2209 : public Driver
{
public:
    TMC2209(
        const Stepper &stepper, Stream *serial, const uint8_t address
    );

    void setup() const override;

    uint16_t getAvailableMicrosteppingModes() const override;

    uint16_t getMaxSpeed() const override;
protected:
    void updateMicrostepping(uint16_t microstepping) override;
private:
    TMC2209Stepper *tmcStepper;
};
