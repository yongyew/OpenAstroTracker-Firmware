#pragma once

#include "Driver.hpp"

#include "stdint.h"
#include "TMCStepper.h"

class TMC2209 : public Driver
{
public:
    TMC2209(const StepperSpecs &stepper,
            Stream *serial,
            const uint8_t address,
            const uint8_t pin_en,
            const uint8_t pin_step,
            const uint8_t pin_dir);

    void setup() override;

    uint16_t getAvailableMicrosteppingModes() const override;

    uint16_t getMaxSpeed() const override;

    void step() override;

    void setDirection(Direction direction) override;

protected:
    void updateMicrostepping(const uint16_t microstepping) override;

private:
    TMC2209Stepper tmcStepper;

    const uint8_t pin_en;
    const uint8_t pin_step;
    const uint8_t pin_dir;
};
