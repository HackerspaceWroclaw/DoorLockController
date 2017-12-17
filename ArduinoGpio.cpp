#include "ArduinoGpio.h"
#include <Arduino.h>

ArduinoGpio::ArduinoGpio(int pin, bool initialValue, IGpio::Mode initialMode):
    pin(pin)
{
    /* There is no protection to prevent from creation of multiple instances
     * of single pin, as Arduino does not support C++ exceptions.
     * Only one parent object may own instance of a pin.
     */
    write(initialValue);
    setMode((initialMode));
}

ArduinoGpio::~ArduinoGpio()
{
    setMode(Mode::Input);
    write(false);
}

bool ArduinoGpio::read()
{
    return (digitalRead(pin) != 0);
}

void ArduinoGpio::write(bool newValue)
{
    digitalWrite(pin, newValue ? HIGH : LOW);
}

IGpio::Mode ArduinoGpio::getMode()
{
    return mode;
}

void ArduinoGpio::setMode(IGpio::Mode newMode)
{
    mode = newMode;
    pinMode(pin, toAdruinoMode(newMode));
}

int ArduinoGpio::toAdruinoMode(IGpio::Mode mode)
{
    switch(mode) {
    case Mode::Input:
        return INPUT;
    case Mode::InputPullup:
        return INPUT_PULLUP;
    case Mode::Output:
        return OUTPUT;
    }
}
