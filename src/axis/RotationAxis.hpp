#pragma once

#include "src/hal/driver/Driver.hpp"

/**
 * Rotation axis used for most movements of the tracking mount. The axis class calculates
 * conversions from arcsecs to steps of its stepper taking into account transmission,
 * max speed, stepper and driver characteristics etc. It should be used by the mount without
 * exposing detailed information about the used hardware.
 **/
class RotationAxis {

public:
    /**
     * Perform initial setup of this axis. This function will setup all the hardware used for it.
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
     * @param transmission  Transmission value of this axis.
     *                      If e.g. axis ring radius is 100mm and radius of driving pulley is 20mm,
     *                      resulting transmission would be: <br>
     *                      <b>(pulleyRadius / raRadius) = (20 / 100) = 0.2</b>
     * @param driver        reference to the specific implementation instance of the Driver interface.
     */
    RotationAxis(float transmission, Driver *driver);

    /**
     * Get current axis position in degrees.
     */
    float getCurrentPosition() const;

    /**
     * Set current axis position.
     *
     * @param degrees Position to be set in degrees. Negative values are allowed which lead to reversed direction.
     */
    void setCurrentPosition(float degrees);

    /**
     * Rotate the axis at the specified speed.
     * 
     * @param degPerSecond Rotation speed. Negative for reversed direction. Zero for stop.
     */
    void setSpeed(float degPerSecond);

private:

    /**
     * Current position of this axis in degrees.
     */
    float _positionDeg = 0.0f;

    /**
     * Transmission ratio of this axis
     */
    const float _transmission;

    /**
     * Driver instance used by this axis for movements
     */
    Driver *_driver;

};
