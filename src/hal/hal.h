/**
 * This file is used to load all the hardware and platform dependant configurations and helpers. These are e.g. platform
 * and board specific pin configurations, interrupts, etc. Also different addon abstractions will be loaded here so they 
 * can be used in the main code without the need to know the actual implementation.
 **/

#pragma once

#include "../Constants.hpp"
#include "../Configuration.hpp"

#define PLATFORM (BOARD & PLATFORM_MASK)

#if PLATFORM == PLATFORM_AVR
#include "platform/AVR/platform.h"
#elif PLATFORM == PLATFORM_ESP32
#include "platform/ESP32/platform.h"
#else 
#error Unsupported platform
#endif

#include "axis/RaAxis.hpp"
#include "axis/DecAxis.hpp"

#if RA_DRIVER_TYPE == DRIVER_TYPE_TMC2209_UART
#include "driver/TMC2209.hpp"
typedef TMC2209 RaDriver;
#elif RA_DRIVER_TYPE == DRIVER_TYPE_ULN2003
#include "driver/ULN2003.hpp"
typedef ULN2003 RaDriver;
#endif

#if DEC_DRIVER_TYPE == DRIVER_TYPE_TMC2209_UART
#include "driver/TMC2209.hpp"
typedef TMC2209 DecDriver;
#elif DEC_DRIVER_TYPE == DRIVER_TYPE_ULN2003
#include "driver/ULN2003.hpp"
typedef ULN2003 DecDriver;
#endif

namespace hal 
{
    namespace axis {
        extern RaAxis ra;
        extern DecAxis dec;
    }
}