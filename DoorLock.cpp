#include "DoorLock.h"

#include <Arduino.h>

DoorLock::DoorLock(IGpio &gpio, DoorLock::ActiveState activeState, DoorLock::TMilliseconds openTime):
    gpio(gpio),
    activeState(activeState),
    openTime(openTime)
{
    deactivate();
    gpio.setMode(IGpio::Mode::Output);
}

void DoorLock::open()
{
    activate();
    delay(openTime);
    deactivate();
}

void DoorLock::activate()
{
    gpio.write(activeState == ActiveState::High);
}

void DoorLock::deactivate()
{
    gpio.write(activeState != ActiveState::High);
}
