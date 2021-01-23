#include "TMC2209.hpp"

TMC2209::TMC2209(
    const StepperSpecs &stepper,
    Stream *serial,
    const uint8_t address,
    const uint8_t pin_en,
    const uint8_t pin_step,
    const uint8_t pin_dir) : Driver(stepper),
                             tmcStepper(TMC2209Stepper(serial, 0.11f, address)),
                             pin_en(pin_en),
                             pin_step(pin_step),
                             pin_dir(pin_dir)
{
}

void TMC2209::setup()
{
    // set driver pins in output mode
    pinMode(pin_en, OUTPUT);
    pinMode(pin_step, OUTPUT);
    pinMode(pin_dir, OUTPUT);

    // enable stepper (LOW = on, HIGH = off)
    digitalWrite(pin_en, LOW);

    tmcStepper.begin();

    // TODO: check if connection suceeded

    // TODO: document these values and why they are used

// TODO: pass values as constructor parameters if needed
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

    //     _driverDEC = new TMC2209Stepper(serial, rsense, driveraddress);
    //     _driverDEC->begin();
    //     _driverDEC->blank_time(24);
    // #if DEC_AUDIO_FEEDBACK == 1
    //     _driverDEC->en_spreadCycle(1);
    // #endif
    //     _driverDEC->rms_current(rmscurrent);
    //     _driverDEC->TCOOLTHRS(0xFFFFF);
    //     _driverDEC->semin(5);
    //     _driverDEC->semax(2);
    //     _driverDEC->sedn(0b01);
    //     _driverDEC->SGTHRS(stallvalue);
    //     _driverDEC->ihold(DEC_HOLDCURRENT);
}

uint16_t TMC2209::getAvailableMicrosteppingModes() const
{
    // TMC2209 supports all microstepping modes from 1 (fullstep) to 256
    return 1 | 2 | 4 | 8 | 16 | 32 | 64 | 128 | 256;
}

uint16_t TMC2209::getMaxSpeed() const
{
    return stepper.getMaxSpeed() * microstepping;
}

void TMC2209::onMicrosteppingChanged()
{
    if (microstepping <= 1)
    {
        tmcStepper.microsteps(0);
    }
    else
    {
        tmcStepper.microsteps(microstepping);
    }
}

void TMC2209::step()
{
    // TODO: use fast digital write with direct port manipulation
    digitalWrite(pin_step, HIGH);

    // TODO: handle this without blocking
    // typical required signal timing for STEP pin being HIGH
    delayMicroseconds(100);
    digitalWrite(pin_step, LOW);

    // TODO: handle other modes (standalone, full uart etc.)
}

void TMC2209::onDirectionChanged()
{
    digitalWrite(pin_dir, direction);
}