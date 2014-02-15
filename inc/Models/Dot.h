#ifndef _DOT_H__
#define _DOT_H__

#include "BaseObject.h"
#include "BaseView.h"
#include "TimerListener.h"

namespace Gravity {
    class Dot: public BaseObject, public BaseView, public TimerListener {

        float x, y, z;
        float xVel, yVel, zVel;
        float size;

    public:
        Dot();
        ~Dot();

        float GetX();
        float GetY();
        float GetZ();
        float GetSize();

        void SetPosition(float x, float y, float z);
        virtual void PaintSelf();
        virtual bool HandleKeyEventSelf(KeyEvent*);
        virtual void HandleTimer(Timer*);
    };
}

#endif //_DOT_H__
