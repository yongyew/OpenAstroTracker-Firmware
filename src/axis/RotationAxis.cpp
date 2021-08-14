#include "RotationAxis.hpp"


RotationAxis::RotationAxis(
    const float transmission,
    Driver* driver)
    : _transmission(transmission),
      _driver(driver)
{
}

void RotationAxis::setup()
{
    _driver->setup();
}

void RotationAxis::loop()
{
    _driver->loop();
}

void RotationAxis::setSpeed(const float degPerSecond)
{
    _driver->setSpeed(degPerSecond * _transmission);
}

float RotationAxis::getCurrentPosition() const
{
    return _positionDeg;
}

void RotationAxis::setCurrentPosition(float degrees)
{
    _positionDeg = degrees;
}