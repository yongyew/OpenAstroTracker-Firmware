#pragma once

#include "stdint.h"

class Stepper
{
public:
    Stepper(const int spr,
            const float circumference,
            const bool supportsMicrostepping,
            const uint16_t maxStepsPerSecond);

    int getSPR() const;

    float getPulleyCircumference() const;

    bool isMicrosteppingSupported() const;

    uint16_t getMaxStepsPerSecond() const;

private:
    const int spr;
    const float circumference;
    const bool supportsMicrostepping;
    const uint16_t maxStepsPerSecond;
};