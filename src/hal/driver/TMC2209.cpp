#include "TMC2209.hpp"

TMC2209::TMC2209(
    const StepperSpecs& stepper,
    const uint16_t microstepping,
    Stream* serial,
    const uint8_t address,
    const uint8_t pin_en,
    const uint8_t pin_step,
    const uint8_t pin_dir)
    :
    Driver(stepper, microstepping),
    mTmcStepper(TMC2209Stepper(serial, 0.11f, address)),
    mPin_en(pin_en),
    mPin_step(pin_step),
    mPin_dir(pin_dir)
{
}

void TMC2209::setup()
{
    // set driver pins in output mode
    pinMode(mPin_en, OUTPUT);
    pinMode(mPin_step, OUTPUT);
    pinMode(mPin_dir, OUTPUT);

    // enable mStepper (LOW = on, HIGH = off)
    digitalWrite(mPin_en, LOW);

    mTmcStepper.begin();

    // TODO: check if connection suceeded

    // TODO: document these values and why they are used

    mTmcStepper.toff(4);
    mTmcStepper.rms_current(mStepper.getRMSCurrent());
    mTmcStepper.fclktrim(4);
    mTmcStepper.microsteps((mMicrostepping <= 1) ? 0 : mMicrostepping);
}

float TMC2209::setSpeed(const float degPerSecond)
{
    if (this->mSpeed != degPerSecond)
    {
        Driver::setSpeed(degPerSecond);

        if (this->mSpeed >= 0)
        {
            digitalWrite(mPin_dir, HIGH);
        }
        else
        {
            digitalWrite(mPin_dir, LOW);
        }
    }

    return this->mSpeed;
}

void TMC2209::loop()
{
    if (mSteppingHelper.step())
    {
        // TODO: use fast digital write with direct port manipulation
        digitalWrite(mPin_step, HIGH);

        // TODO: handle this without blocking
        // typical required signal timing for STEP pin being HIGH
        delayMicroseconds(100);
        digitalWrite(mPin_step, LOW);
    }
}

float TMC2209::getPosition() const
{
    return this->mStepper.getDegPerStep() * static_cast<float>(mSteppingHelper.getPosition())
        / static_cast<float>(mMicrostepping);
}