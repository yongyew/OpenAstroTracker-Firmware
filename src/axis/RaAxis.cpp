#include "RaAxis.hpp"

#include "Constants.hpp"

RaAxis::RaAxis(
    const float transmission,
    Driver* driver,
    const float guidingSpeedFactor)
    : RotationAxis(transmission, driver),
      _isTrackingEnabled(false),
      _guidingDirection(NONE),
      _guidingSpeedFactor(guidingSpeedFactor)
{
}

void RaAxis::setTracking(const bool enable)
{
    _isTrackingEnabled = enable;
    updateRotationSpeed();
}

void RaAxis::setGuiding(const Direction direction)
{
    _guidingDirection = direction;
    updateRotationSpeed();
}

void RaAxis::updateRotationSpeed()
{
    float speed = 0.0f;

    if (_isTrackingEnabled)
    {
        speed += EARTH_ROTATION_SPEED;
    }

    speed += static_cast<float>(_guidingDirection) * _guidingSpeedFactor * EARTH_ROTATION_SPEED;

    setSpeed(speed);
}

void RaAxis::setSlewingRate(float rate) {
    this->_slewingRate = rate;
}
