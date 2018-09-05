# Introduction

An implementation of electric door lock controller. Currently based on Arduino.
Supporting NFC card and iButton devices as authentication keys.
Currently uses built-in key database as authentication source, but remote source is planned,
as defined in interfaces.

# Building

Arduino v1.8.5 or later is required as a base platform.
Required libraries:
- MFRC522 v1.3.6 or later
- OneWire v2.3.3 or later
Previous verions may work, but are untested.


# Further development
It is planned to abstract Arduino out, and move to
more capable platform, not depending on Arduino.
Also, LDAP support is planned instead of hardcoded key database,
over TLS-secured connection, possibly with client certificate.
