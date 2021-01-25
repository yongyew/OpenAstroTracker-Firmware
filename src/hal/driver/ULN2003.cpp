#include "ULN2003.hpp"

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
										  pin_in1(pin_in1),
										  pin_in2(pin_in2),
										  pin_in3(pin_in3),
										  pin_in4(pin_in4),
										  pin_state_sequence(0)
{
	
}

void ULN2003::setup()
{
	pinMode(pin_in1, OUTPUT);
	pinMode(pin_in2, OUTPUT);
	pinMode(pin_in3, OUTPUT);
	pinMode(pin_in4, OUTPUT);
}

uint16_t ULN2003::getMaxSpeed() const
{
	return stepper.getMaxSpeed() * microstepping;
}

void ULN2003::step()
{
	digitalWrite(pin_in1, rot(pin_state_sequence, 0 * microstepping) & 0b1);
	digitalWrite(pin_in2, rot(pin_state_sequence, 1 * microstepping) & 0b1);
	digitalWrite(pin_in3, rot(pin_state_sequence, 2 * microstepping) & 0b1);
	digitalWrite(pin_in4, rot(pin_state_sequence, 3 * microstepping) & 0b1);

	pin_state_sequence = rot(pin_state_sequence, 1);
}

void ULN2003::onDirectionChanged()
{
	rot = (direction == Direction::CLOCKWISE) ? &rotl : &rotr;
}
