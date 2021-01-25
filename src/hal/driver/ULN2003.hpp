#pragma once

#include "Driver.hpp"

#define INIT_STATE_FULL_STEP 0b00110011
#define INIT_STATE_HALF_STEP 0b00000111

class ULN2003 : public Driver
{
public:
    ULN2003(
        const StepperSpecs &stepper,
        const uint16_t microstepping,
        const uint8_t pin_in1,
        const uint8_t pin_in2,
        const uint8_t pin_in3,
        const uint8_t pin_in4);

    void setup() override;

    uint16_t getMaxSpeed() const override;

    void step() override;

protected:
    void onDirectionChanged() override;

private:
    const uint8_t pin_in1;
    const uint8_t pin_in2;
    const uint8_t pin_in3;
    const uint8_t pin_in4;

    uint8_t pin_state_sequence;

    uint8_t (*rot)(const uint8_t, const uint8_t);
};
