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

float Stepper::getMaxSpeed() const
{
    /**
     * T_s      - time per step
     * L        - inductance
     * I_max    - max current
     * V        - voltage
     * 
     * T_s = L * I_max * 2 / V
     * Steps per second = 1 / T_s
     */
    return voltage / (inductance * ratedCurrent * 2);
}

float Stepper::getRatedCurrent() const
{
    return ratedCurrent;
}