#pragma once

#include "stdint.h"

/**
 * Represents technical specification of the used stepper.
 */
class Stepper
{
public:

    /**
    * Create a stepper instance to be used by a driver.
    * spr - steps per revolution (1.8° => 200, 0.9° => 400)
    * circumference - circumference of the pulley used on this stepper
    * maxStepsPerSecond - maximal stepping speed this stepper can handle
    * ratedCurrent - current rating of this stepper motor
    */
    Stepper(const int spr,
            const bool supportsMicrostepping,
            const float ratedCurrent,
            const float voltage,
            const float inductance);

    /**
     * Get steps per revolution
     */
    int getSPR() const;

    /**
     * Get whether this stepper is able to execute microstepping
     */
    bool isMicrosteppingSupported() const;

    /**
     * Get maximal speed (steps/s) of this stepper motor
     */
    uint16_t getMaxFullStepsPerSecond() const;

    /**
     * Calculate RMS current from the rated current.
     */
    float getRMSCurrent() const;

    /**
     * Get rated current of this motor. This value should be used to configure RMS properly.
     */
    uint16_t getRatedCurrent() const;

private:
    const int spr;
    const bool supportsMicrostepping;
    const float ratedCurrent;
    const float voltage;
    const float inductance;
};