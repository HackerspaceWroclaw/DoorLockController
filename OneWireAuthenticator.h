#ifndef ONEWIREAUTHENTICATOR_H
#define ONEWIREAUTHENTICATOR_H

#include "IAuthenticator.h"

#include <OneWire.h>

class ILogger;

class OneWireAuthenticator: public IAuthenticator
{
public:
    OneWireAuthenticator(int interfacePin, const ILogger& logger);
    virtual Key getKey();
private:
    enum {
        ONEWIRE_KEY_SIZE = 8,
    };

    OneWire oneWire;
    const ILogger& logger;
};

#endif // ONEWIREAUTHENTICATOR_H
