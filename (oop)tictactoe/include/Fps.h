#ifndef FPS_H
#define FPS_H

#include <windows.h>

class TimeInterval {
public:
    TimeInterval () :
    initial (GetTickCount()) { }

unsigned getTick () {
    return GetTickCount () - initial;
}

private:
    unsigned initial;
};

class Fps {
public:
    ~Fps () = default;


    Fps () :
    fpsCount (0), fpsCounter (0) { }

    void update () {
    ++fpsCount;

    if (interval.getTick () > 1000) {
        fpsCounter = fpsCount;
        fpsCount = 0;
        interval = TimeInterval ();
    }

    }

    unsigned getFps () {
    return fpsCounter;
    }

private:
    unsigned fpsCount, fpsCounter;
    TimeInterval interval;
};

#endif // FPS_H
