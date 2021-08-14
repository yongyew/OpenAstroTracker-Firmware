//
// Created by Andre Stefanov on 13.03.21.
//

#include "RA.h"

#define SECONDS_PER_MINUTE (60.f)
#define SECONDS_PER_HOUR (60.f * SECONDS_PER_MINUTE)
#define SECONDS_PER_DAY (24.f * SECONDS_PER_HOUR)

#define SECONDS_PER_DEGREE (SECONDS_PER_DAY / 360.0f)
#define DEGREES_PER_SECOND (360.0f / SECONDS_PER_DAY)

RA::RA(float degrees) : degrees(degrees) {}

RA::RA(uint8_t h, uint8_t m, uint8_t s) : degrees(
                                              DEGREES_PER_SECOND *
                                              ((static_cast<float>(h) * SECONDS_PER_HOUR) +
                                               (static_cast<float>(m) * SECONDS_PER_MINUTE) +
                                               (static_cast<float>(s))))
{
}

uint8_t RA::h() const
{
    return (uint8_t)(degrees * SECONDS_PER_DEGREE / SECONDS_PER_HOUR);
}

uint8_t RA::m() const
{
    return (uint8_t)(static_cast<uint32_t>(degrees * SECONDS_PER_DEGREE / SECONDS_PER_MINUTE) % 24);
}

uint8_t RA::s() const
{
    return (uint8_t)(static_cast<uint32_t>(degrees * SECONDS_PER_DEGREE) % (24 * 60));
}

float RA::deg() const
{
    return degrees;
}