#pragma once

#include "Driver.hpp"

#include "stdint.h"
#include "TMCStepper.h"

#include "utils/SteppingHelper.hpp"

class TMC2209 : public Driver
{
public:
    TMC2209(const StepperSpecs &stepper,
            const uint16_t microstepping,
            Stream *serial,
            const uint8_t address,
            const uint8_t pin_en,
            const uint8_t pin_step,
            const uint8_t pin_dir);

    void setup() override;

    void loop() override;

    float setSpeed(const float degPerSecond) override;

    const float getPosition() const override;

private:
    TMC2209Stepper tmcStepper;

    const uint8_t pin_en;
    const uint8_t pin_step;
    const uint8_t pin_dir;

    SteppingHelper steppingHelper;
};
