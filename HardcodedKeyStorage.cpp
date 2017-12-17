#include "HardcodedKeyStorage.h"

HardcodedKeyStorage::HardcodedKeyStorage():
    keyTable( {
              MifareClassicKey((const uint8_t[]) { 0x01, 0x02, 0x03, 0x04 }), // SAMPLE. DO NOT USE!
    })
{}

HardcodedKeyStorage::~HardcodedKeyStorage() {}

bool HardcodedKeyStorage::contains(const Key& inputKey)
{
    if(!inputKey.isValid())
        return false;

    for(const Key& keyFromTable: keyTable)
    {
        if(inputKey == keyFromTable)
            return true;
    }

    return false;
}

bool HardcodedKeyStorage::insert(const Key &existingKey, const Key &newKey)
{
    (void) existingKey;
    (void) newKey;
    return false;
}

bool HardcodedKeyStorage::remove(const Key &key)
{
    (void) key;
    return false;
}
