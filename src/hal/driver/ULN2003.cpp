#include "ULN2003.hpp"

#include <Arduino.h>

namespace
{
	/**
	 * Rotate bit value to the left.
	 * 
	 * @param v bit value to be rotated
	 * @param n amount of positions to rotate 
	 */
	inline uint8_t rotl(const uint8_t v, const uint8_t n)
	{
		return ((v << n) | (v >> (8 - n)));
	}

	/**
	 * Rotate bit value to the right.
	 * 
	 * @param v bit value to be rotated
	 * @param n amount of positions to rotate 
	 */
	inline uint8_t rotr(const uint8_t v, const uint8_t n)
	{
		return ((v >> n) | (v << (8 - n)));
	}
} // namespace

ULN2003::ULN2003(const StepperSpecs &stepper,
				 const uint16_t ms,
				 const uint8_t pin_in1,
				 const uint8_t pin_in2,
				 const uint8_t pin_in3,
				 const uint8_t pin_in4) : Driver(stepper, ms),
                                          _pin_in1(pin_in1),
                                          _pin_in2(pin_in2),
                                          _pin_in3(pin_in3),
                                          _pin_in4(pin_in4),
                                          _pinStateSequence((ms == 1) ? INIT_STATE_FULL_STEP : INIT_STATE_HALF_STEP)
{
}

void ULN2003::setup()
{
	pinMode(_pin_in1, OUTPUT);
	pinMode(_pin_in2, OUTPUT);
	pinMode(_pin_in3, OUTPUT);
	pinMode(_pin_in4, OUTPUT);

    applySequenceStateToPins();
}

void ULN2003::loop()
{
	if (this->_speed > 0)
	{
        _pinStateSequence = rotl(_pinStateSequence, 1);
	}
	else if (this->_speed < 0)
	{
        _pinStateSequence = rotr(_pinStateSequence, 1);
	}

    applySequenceStateToPins();
}

inline void ULN2003::applySequenceStateToPins()
{
	// TODO: use direct port manipulation to improve performance if performance is to low
	digitalWrite(_pin_in1, bitRead(_pinStateSequence, 0 * _ms));
	digitalWrite(_pin_in1, bitRead(_pinStateSequence, 1 * _ms));
	digitalWrite(_pin_in1, bitRead(_pinStateSequence, 2 * _ms));
	digitalWrite(_pin_in1, bitRead(_pinStateSequence, 3 * _ms));
}

float ULN2003::getPosition() const
{
	return static_cast<float>(_stepHelper.getPosition()) * _stepper.getDegPerStep() / static_cast<float>(_ms);
}