#ifndef ARTEMIS_UTIL_TIMER_H
#define ARTEMIS_UTIL_TIMER_H

class Timer
{
    public:
        Timer(long delay, bool repeat);
        void update(long delta);
        void reset();
        bool is_done();
        bool is_running();
        void stop();
        void set_delay(long delay);
        long get_delay();
        virtual void execute();
        float get_percentage_remaining();

    private:
        long delay;
        bool repeat;
        long acc;
        bool done;
        bool stopped;
};
#endif
