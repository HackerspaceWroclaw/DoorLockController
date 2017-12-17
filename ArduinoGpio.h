#ifndef ARDUINOGPIO_H
#define ARDUINOGPIO_H

#include "IGpio.h"

class ArduinoGpio : public IGpio
{
public:
    ArduinoGpio(int pin, bool initialValue, Mode initialMode);
    virtual ~ArduinoGpio();
    virtual bool read();
    virtual void write(bool newValue);
    virtual Mode getMode();
    virtual void setMode(Mode newMode);

private:
    int pin;
    Mode mode;
    int toAdruinoMode(Mode mode);
};

#endif // ARDUINOGPIO_H
