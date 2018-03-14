#include "NfcAuthenticator.h"

#include "ILogger.h"
#include <SPI.h>

NfcAuthenticator::NfcAuthenticator(int nfcSlaveSelectPin, int nfcResetPin, const ILogger &logger):
    rfid(nfcSlaveSelectPin, nfcResetPin),
    logger(logger)
{
    SPI.begin();
    rfid.PCD_Init();
}

NfcAuthenticator::~NfcAuthenticator()
{}

Key NfcAuthenticator::getKey()
{
    if(!initializeCard())
        return Key();

    uint8_t *nuid =  rfid.uid.uidByte;
    logger.debug("NFC tag detected, NUID: %02hhX %02hhX %02hhX %02hhX", nuid[0], nuid[1], nuid[2], nuid[3]);

    releaseCard();

    return MifareClassicKey(rfid.uid.uidByte);
}

bool NfcAuthenticator::initializeCard()
{
    if (!rfid.PICC_IsNewCardPresent())
        return false;

    if (!rfid.PICC_ReadCardSerial())
        return false;

    auto piccType = rfid.PICC_GetType(rfid.uid.sak);
    if (piccType == MFRC522::PICC_TYPE_NOT_COMPLETE)
    {
        logger.warning("Incomplete UID detected in SAK procedure");
        return false;
    }

    logger.debug("Tag type: %d", static_cast<int>(piccType));
    return true;
}

void NfcAuthenticator::releaseCard()
{
    rfid.PICC_HaltA();
    rfid.PCD_StopCrypto1();
}
