#ifndef DOORLOCK_H
#define DOORLOCK_H

#include "IGpio.h"

class DoorLock
{
public:
    enum class ActiveState {
        Low,
        High,
    };
    typedef int TMilliseconds;

    DoorLock(IGpio& gpio, ActiveState activeState, TMilliseconds openTime);
    void open();

private:
    void activate();
    void deactivate();

    IGpio& gpio;
    ActiveState activeState;
    TMilliseconds openTime;
};

#endif // DOORLOCK_H
