#include "ULN2003.hpp"

namespace
{
	uint8_t rotl(const uint8_t c)
	{
		return (c << 1) | (c >> 7);
	}

	uint8_t rotr(const uint8_t c)
	{
		return (c >> 1) | (c << 7);
	}
} // namespace

ULN2003::ULN2003(const StepperSpecs &stepper,
				 const uint8_t pin_in1,
				 const uint8_t pin_in2,
				 const uint8_t pin_in3,
				 const uint8_t pin_in4) : Driver(stepper),
										  pin_in1(pin_in1),
										  pin_in2(pin_in2),
										  pin_in3(pin_in3),
										  pin_in4(pin_in4),
										  state(0)
{
}

void ULN2003::setup()
{
	pinMode(pin_in1, OUTPUT);
	pinMode(pin_in1, OUTPUT);
	pinMode(pin_in1, OUTPUT);
	pinMode(pin_in1, OUTPUT);
}

uint16_t ULN2003::getAvailableMicrosteppingModes() const
{
	// Only full step and half step are supported
	return 1 | 2;
}

uint16_t ULN2003::getMaxSpeed() const
{

	return stepper.getMaxSpeed() * microstepping;
}

void ULN2003::step()
{
	if (direction == Direction::CLOCKWISE)
	{
		state = rotl(state);
	}
	else
	{
		state = rotr(state);
	}

	digitalWrite(pin_in1, (state >> 0) & 0b1);
	digitalWrite(pin_in2, (state >> 1) & 0b1);
	digitalWrite(pin_in3, (state >> 2) & 0b1);
	digitalWrite(pin_in4, (state >> 3) & 0b1);
}

void ULN2003::onMicrosteppingChanged()
{
}

void ULN2003::onDirectionChanged()
{
}
