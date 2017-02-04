#ifndef __TIMERUNIT__P
#define __TIMERUNIT__P
#include <ctime>

class TimerUnit
{
    private:
        time_t previousTime;
        int interval;
        time_t presentTime;
        int delta;
    public:
        TimerUnit(int);
        TimerUnit(void);
        const bool checkTime();
};

#endif
