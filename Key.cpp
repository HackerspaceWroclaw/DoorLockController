#include "Key.h"

#include <string.h>

Key::Key() :
    type(KeyType::Invalid),
    size(0),
    value()
{
}

Key::Key(KeyType type, size_t size, const void *data):
    type(type),
    size(size),
    value()
{
    memcpy(value, data, size);
}

bool Key::isValid() const
{
    return type != KeyType::Invalid;
}

bool Key::operator==(const Key &rhs) const
{
    if(type == KeyType::Invalid)
        return type == rhs.type;

    return type == rhs.type && size == rhs.size && isBufferEqual(value, rhs.value, size);
}

bool Key::isBufferEqual(const unsigned char *lhs, const unsigned char *rhs, size_t size) const
{
    unsigned char maskOfDifferences = 0;

    /** This comparison by design checks whole buffers to harden timing attacks */
    for(size_t i = 0; i < size; ++i)
        maskOfDifferences |= lhs[i] ^ rhs[i];

    return (maskOfDifferences == 0);
}

DallasIButtonKey::DallasIButtonKey(const uint8_t uid[]):
    Key(KeyType::iButton, UID_SIZE, uid) {}

MifareClassicKey::MifareClassicKey(const uint8_t nuid[]):
    Key(KeyType::MifareClassic, NUID_SIZE, nuid) {}
