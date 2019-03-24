#ifndef LED_H
#define LED_H

#include <io.h>


class LED : public IO
{
public:
    LED(uint8_t p, int m = IO::NORMAL): IO(p, m){
        if(m == IO::INVERSE){
            IO::pinMode(OUTPUT_OPEN_DRAIN);
        }
        else{
            IO::pinMode(OUTPUT);
        }
    }
    LED& on(){
        IO::digitalWrite(HIGH);
        return *this;
    }

    LED& off(){
        IO::digitalWrite(LOW);
        return *this;
    }

    LED& toggle(){
        IO::_state? IO::digitalWrite(LOW) : IO::digitalWrite(HIGH);
        _state = !_state;
        return *this;
    }
};

extern LED DEBUG_LED;

#endif // LED_H
