#include "TMC2209.hpp"

#include "AccelStepper.h"

TMC2209::TMC2209(
    const Stepper &stepper,
    Stream *serial,
    const uint8_t address,
    uint8_t stepPin) : Driver(stepper, AccelStepper::DRIVER, stepPin),
                       tmcStepper(TMC2209Stepper(serial, 0.11f, address))
{
}

void TMC2209::setup()
{
    tmcStepper.begin();

    // TODO: document these values and why they are used

#if RA_AUDIO_FEEDBACK == 1
    tmcStepper->en_spreadCycle(1);
#endif
    tmcStepper.toff(4);
    tmcStepper.blank_time(24);
    tmcStepper.rms_current(stepper.getRMSCurrent());
    tmcStepper.fclktrim(4);
    tmcStepper.TCOOLTHRS(0xFFFFF);
    tmcStepper.ihold(1); // its save to assume that the only time RA stands still is during parking and the current can be limited to a minimum
    //tmcStepper.semin(2);
    //tmcStepper.semax(5);
    //tmcStepper.sedn(0b01);
    //tmcStepper.SGTHRS(10);
    tmcStepper.irun(31);
}

uint16_t TMC2209::getAvailableMicrosteppingModes() const
{
    // TMC2209 supports all microstepping modes from 1 (fullstep) to 256
    return 1 | 2 | 4 | 8 | 16 | 32 | 64 | 128 | 256;
}

uint16_t TMC2209::getMaxSpeed() const
{
    return stepper.getMaxSpeed();
}

void TMC2209::updateMicrostepping(const uint16_t microstepping)
{
    tmcStepper.microsteps((microstepping <= 1) ? 0 : microstepping);
}