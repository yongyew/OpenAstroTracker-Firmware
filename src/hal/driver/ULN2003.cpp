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
				 const uint16_t microstepping,
				 const uint8_t pin_in1,
				 const uint8_t pin_in2,
				 const uint8_t pin_in3,
				 const uint8_t pin_in4) : Driver(stepper, microstepping),
                                          mPin_in1(pin_in1),
                                          mPin_in2(pin_in2),
                                          mPin_in3(pin_in3),
                                          mPin_in4(pin_in4),
                                          mPinStateSequence((microstepping == 1) ? INIT_STATE_FULL_STEP : INIT_STATE_HALF_STEP)
{
}

void ULN2003::setup()
{
	pinMode(mPin_in1, OUTPUT);
	pinMode(mPin_in2, OUTPUT);
	pinMode(mPin_in3, OUTPUT);
	pinMode(mPin_in4, OUTPUT);

	setPins();
}

void ULN2003::loop()
{
	if (this->mSpeed > 0)
	{
        mPinStateSequence = rotl(mPinStateSequence, 1);
	}
	else if (this->mSpeed < 0)
	{
        mPinStateSequence = rotr(mPinStateSequence, 1);
	}

	setPins();
}

inline void ULN2003::setPins()
{
	// TODO: use direct port manipulation to improve performance
	digitalWrite(mPin_in1, bitRead(mPinStateSequence, 0 * mMicrostepping));
	digitalWrite(mPin_in1, bitRead(mPinStateSequence, 1 * mMicrostepping));
	digitalWrite(mPin_in1, bitRead(mPinStateSequence, 2 * mMicrostepping));
	digitalWrite(mPin_in1, bitRead(mPinStateSequence, 3 * mMicrostepping));
}

float ULN2003::getPosition() const
{
	return static_cast<float>(steppingHelper.getPosition()) * mStepper.getDegPerStep() / static_cast<float>(mMicrostepping);
}