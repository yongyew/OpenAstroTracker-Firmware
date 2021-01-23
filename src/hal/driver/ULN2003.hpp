#pragma once

#include "Driver.hpp"

class ULN2003 : public Driver
{
public:
    ULN2003(
        const StepperSpecs &stepper,
        const uint8_t pin_in1,
        const uint8_t pin_in2,
        const uint8_t pin_in3,
        const uint8_t pin_in4);

    void setup() override;

    uint16_t getAvailableMicrosteppingModes() const override;

    uint16_t getMaxSpeed() const override;

    void step() override;

protected:
    void onMicrosteppingChanged() override;
    void onDirectionChanged() override;

private:
    const uint8_t pin_in1;
    const uint8_t pin_in2;
    const uint8_t pin_in3;
    const uint8_t pin_in4;

    uint8_t state;
};
