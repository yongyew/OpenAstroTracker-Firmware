#pragma once

#include "../stepper/Stepper.hpp"

#include "stdint.h"
#include "AccelStepper.h"

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
     * Construct new driver with provided hardware specifications.
     * 
     * stepper - reference to the stepper specifications
     * interfaceType - type of driver interface (wires)
     * pin1 - first pin
     * pin2 - second pin
     * pin3 - third pin
     * pin4 - fourth pin
     */
    Driver(
        const Stepper &stepper,
        AccelStepper::MotorInterfaceType interfaceType,
        uint8_t pin1 = NOT_A_PIN,
        uint8_t pin2 = NOT_A_PIN,
        uint8_t pin3 = NOT_A_PIN,
        uint8_t pin4 = NOT_A_PIN);

    /**
     * Perform required preparations (e.g. setting up UART connection, max speed,
     * microstepping etc.)
     */
    virtual void setup() = 0;

    /**
     * Move the motor at the specified speed (steps per second).  
     * Negative speed value leads to reversed direction.
     * Speed 0 leads to a stop of the motor.
     * limit defines the amount of steps to move at the specified speed.
     * maxSteps 0 lead to infinite movement (until another call of this function).
     */
    // virtual void move(float speed, int microstepping = 1, float limit = 0) const = 0;

    /**
     * Return amount of full steps per revolution.
     */
    uint16_t getStepperSPR() const;

    /**
     * Return available microstepping modes as bitmask of 16 bits. Modes are 
     * represented from lowest to highest bit (1,2,4,8,16,32,64,128,256...) respectively.
     * E.g. 0000_0000_0000_1011 stands for available modes: full step, half step and 8.
     * If microstepping is not supported, this function will return value 1.
     */
    virtual uint16_t getAvailableMicrosteppingModes() const = 0;

    /**
     * Set microstepping. The value has to be power of 2 between 1 and 256.
     */
    void setMicrostepping(const uint16_t microstepping);

    /**
     * Get currently selected microstepping mode.
     */
    uint16_t getMicrostepping() const;

    /**
     * Return maximal speed (steps per second).
     */
    virtual uint16_t getMaxSpeed() const = 0;

protected:
    virtual void updateMicrostepping(uint16_t microstepping) = 0;

    const Stepper &stepper;

    const AccelStepper accelStepper;
    uint16_t microstepping;
};
