#ifndef HARDCODEDKEYSTORAGE_H
#define HARDCODEDKEYSTORAGE_H

#include "IKeyStorage.h"

class HardcodedKeyStorage: public IKeyStorage
{
public:
    HardcodedKeyStorage();

    virtual ~HardcodedKeyStorage();
    virtual bool contains(const Key &inputKey);
    virtual bool insert(const Key &existingKey, const Key &newKey);
    virtual bool remove(const Key &key);

private:
    enum {
        NUMBER_OF_ENTRIES = 1,
    };

    Key keyTable[NUMBER_OF_ENTRIES];
};

#endif // HARDCODEDKEYSTORAGE_H
