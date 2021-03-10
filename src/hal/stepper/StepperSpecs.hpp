#pragma once

#include "stdint.h" // NOLINT(modernize-deprecated-headers)

/**
 * Represents technical specification of a mStepper.
 */
class StepperSpecs
{
public:
    /**
    * Create a mStepper instance to be used by a driver.
    * mSPR - steps per revolution (1.8° => 200, 0.9° => 400)
    * supportsMicrostepping - whether this mStepper supports mMicrostepping (e.g. 28byj-48 does not)
    * mRatedCurrent - current rating of this mStepper motor in A
    * mVoltage - mStepper mVoltage in V
    * mInductance - mInductance of the mStepper in mH
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
     * Get amount of degrees for one full step of this mStepper.
     */
    float getDegPerStep() const;

    /**
     * Get maximal speed (steps per second) of this mStepper motor
     */
    float getMaxSPS() const;

    /**
     * Get maximal speed (degrees per second) of this mStepper motor
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