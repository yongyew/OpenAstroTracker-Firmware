#include "Stepper.hpp"

Stepper::Stepper(
    const int spr,
    const float circumference,
    const bool supportsMicrostepping,
    const uint16_t maxStepsPerSecond) : spr(spr),
                                        circumference(circumference),
                                        supportsMicrostepping(supportsMicrostepping),
                                        maxStepsPerSecond(maxStepsPerSecond) {}

int Stepper::getSPR() const {
    return spr;
}

float Stepper::getPulleyCircumference() const {
    return circumference;
}

bool Stepper::isMicrosteppingSupported() const {
    return supportsMicrostepping;
}

uint16_t Stepper::getMaxStepsPerSecond() const {
    return maxStepsPerSecond;
}