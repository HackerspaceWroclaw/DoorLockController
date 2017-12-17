#include "DualColorLed.h"

#include <Arduino.h>

DualColorLed::DualColorLed(IGpio& redGpio, IGpio& greenGpio):
    redGpio(redGpio),
    greenGpio(greenGpio),
    currentState(State::Off)
{
    redGpio.write(false);
    greenGpio.write(false);
    redGpio.setMode(IGpio::Mode::Output);
    greenGpio.setMode(IGpio::Mode::Output);
}

void DualColorLed::setState(DualColorLed::State newState)
{
    if(currentState == newState)
        return;

    currentState = newState;

    switch(newState) {
    case State::Off:
        redGpio.write(false);
        greenGpio.write(false);
        return;
    case State::Red:
        redGpio.write(true);
        greenGpio.write(false);
        return;
    case State::Green:
        redGpio.write(false);
        greenGpio.write(true);
        return;
    }
}
