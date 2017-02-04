#include <timerunit.h>

TimerUnit::TimerUnit(int inr)
    : interval(inr)
{
    std::time(&previousTime);
    presentTime = previousTime;
    delta = 0;
}

TimerUnit::TimerUnit(void)
{
    interval = 5;
    std::time(&previousTime);
    presentTime = previousTime;
    delta = 0;
}

const bool TimerUnit::checkTime()
{
    std::time(&presentTime);
    delta = std::difftime(presentTime, previousTime);
    if(delta >= interval)
    {
        delta = 0;
        previousTime = presentTime;
        return true;
    }
    else
        return false;
}
