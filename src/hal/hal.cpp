#include "hal.h"

#include "driver/TMC2209.hpp"

#define RA_TRANSMISSION RA_WHEEL_CIRCUMFERENCE / RA_PULLEY_TEETH * 2.0

namespace hal
{
    namespace axis
    {
        StepperSpecs raStepper(
            RA_STEPPER_SPR,
            RA_STEPPER_RATED_CURRENT,
            RA_STEPPER_VOLTAGE,                  // TODO: add voltage config
            RA_STEPPER_INDUCTANCE);

        RaDriver raDriver(
            raStepper,
            &Serial,
            RA_DRIVER_ADDRESS,
            RA_EN_PIN,
            RA_STEP_PIN,
            RA_DIR_PIN);

        RaAxis ra(
            RA_TRANSMISSION,
            raDriver,
            RA_PULSE_MULTIPLIER);
    } // namespace axis
} // namespace hal