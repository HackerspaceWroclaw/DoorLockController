#ifndef KEY_H
#define KEY_H

#include <stddef.h>
#include <stdint.h>

class Key {
public:
    enum {
        MAX_KEY_SIZE = 8
    };

    enum class KeyType
    {
        Invalid = 0,
        MifareClassic = 1,
        iButton = 2,
    };

    Key();

    bool isValid() const;
    bool operator==(const Key& rhs) const;

protected:
    Key(KeyType type, size_t size, const void* data);

private:
    bool isBufferEqual(const unsigned char *lhs, const unsigned char* rhs, size_t size) const;

    KeyType type;
    size_t size;
    unsigned char value[MAX_KEY_SIZE];
};

class DallasIButtonKey: public Key {
public:
    enum {UID_SIZE = 8};
    explicit DallasIButtonKey(const uint8_t uid[UID_SIZE]);
};

class MifareClassicKey: public Key {
public:
    enum {NUID_SIZE = 4};
    explicit MifareClassicKey(const uint8_t nuid[NUID_SIZE]);
};

#endif // KEY_H
