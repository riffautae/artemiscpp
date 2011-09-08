#include "Timer.h"

Timer::Timer(int delay, bool repeat)
{
    this->delay = delay;
    this->repeat = repeat;
    this->acc = 0;
}

void Timer::update(int delta)
{
    if (!done && !stopped) {
    acc += delta;

    if (acc >= delay) {
        acc -= delay;

        if (repeat) {
            reset();
        } else {
            done = true;
        }

        execute();
    }
}

void Timer::reset()
{
    stopped = false;
    done = false;
    acc = 0;
}

bool Timer::is_done()
{
    return done;
}

bool Timer::is_running()
{
    return !done && acc < delay && !stopped;
}

void Timer::stop()
{
    stopped = true;
}

void Timer::set_delay(int delay)
{
    this->delay = delay;
}

float Timer::get_percentage_remaining()
{
    if( done )
        return 100.0;
    else if( stopped )
        return 0.0;
    else
        return 1.0 - (float) (delay - acc) / (float) delay;
}

int Timer::get_delay()
{
    return delay;
}

