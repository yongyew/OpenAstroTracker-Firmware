#include "StepperSpecs.hpp"

#define SQRT2 1.41421356237309504880

StepperSpecs::StepperSpecs(
    const int spr,
    const float ratedCurrent,
    const float voltage,
    const float inductance) : spr(spr),
                              ratedCurrent(ratedCurrent),
                              voltage(voltage),
                              inductance(inductance)
{
}

const int StepperSpecs::getStepsPerRevolution() const
{
    return spr;
}

const float StepperSpecs::getRMSCurrent() const
{
    return ratedCurrent * SQRT2;
}

const float StepperSpecs::getMaxSpeed() const
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

const float StepperSpecs::getRatedCurrent() const
{
    return ratedCurrent;
}

const float StepperSpecs::getDegPerStep() const
{
    return 360.0f / spr;
}