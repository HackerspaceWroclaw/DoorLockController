#ifndef IGPIO_H
#define IGPIO_H

class IGpio
{
public:
    enum class Mode {
        Input,
        InputPullup,
        Output,
    };

    virtual ~IGpio() {}
    virtual bool read() = 0;
    virtual void write(bool value) = 0;
    virtual Mode getMode() = 0;
    virtual void setMode(Mode mode) = 0;
};

#endif // IGPIO_H
