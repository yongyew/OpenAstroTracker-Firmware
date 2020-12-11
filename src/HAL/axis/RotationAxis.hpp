#pragma once

#include "../driver/Driver.hpp"

#include "AccelStepper.h"

/**
 * Rotation axis used for most movements of the tracking mount. The axis class calculates
 * conversions from arcsecs to steps of its stepper taking into account gear reductions, 
 * max speed, stepper and driver characteristics etc. It should be used by the mount without
 * exposing detailed information about the used hardware.
 **/
class RotationAxis
{

public:
    /**
     * Construct a new RotationAxis instance.
     * driver - pointer to a specific implementation instance of the Driver interface.
     */
    RotationAxis(const Driver &driver, const float circumference);

    /**
     * Perform initial setup of this axis. This calling setup of the motor driver.
     */
    void setup();

    /**
     * Perform required calculations and make a motor step if needed.
     * This function has to be called periodically.
     */
    void loop();

protected:
    /**
     * Rotate the axis at the specified speed.
     * speed - deg per second. Negative for reversed direction. Zero for stop.
     */
    void setRotationSpeed(const float speed);

    /**
     * Return angle of the axis it moves per stepper full step.
     */
    float getFullStepsPerDeg() const;

    const Driver &driver;

    const float circumference;
private:
    AccelStepper accelstepper;
};
