#ifndef ARDUINOSERIALLOGGER_H
#define ARDUINOSERIALLOGGER_H

#include "ILogger.h"
#include <Arduino.h>

#define Serial_ HardwareSerial
class ArduinoSerialLogger : public ILogger
{
public:
    explicit ArduinoSerialLogger(Serial_& hardwareSerial);
    virtual ~ArduinoSerialLogger();

    virtual void debug(const char *format, ...) const;
    virtual void info(const char *format, ...) const;
    virtual void warning(const char* format, ...) const;
    virtual void error(const char* format, ...) const;

    virtual void flush() const;

private:
    enum {
        DEBUG_CONSOLE_BAUD = 9600
    };

    void formatLog(const char* level, const char* format, va_list args) const;

    Serial_& hardwareSerial;
};

#endif // ARDUINOSERIALLOGGER_H
