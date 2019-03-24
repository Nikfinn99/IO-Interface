#ifndef IO_H
#define IO_H

#include <Arduino.h>

class IO
{
protected:
    const uint8_t _pin;
    const int _mode;
    uint8_t _pinmode;
    int _state;

public:
    IO(const uint8_t p, const int m = NORMAL): _pin(p), _mode(m) {}

    IO& pinMode(uint8_t m){
        ::pinMode(_pin, m);
        _pinmode = m;
        return *this;
    }

    uint8_t getPinmode(){
        return _pinmode;
    }

    int digitalRead(){
        int read = ::digitalRead(_pin);
        read = _mode == NORMAL? read?HIGH:LOW : read?LOW:HIGH;
        return read;
    }

    IO& digitalWrite(uint8_t h){
        uint8_t n = _mode == NORMAL? h?HIGH:LOW : h?LOW:HIGH;
        ::digitalWrite(_pin, n);
        _state = n;
        return *this;
    }

    int getDigitalWrite(){
        return _state;
    }

    int analogRead(){
        return ::analogRead(_pin);
    }

    IO& analogWrite(int v){
        ::analogWrite(_pin, v);
        _state = v;
        return *this;
    }

    enum {
        NORMAL,
        INVERSE
    };
};

#include <led.h>
#include <button.h>

#endif
