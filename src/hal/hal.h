/**
 * This file is used to load all the hardware and platform dependant configurations and helpers. These are e.g. platform
 * and board specific pin configurations, interrupts, etc. Also different addon abstractions will be loaded here so they
 * can be used in the main code without the need to know the actual implementation.
 **/

#pragma once

#include "stdint.h" // NOLINT(modernize-deprecated-headers)
#include "Stream.h"

#include "Constants.hpp"
#include "Configuration.hpp"

#define PLATFORM (BOARD & PLATFORM_MASK)

#if BOARD == BOARD_AVR_MKS_GEN_L_V21
#include "platform/atmega2560/board/mks_gen_l_v2.1/board.h"
#else
#error Unsupported platform
#endif

#include "stepper/StepperSpecs.hpp"
#include "driver/Driver.hpp"
#include "driver/TMC2209.hpp"

namespace hal
{
    namespace stepper
    {
        StepperSpecs* create(
            uint16_t spr,
            float ratedCurrent,
            float voltage,
            float inductance);
    }

    namespace driver
    {
        struct TMC2209Config
        {
            uint16_t ms;
            Stream* serial;
            uint8_t address;
            uint8_t pin_en;
            uint8_t pin_step;
            uint8_t pin_dir;
        };

        Driver* create(
            StepperSpecs& stepperSpecs,
            TMC2209Config& config
        );
    }

    Driver* createDriver(

    );
//    template<typename Type>
//    Type* createDriver();
//
//    template<>
//    TMC2209* createDriver(
//        StepperSpecs* raStepper,
//        uint16_t ms,
//        Stream* serial,
//        uint8_t serialAddress,
//        uint8_t pinEN,
//        uint8_t pinSTEP,
//        uint8_t pinDIR
//    );

} // namespace hal