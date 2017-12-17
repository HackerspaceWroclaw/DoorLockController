#ifndef IAUTHENTICATOR_H
#define IAUTHENTICATOR_H

#include "Key.h"

class IAuthenticator
{
public:
    virtual ~IAuthenticator() {};

    virtual Key getKey() = 0;
};

#endif // IAUTHENTICATOR_H
