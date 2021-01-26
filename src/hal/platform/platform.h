#include "Configuration.hpp"

#define PLATFORM (BOARD & PLATFORM_MASK)

#if PLATFORM == PLATFORM_AVR
#include "AVR/platform.h"
#elif PLATFORM == PLATFORM_ESP32
#include "ESP32/platform.h"
#else
#error Unsupported platform
#endif