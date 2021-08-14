#include "platform.h"

#include "Configuration.hpp"
#include "../utils/NoopStream.h"

#include <Stream.h>

#define PLATFORM (BOARD & PLATFORM_MASK)

#if PLATFORM == PLATFORM_AVR

#include "atmega2560/platform.h"

#elif PLATFORM == PLATFORM_ESP32
#include "ESP32/platform.h"
#else
#error Unsupported platform
#endif

hal::platform::Platform::Platform(
        Stream *raSerial,
        Stream *decSerial)
        : _serialRA(raSerial),
          _serialDEC(decSerial) {}

Stream *hal::platform::Platform::getSerial(uint8_t rx, uint8_t tx, bool invertLogic) {
    if (IS_SRX_PIN(rx)) {
        // TODO: construct serial (sw)
    }

    // TODO: check if hw serial pins and construct if so

    return nullptr;
}
