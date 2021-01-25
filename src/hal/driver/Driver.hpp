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
    enum Direction
    {
        CLOCKWISE = 1,
        ANTICLOCKWISE = -1
    };

    /**
     * Construct new driver with provided hardware specifications.
     * 
     * @param stepper reference to the stepper specifications.
     * @param microstepping microstepping mode to be used.
     * @param direction initial direction to be used. Defaults to clockwise.
     */
    Driver(const StepperSpecs &stepper, const uint16_t microstepping, const Direction direction = Direction::CLOCKWISE);

    /**
     * Perform required preparations (e.g. setting up UART connection, max speed,
     * microstepping etc.)
     */
    virtual void setup() = 0;

    /**
     * Return specs of the connected stepper.
     */
    const StepperSpecs &getStepperSpecs() const;

    /**
     * Get microstepping.
     */
    const uint16_t getMicrostepping() const;

    /**
     * Return maximal speed (steps per second) taking microstepping and driver characteristics into account.
     */
    virtual uint16_t getMaxSpeed() const = 0;

    /**
     * Perform a step in the currently set direction.
     */
    virtual void step() = 0;

    /**
     * Set rotation direction to be used for the steps after this call. If the provided direction differs from the 
     * previos one, onDIrectionChanged will be called on the subclass instance.
     * 
     * @param direction rotation direction
     */
    void setDirection(const Direction direction);

protected:
    virtual void onDirectionChanged() = 0;

    const StepperSpecs &stepper;

    const uint16_t microstepping;

    Direction direction = CLOCKWISE;
};
