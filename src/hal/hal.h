/**
 * This file is used to load all the hardware and platform dependant configurations and helpers. These are e.g. platform
 * and board specific pin configurations, interrupts, etc. Also different addon abstractions will be loaded here so they 
 * can be used in the main code without the need to know the actual implementation.
 **/

#pragma once

#include "axis/RaAxis.hpp"
#include "axis/DecAxis.hpp"
namespace hal
{
    namespace axis
    {
        extern RaAxis ra;
        extern DecAxis dec;
    } // namespace axis
} // namespace hal