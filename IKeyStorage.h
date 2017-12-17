#ifndef IKEYSTORAGE_H
#define IKEYSTORAGE_H

#include "Key.h"

class IKeyStorage
{
public:
    virtual ~IKeyStorage() {}

    virtual bool contains(const Key& key) = 0;
    virtual bool insert(const Key& existingKey, const Key& newKey) = 0;
    virtual bool remove(const Key& key) = 0;
};

#endif // IKEYSTORAGE_H
