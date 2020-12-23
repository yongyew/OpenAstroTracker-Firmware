#pragma once

#include "stdint.h"

/**
 * Represents technical specification of the used stepper.
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
    int getStepsPerRevolution() const;

    /**
     * Get maximal speed (steps/s) of this stepper motor
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
    const int spr;
    const float ratedCurrent;
    const float voltage;
    const float inductance;
};