#include "StepperSpecs.hpp"

#define SQRT2F 1.41421356237309504880f

StepperSpecs::StepperSpecs(
    const uint16_t spr,
    const float ratedCurrent,
    const float voltage,
    const float inductance) : mSPR(spr),
                              mRatedCurrent(ratedCurrent),
                              mVoltage(voltage),
                              mInductance(inductance)
{
}

uint16_t StepperSpecs::getStepsPerRevolution() const
{
    return mSPR;
}

float StepperSpecs::getRMSCurrent() const
{
    return mRatedCurrent / SQRT2F;
}

float StepperSpecs::getMaxSPS() const
{
    /**
     * T_s      - time per step
     * L        - mInductance
     * I_max    - max current
     * V        - mVoltage
     * 
     * T_s = L * I_max * 2 / V
     * Steps per second = 1 / T_s
     */
    return mVoltage / (mInductance * mRatedCurrent * 2);
}

float StepperSpecs::getMaxSpeed() const
{
    return getMaxSPS() * getDegPerStep();
}

float StepperSpecs::getRatedCurrent() const
{
    return mRatedCurrent;
}

float StepperSpecs::getDegPerStep() const
{
    return 360.0f / static_cast<float>(mSPR);
}