#ifndef CDOORLOCKCONTROLLER_H
#define CDOORLOCKCONTROLLER_H

#include "ArduinoGpio.h"
#include "ArduinoSerialLogger.h"

#include "DoorLock.h"
#include "NfcAuthenticator.h"
#include "OneWireAuthenticator.h"
#include "HardcodedKeyStorage.h"
#include "DualColorLed.h"

class DoorLockController
{
public:
    DoorLockController();
    void run();

private:
    enum {
        NFC_SLAVE_SELECT_PIN = 10,
        NFC_RESET_PIN = 9,
        ONEWIRE_PIN = 8,
        DOOR_PIN = 4,
        LED_RED_PIN = 3,
        LED_GREEN_PIN = 2,
        DOOR_OPEN_TIME_MS = 3000,
        NUM_AUTHENTICATORS=2,
        POLLING_INTERVAL_MS = 250,
        BLINK_INTERVAL_CYCLES = 20
    };

    void heartbeat();
    void checkForKeys();

    ArduinoSerialLogger logger;
    ArduinoGpio greenLedGpio, redLedGpio, doorLockGpio;

    DualColorLed statusLed;
    DoorLock doorLock;
    NfcAuthenticator nfcAuthenticator;
    OneWireAuthenticator oneWireAuthenticator;
    IAuthenticator* authenticators[NUM_AUTHENTICATORS];
    HardcodedKeyStorage keyDatabase;

    bool unauthorizedAccess;
    short heartbeatCounter;
};

#endif // CDOORLOCKCONTROLLER_H
