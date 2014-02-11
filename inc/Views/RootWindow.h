#ifndef _ROOT_WINDOW_H__
#define _ROOT_WINDOW_H__

#include "BaseView.h"
#include "TimerListener.h"

namespace Gravity {
    class RootWindow : public BaseView, public TimerListener {
        bool InitSDL();
        bool InitOpenGL();

    public:
        RootWindow();
        ~RootWindow();
        bool Initialize();
        virtual void PaintSelf();
        void RedefineViewport(int, int);

        virtual void HandleTimer(Timer*);
    };
}

#endif //_ROOT_WINDOW_H__
