#include "ULN2003.hpp"

ULN2003::ULN2003(const StepperSpecs &stepper) : Driver(stepper)
{

}

void ULN2003::setup()
{
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
}

void ULN2003::setDirection(Direction direction)
{
}

void ULN2003::updateMicrostepping(const uint16_t microstepping)
{
}
