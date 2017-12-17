#ifndef ILOGGER_H
#define ILOGGER_H

class ILogger
{
public:
    virtual ~ILogger() {}

    virtual void debug(const char *format, ...) const = 0;
    virtual void info(const char *format, ...) const = 0;
    virtual void warning(const char* format, ...) const = 0;
    virtual void error(const char* format, ...) const = 0;

    virtual void flush() const;
};

#endif // ILOGGER_H
