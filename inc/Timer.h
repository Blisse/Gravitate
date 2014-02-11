#ifndef _TIMER_H__
#define _TIMER_H__

#include <vector>
#include "TimerListener.h"

namespace Gravity {

    class TimerListener;

    class Timer {
        unsigned long startTicks;
        unsigned long delayMS;

        std::vector<TimerListener*> timerListeners;

        bool repeat;
        bool running;

        void AddTimer(Timer*);
        void RemoveTimer(Timer*);

    public:
        Timer(unsigned long, bool);
        ~Timer();
        void Start();
        void Stop();
        bool IsRunning();

        void SetDelay(unsigned long);

        void AddTimerListener(TimerListener*);
        void RemoveTimerListener(TimerListener*);

        void CheckTimer();
        void NotifyListeners();
    };

}

#endif //_TIMER_H__
