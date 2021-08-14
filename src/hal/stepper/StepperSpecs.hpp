#pragma once

#include "stdint.h" // NOLINT(modernize-deprecated-headers)

/**
 * Represents technical specification of a _stepper.
 */
class StepperSpecs
{
public:
    /**
    * Create a _stepper instance to be used by a driver.
    * mSPR - steps per revolution (1.8° => 200, 0.9° => 400)
    * supportsMicrostepping - whether this _stepper supports _ms (e.g. 28byj-48 does not)
    * mRatedCurrent - current rating of this _stepper motor in A
    * mVoltage - _stepper mVoltage in V
    * mInductance - mInductance of the _stepper in mH
    */
    StepperSpecs(
        uint16_t spr,
        float ratedCurrent,
        float voltage,
        float inductance);

    /**
     * Get steps per revolution
     */
    uint16_t getStepsPerRevolution() const;

    /**
     * Get amount of degrees for one full step of this _stepper.
     */
    float getDegPerStep() const;

    /**
     * Get maximal speed (steps per second) of this _stepper motor
     */
    float getMaxSPS() const;

    /**
     * Get maximal speed (degrees per second) of this _stepper motor
     */
    float getMaxSpeed() const;

    /**
     * Calculate RMS current from the rated current.
     */
    float getRMSCurrent() const;

    /**
     * Get rated current of this motor. This value should be used to configure RMS properly.
     */
    float getRatedCurrent() const;

private:
    const uint16_t mSPR;
    const float mRatedCurrent;
    const float mVoltage;
    const float mInductance;
};