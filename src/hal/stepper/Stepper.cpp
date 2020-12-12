#include "Stepper.hpp"

#include "math.h"

Stepper::Stepper(
    const int spr,
    const bool supportsMicrostepping,
    const float ratedCurrent,
    const float voltage,
    const float inductance) : spr(spr),
                              supportsMicrostepping(supportsMicrostepping),
                              ratedCurrent(ratedCurrent),
                              voltage(voltage),
                              inductance(inductance)
{
}

int Stepper::getSPR() const
{
    return spr;
}

bool Stepper::isMicrosteppingSupported() const
{
    return supportsMicrostepping;
}

float Stepper::getRMSCurrent() const
{
    return ratedCurrent * sqrtf(2.0f);
}

uint16_t Stepper::getMaxFullStepsPerSecond() const
{
    return ratedCurrent * sqrt(2);
}

uint16_t Stepper::getRatedCurrent() const
{
    return ratedCurrent;
}