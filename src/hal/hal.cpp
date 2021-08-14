// #include "hal.h"

// #include "Configuration.hpp"

// #define DRIVER_TYPES_ALL (RA_DRIVER_TYPE | DEC_DRIVER_TYPE)

// #if DRIVER_TYPES_ALL & DRIVER_TYPE_ULN2003
// #include "driver/ULN2003.hpp"
// #endif

// #if DRIVER_TYPES_ALL & DRIVER_TYPE_TMC2209_UART
// #include "driver/TMC2209.hpp"
// #include "SoftwareSerial.h"
// #endif

// StepperSpecs raStepper(
//     RA_STEPPER_SPR,
//     RA_STEPPER_RATED_CURRENT,
//     RA_STEPPER_VOLTAGE,
//     RA_STEPPER_INDUCTANCE);

// StepperSpecs decStepper(
//     DEC_STEPPER_SPR,
//     DEC_STEPPER_RATED_CURRENT,
//     DEC_STEPPER_VOLTAGE,
//     DEC_STEPPER_INDUCTANCE);

// #if RA_DRIVER_TYPE == DRIVER_TYPE_ULN2003
// ULN2003 raDriver(
//     raStepper,
//     RA_MICROSTEPPING,
//     RA_IN1_PIN,
//     RA_IN2_PIN,
//     RA_IN3_PIN,
//     RA_IN4_PIN);
// #elif RA_DRIVER_TYPE == DRIVER_TYPE_TMC2209_UART
// Stream* raSerial =
// SoftwareSerial raSerial(RA_SERIAL_PORT_RX, RA_SERIAL_PORT_TX);
// TMC2209 raDriver(
//     raStepper,
//     RA_MICROSTEPPING,
//     &raSerial,
//     RA_DRIVER_ADDRESS,
//     RA_EN_PIN,
//     RA_STEP_PIN,
//     RA_DIR_PIN);
// #endif

// #if DEC_DRIVER_TYPE == DRIVER_TYPE_ULN2003
// ULN2003 decDriver(
//     decStepper,
//     DEC_MICROSTEPPING,
//     DEC_IN1_PIN,
//     DEC_IN2_PIN,
//     DEC_IN3_PIN,
//     DEC_IN4_PIN);
// #elif DEC_DRIVER_TYPE == DRIVER_TYPE_TMC2209_UART
// SoftwareSerial decSerial(DEC_SERIAL_PORT_RX, DEC_SERIAL_PORT_TX);
// TMC2209 decDriver(
//     decStepper,
//     DEC_MICROSTEPPING,
//     &decSerial,
//     DEC_DRIVER_ADDRESS,
//     DEC_EN_PIN,
//     DEC_STEP_PIN,
//     DEC_DIR_PIN);
// #endif

// namespace hal
// {
//     namespace axis
//     {

//         RaAxis ra(
//             RA_WHEEL_CIRCUMFERENCE / RA_PULLEY_TEETH * 2.0,
//             raDriver,
//             RA_PULSE_MULTIPLIER);

//         DecAxis dec(
//             DEC_WHEEL_CIRCUMFERENCE / DEC_PULLEY_TEETH * 2.0,
//             decDriver);

//     } // namespace axis
// } // namespace hal

#include "hal.h"

StepperSpecs* hal::stepper::create(uint16_t spr, float ratedCurrent, float voltage, float inductance)
{
    return new StepperSpecs(spr, ratedCurrent, voltage, inductance);
}

Driver* hal::driver::create(StepperSpecs& stepperSpecs, hal::driver::TMC2209Config& config)
{
    return new TMC2209(
        stepperSpecs,
        config.ms,
        config.serial,
        config.address,
        config.pin_en,
        config.pin_step,
        config.pin_dir
    );
}
