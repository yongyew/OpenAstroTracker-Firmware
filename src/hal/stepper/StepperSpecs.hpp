#pragma once

#include "stdint.h"

/**
 * Represents technical specification of a stepper.
 */
class StepperSpecs
{
public:
    /**
    * Create a stepper instance to be used by a driver.
    * spr - steps per revolution (1.8° => 200, 0.9° => 400)
    * supportsMicrostepping - whether this stepper supports microstepping (e.g. 28byj-48 does not)
    * ratedCurrent - current rating of this stepper motor in A
    * voltage - stepper voltage in V
    * inductance - inductance of the stepper in mH
    */
    StepperSpecs(
        const int spr,
        const float ratedCurrent,
        const float voltage,
        const float inductance);

    /**
     * Get steps per revolution
     */
    const int getStepsPerRevolution() const;

    /**
     * Get amount of degrees for one full step of this stepper.
     */
    const float getDegPerStep() const;

    /**
     * Get maximal speed (steps per second) of this stepper motor
     */
    const float getMaxSPS() const;

    /**
     * Get maximal speed (degrees per second) of this stepper motor
     */
    const float getMaxSpeed() const;

    /**
     * Calculate RMS current from the rated current.
     */
    const float getRMSCurrent() const;

    /**
     * Get rated current of this motor. This value should be used to configure RMS properly.
     */
    const float getRatedCurrent() const;

private:
    const int spr;
    const float ratedCurrent;
    const float voltage;
    const float inductance;
};