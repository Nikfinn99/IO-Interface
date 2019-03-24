#ifndef BUTTON_H
#define BUTTON_H

#include <io.h>

class BUTTON : public IO
{
protected:
    int _laststate = 0;
    bool _risen, _fallen, _changed;
public:
    BUTTON(uint8_t p, int m = IO::NORMAL): IO(p, m){
        IO::pinMode(INPUT_PULLUP);
    }
    BUTTON& update(){
        int n = get();
        _changed = _laststate != n? true : false;
        _risen = _laststate < n? true : false;
        _fallen = _laststate > n? true : false;
        _laststate = n;
        return *this;
    }
    int get(){
        return IO::digitalRead();
    }
    int lastState(){
        return _laststate;
    }
    bool changingEdge(){
        return _changed;
    }
    bool risingEdge(){
        return _risen;
    }
    bool fallingEdge(){
        return _fallen;
    }
};

#endif // BUTTON_H
