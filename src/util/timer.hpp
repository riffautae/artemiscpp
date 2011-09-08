#ifndef ARTEMIS_UTIL_TIMER_H
#define ARTEMIS_UTIL_TIMER_H

class Timer
{
    public:
        Timer(int delay, bool repeat);
        void update(int delta);
        void reset();
        bool is_done();
        bool is_running();
        void stop();
        void set_delay(int delay);
        int get_delay();
        virtual void execute();
        float get_percentage_remaining();

    private:
        int delay;
        bool repeat;
        int acc;
        bool done;
        bool stopped;
}
#endif
