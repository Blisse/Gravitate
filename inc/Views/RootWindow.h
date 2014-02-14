#ifndef _ROOT_WINDOW_H__
#define _ROOT_WINDOW_H__

#include "BaseView.h"
#include "Dot.h"
#include "TimerListener.h"

namespace Gravity {
    class RootWindow : public BaseView, public TimerListener {
        bool InitSDL();
        bool InitOpenGL();

        Dot* dot;

    public:
        RootWindow();
        ~RootWindow();
        bool Initialize();
        virtual void PaintSelf();
        virtual bool HandleKeyEventSelf(KeyEvent*);
        void RedefineViewport(int, int);

        virtual void HandleTimer(Timer*);
    };
}

#endif //_ROOT_WINDOW_H__
