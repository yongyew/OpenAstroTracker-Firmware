#pragma once

#include "Driver.hpp"

class ULN2003 : public Driver
{
public:
    ULN2003(const StepperSpecs &stepper);

    void setup() override;

    uint16_t getAvailableMicrosteppingModes() const override;

    uint16_t getMaxSpeed() const override;

    void step() override;

    void setDirection(Direction direction) override;

protected:
    void updateMicrostepping(const uint16_t microstepping) override;
};
