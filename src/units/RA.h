#pragma once

#include "stdint.h" // NOLINT(modernize-deprecated-headers)

class RA {
public:
    explicit RA(float degrees);

    RA(uint8_t h, uint8_t m, uint8_t s);

    uint8_t h() const;

    uint8_t m() const;

    uint8_t s() const;

    float deg() const;

private:
    const float degrees;
};
