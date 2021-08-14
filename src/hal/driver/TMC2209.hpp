#pragma once

#include "Driver.hpp"
#include "utils/SteppingHelper.hpp"

PUSH_NO_WARNINGS
#include "stdint.h" // NOLINT(modernize-deprecated-headers)
#include "TMCStepper.h"
POP_NO_WARNINGS


class TMC2209 : public Driver
{
public:
    TMC2209(const StepperSpecs& stepper,
        uint16_t ms,
        Stream* serial,
        uint8_t address,
        uint8_t pin_en,
        uint8_t pin_step,
        uint8_t pin_dir);

    void setup() override;

    void loop() override;

    float setSpeed(float degPerSecond) override;

    float getPosition() const override;

private:
    TMC2209Stepper _tmcStepper;

    const uint8_t _pin_en;
    const uint8_t _pin_step;
    const uint8_t _pin_dir;

    SteppingHelper _stepHelper;
};
