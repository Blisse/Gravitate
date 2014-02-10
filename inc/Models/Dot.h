#ifndef _DOT_H__
#define _DOT_H__

#include "BaseObject.h"

namespace Gravity {
    class Dot: public BaseObject {

        private:
            float x, y;
            float xVel, yVel;

        public:
            Dot();
            void handle_input();
            void move();
            void show();
    };
}

#endif //_DOT_H__
