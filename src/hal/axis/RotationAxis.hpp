#pragma once

#include "../driver/Driver.hpp"

#include "AccelStepper.h"

/**
 * Rotation axis used for most movements of the tracking mount. The axis class calculates
 * conversions from arcsecs to steps of its stepper taking into account transmission, 
 * max speed, stepper and driver characteristics etc. It should be used by the mount without
 * exposing detailed information about the used hardware.
 **/
class RotationAxis
{

public:
    /**
     * Perform initial setup of this axis. This function will setup all the hadrware used for it.
     */
    virtual void setup();

    /**
     * Perform required calculations and make a motor step if needed.
     * This function has to be called periodically as fast as possible and at least 1 time per step.
     */
    virtual void loop();

protected:

    /**
     * Construct a new RotationAxis instance.
     * 
     * transmission - transmission value of this axis. If e.g. RA ring circumference is 100mm and used pulley is 20mm,
     *                resulting transmission would be (circ_ra / circ_pulley) = (100 / 20) = 5
     * driver - reference to a specific implementation instance of the Driver interface.
     */
    RotationAxis(const float transmission, Driver &driver);

    /**
     * Rotate the axis at the specified speed.
     * 
     * speed - deg per second. Negative for reversed direction. Zero for stop.
     */
    void rotate(const float speed);

    /**
     * Rotate the axis at the specified speed to a target and stop after this target was reached. The last loop() call 
     * will also call onTargetReached() so the subclass can react.
     * 
     * speed - deg per second. Negative for reversed direction. Zero for stop.
     * target - target of rotation in deg (absolute)
     */
    void rotateToTarget(const float speed, const float target);

    /**
     * Callback to be called after the rotation target was reached. This function will be called at the end of the 
     * loop() call which leads to reaching the target set in rotateToTarget().
     */
    virtual void onTargetReached();

private:

    /**
     * Return amount of steps needed to rotate this axis by one degree concidering current microstepping.
     */
    float getStepsPerDeg() const;

    const float transmission;

    Driver &driver;
};
