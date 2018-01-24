#include "DoorLockController.h"

DoorLockController::DoorLockController() :
    logger(Serial),
    greenLedGpio(LED_GREEN_PIN, false, IGpio::Mode::Output),
    redLedGpio(LED_RED_PIN, false, IGpio::Mode::Output),
    doorLockGpio(DOOR_PIN, false, IGpio::Mode::Output),
    statusLed(redLedGpio, greenLedGpio),
    doorLock(doorLockGpio, DoorLock::ActiveState::Low, DOOR_OPEN_TIME_MS),
    nfcAuthenticator(NFC_SLAVE_SELECT_PIN, NFC_RESET_PIN, logger),
    oneWireAuthenticator(ONEWIRE_PIN, logger),
    authenticators{&nfcAuthenticator, &oneWireAuthenticator},
    unauthorizedAccess(false),
    heartbeatCounter(0)
{
    logger.info("Ready. Waiting for keys.");
}

void DoorLockController::heartbeat()
{
    heartbeatCounter = (heartbeatCounter == BLINK_INTERVAL_CYCLES - 1) ? 0 : heartbeatCounter+1;
    if(heartbeatCounter == 0)
            statusLed.setState(unauthorizedAccess ? DualColorLed::State::Red : DualColorLed::State::Green);
}

void DoorLockController::checkForKeys()
{
    for(IAuthenticator* authenticator : authenticators) {
       Key key = authenticator->getKey();
       if(!key.isValid())
           continue;

       if(keyDatabase.contains(key))
       {
           statusLed.setState(DualColorLed::State::Green);
           logger.info("Access granted.");
           unauthorizedAccess = false;
           doorLock.open();
       }
       else
       {
           statusLed.setState(DualColorLed::State::Red);
           logger.error("ACCESS DENIED!");
           unauthorizedAccess = true;
           delay(DOOR_OPEN_TIME_MS);
       }

       return;
    }
}

void DoorLockController::run()
{
    for(;;)
    {
        heartbeat();
        checkForKeys();
        statusLed.setState(DualColorLed::State::Off);
        delay(POLLING_INTERVAL_MS);
    }
}
