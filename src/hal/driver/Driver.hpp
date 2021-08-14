#pragma once

#include "../stepper/StepperSpecs.hpp"

#include "stdint.h" // NOLINT(modernize-deprecated-headers)

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
     * @param stepper reference to the _stepper specifications.
     * @param microstepping _ms mode to be used.
     */
    Driver(const StepperSpecs& stepper, uint16_t microstepping);

    /**
     * Perform required preparations (e.g. setting up UART connection, setting _ms etc.)
     */
    virtual void setup() = 0;

    /**
     * Perform operations needed to be run periodically (e.g. perform a step if needed or calculate _position).
     */
    virtual void loop() = 0;

    /**
     * Set speed of this driver/_stepper. Negative values reverse direction. Zero stops the motor.
     * The speed can be limited based on the driver or _stepper limitations. Use return value to
     * get the actual speed value which will be used.
     * 
     * @param degPerSecond new speed in degrees per second
     * 
     * @return applied speed in degrees per second.
     */
    virtual float setSpeed(float degPerSecond);

    /**
     * @return current speed (deg per second).
     */
    float getSpeed() const;

    /**
     * Get current stepper position in degrees
     * @return
     */
    virtual float getPosition() const = 0;

protected:
    const StepperSpecs& _stepper;

    const uint16_t _ms;

    float _speed = 0;
};
