#pragma once

#include "../stepper/StepperSpecs.hpp"

#include "stdint.h"

/**
 * This is the abstract interface to be implemented by specific driver implementations.
 * The interface itself is kept to a minimum to provide easy extensions by new hardware.
 * All the parameters required for correct setup and operation of the actual driver should
 * be provided in its constructor (dependency injection).
 */
class Driver
{
public:
    /**
     * Construct new driver instance with provided hardware specifications.
     * 
     * @param stepper reference to the stepper specifications.
     * @param microstepping microstepping mode to be used.
     */
    Driver(const StepperSpecs &stepper, const uint16_t microstepping);

    /**
     * Perform required preparations (e.g. setting up UART connection, setting microstepping etc.)
     */
    virtual void setup() = 0;

    /**
     * Perform operations needed to be run periodically (e.g. perform a step if needed or calculate position).
     */
    virtual void loop() = 0;

    /**
     * Set speed of this driver/stepper. Negative values reverse direction. Zero stops the motor.
     * The speed can be limited based on the driver or stepper limitations. Use return value to
     * get the actual speed value which will be used.
     * 
     * @param degPerSecond new speed in degrees per second
     * 
     * @return applied speed in degrees per second.
     */
    virtual float setSpeed(const float degPerSecond);

    /**
     * @return current speed (deg per second).
     */
    const float getSpeed() const;

    virtual const float getPosition() const = 0;

protected:
    const StepperSpecs &stepper;

    const uint16_t microstepping;

    float speed = 0;
};
