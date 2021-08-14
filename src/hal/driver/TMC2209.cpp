#include "TMC2209.hpp"

#define R_SENSE 0.11f

TMC2209::TMC2209(
    const StepperSpecs& stepper,
    const uint16_t ms,
    Stream* serial,
    const uint8_t address,
    const uint8_t pin_en,
    const uint8_t pin_step,
    const uint8_t pin_dir)
    :
        Driver(stepper, ms),
        _tmcStepper(TMC2209Stepper(serial, R_SENSE, address)),
        _pin_en(pin_en),
        _pin_step(pin_step),
        _pin_dir(pin_dir)
{
}

void TMC2209::setup()
{
    // set driver pins in output mode
    pinMode(_pin_en, OUTPUT);
    pinMode(_pin_step, OUTPUT);
    pinMode(_pin_dir, OUTPUT);

    // enable _stepper (LOW = on, HIGH = off)
    digitalWrite(_pin_en, LOW);

    _tmcStepper.begin();

    // TODO: check if connection suceeded

    // TODO: document these values and why they are used

    _tmcStepper.toff(4);
    _tmcStepper.rms_current(_stepper.getRMSCurrent());
    _tmcStepper.fclktrim(4);
    _tmcStepper.microsteps((_ms <= 1) ? 0 : _ms);
}

float TMC2209::setSpeed(const float degPerSecond)
{
    if (this->_speed != degPerSecond)
    {
        Driver::setSpeed(degPerSecond);

        if (this->_speed >= 0)
        {
            digitalWrite(_pin_dir, HIGH);
        }
        else
        {
            digitalWrite(_pin_dir, LOW);
        }
    }

    return this->_speed;
}

void TMC2209::loop()
{
    if (_stepHelper.step())
    {
        // TODO: use fast digital write with direct port manipulation
        digitalWrite(_pin_step, HIGH);

        // TODO: check if the delays are really needed since digitalWrite takes 3.40us (vs required 1us)
        // typical required signal timing for STEP pin being HIGH is 100ns, lowest time we can wait is 1us
        delayMicroseconds(1);

        digitalWrite(_pin_step, LOW);
        // typical required signal timing for STEP pin being LOW is 100ns, lowest time we can wait is 1us
        delayMicroseconds(1);
    }
}

float TMC2209::getPosition() const
{
    return this->_stepper.getDegPerStep() * static_cast<float>(_stepHelper.getPosition()) / static_cast<float>(_ms);
}