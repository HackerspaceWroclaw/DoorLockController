#ifndef NFCAUTHENTICATOR_H
#define NFCAUTHENTICATOR_H

#include "IAuthenticator.h"

#include <MFRC522.h>

class ILogger;

class NfcAuthenticator: public IAuthenticator
{
public:
    NfcAuthenticator(int nfcSlaveSelectPin, int nfcResetPin, const ILogger& logger);
    virtual ~NfcAuthenticator();
    virtual Key getKey();


private:
    bool initializeCard();
    void releaseCard();
    MFRC522 rfid;
    const ILogger& logger;
};

#endif // NFCAUTHENTICATOR_H
