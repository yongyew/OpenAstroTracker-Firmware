#pragma once

#include "../Driver.hpp"

#include "stdint.h"

class TMC2209 : public Driver
{
public:
    TMC2209(
        const Stepper &stepper
    );

    void setup() const;

    float getDegPerFullStep() const;

    uint16_t getAvailableMicrosteppingModes() const;

    uint16_t getMaxSpeed() const;
protected:
    void updateMicrostepping(uint16_t microstepping) override;
};
