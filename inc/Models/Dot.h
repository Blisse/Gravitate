#ifndef _DOT_H__
#define _DOT_H__

#include "BaseObject.h"
#include "BaseView.h"

namespace Gravity {
    class Dot: public BaseObject, public BaseView {

        float x, y;
        float xVel, yVel;

    public:
        Dot();
        ~Dot();

        void SetPosition(float x, float y);
        virtual void PaintSelf();
    };
}

#endif //_DOT_H__
