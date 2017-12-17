#include "OneWireAuthenticator.h"

#include "ILogger.h"
#include <Arduino.h>

OneWireAuthenticator::OneWireAuthenticator(int interfacePin, const ILogger& logger):
    oneWire(interfacePin),
    logger(logger)
{
    pinMode(interfacePin, INPUT_PULLUP);
}

Key OneWireAuthenticator::getKey()
{
    uint8_t key[ONEWIRE_KEY_SIZE];

    if (!oneWire.search(key)) {
        oneWire.reset_search();
        return Key();
    }

    logger.debug("1-Wire device detected, S/N: %02hhX %02hhX %02hhX %02hhX %02hhX %02hhX %02hhX %02hhX",
             key[0], key[1], key[2], key[3], key[4], key[5], key[6], key[7]);

    oneWire.reset();
    return DallasIButtonKey(key);
}
