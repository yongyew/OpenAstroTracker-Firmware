/**
 * This file is used to load all the hardware and platform dependant configurations and helpers. These are e.g. platform
 * and board specific pin configurations, interrupts, etc. Also different addon abstractions will be loaded here so they 
 * can be used in the main code without the need to know the actual implementation.
 **/

#pragma once

#include "../inc/Config.hpp"

#include "axis/RaAxis.hpp"

// load the platform
#if defined(__AVR__)
#include "platform/AVR/platform.h"
#elif defined(ARDUINO_ARCH_ESP32)
#include "platform/ESP32/platform.h"
#endif

#if RA_DRIVER_TYPE == DRIVER_TYPE_TMC2209_UART
#include "driver/TMC2209.hpp"
typedef TMC2209 RaDriver;
#endif

#if DEC_DRIVER_TYPE == DRIVER_TYPE_TMC2209_UART
#include "driver/TMC2209.hpp"
typedef TMC2209 DecDriver;
#endif

namespace hal 
{
    namespace axis {
        extern RaAxis ra;
    }
}