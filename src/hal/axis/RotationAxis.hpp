#pragma once

#include "../driver/Driver.hpp"

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

    /**
     * Get current axis position in degrees.
     */
    float getCurrentPosition() const;

    /**
     * Set current axis position.
     * 
     * @param degrees Position to be set in degrees. Negative values are allowed.
     */
    void setCurrentPosition(float degrees);

protected:
    /**
     * Construct a new RotationAxis instance.
     * 
     * @param transmission  transmission value of this axis. 
     *                      If e.g. RA ring circumference is 100mm and used pulley is 20mm,
     *                      resulting transmission would be (circ_ra / circ_pulley) = (100 / 20) = 5
     * @param driver        reference to a specific implementation instance of the Driver interface.
     */
    RotationAxis(const float transmission, Driver &driver);

    /**
     * Rotate the axis at the specified speed.
     * 
     * @param degPerSecond Rotation speed. Negative for reversed direction. Zero for stop.
     */
    void setSpeed(const float degPerSecond);

    /**
     * Rotate the axis at the specified speed to a target and stop after this target was reached. The last loop() call 
     * will also call onTargetReached() so the subclass can react.
     * 
     * @param degrees target of rotation in deg (absolute value)
     */
    void moveTo(const float degrees);

    /**
     * Rotate the axis at the specified speed to a target and stop after this target was reached. The last loop() call 
     * will also call onTargetReached() so the subclass can react.
     * 
     * @param degrees target of rotation in deg (relative value)
     */
    void moveBy(const float degrees);

    /**
     * Callback to be called after the rotation target was reached. This function will be called at the end of the 
     * loop() call which leads to reaching the target set in rotateToTarget().
     */
    virtual void onTargetReached();
    
    /**
     * Return amount of degrees this axis makes with one step of the stepper motor. Takes transmissin, microstepping
     * and stepper characteristics into account.
     */
    const float getDegPerStep() const;

private:
    /**
     * Return amount of steps needed to rotate this axis by one degree concidering current microstepping.
     */
    float getStepsPerDeg() const;

    /**
     * Current position of this axis in degrees.
     */
    float currentPosition = 0.0f;

    const float transmission;

    Driver &driver;

    /**
     * Current speed in degrees per second.
     */
    float speed = 0;

    /**
     * Time interval of two steps in microseconds.
     */
    float steppingInterval = 0;

    /**
     * Distance in degrees to the target. 0 if there is no target set.
     */
    float degsToTarget = 0;

    unsigned long lastStepTime = 0.0f;
};
