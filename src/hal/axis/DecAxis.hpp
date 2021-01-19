#pragma once

#include "RotationAxis.hpp"

class DecAxis : public RotationAxis
{
public:

    enum Direction
    {
        SOUTH = -1,
        NONE = 0,
        NORTH = 1
    };

    DecAxis(const float transmission, Driver &driver);

    void setGuiding(const Direction direction);

private:
    void updateRotationSpeed();
};
