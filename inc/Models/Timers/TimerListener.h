#ifndef _TIMER_LISTENER_H__
#define _TIMER_LISTENER_H__

#include "Timer.h"

namespace Gravity {

    class TimerListener {
    public:
        TimerListener();
        ~TimerListener();

        virtual void HandleTimer(Timer*) = 0;
    };

}

#endif //_TIMER_LISTENER_H__
