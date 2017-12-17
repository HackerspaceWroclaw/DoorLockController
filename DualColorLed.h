#ifndef DUALCOLORLED_H
#define DUALCOLORLED_H

#include "IGpio.h"

class DualColorLed
{
public:
    enum class State {
        Off,
        Red,
        Green
    };
    DualColorLed(IGpio& redGpio, IGpio& greenGpio);

    void setState(State newState);

private:
    IGpio& redGpio;
    IGpio& greenGpio;
    State currentState;
};

#endif // DUALCOLORLED_H
