#ifndef _UNIVERSE_VIEW_H__
#define _UNIVERSE_VIEW_H__

#include "BaseView.h"

namespace Gravity {
    class RootWindow : public BaseView {

        bool InitSDL();
        bool InitOpenGL();

    public:
        RootWindow() {};
        ~RootWindow() {};
        bool Initialize();
        void Paint();
        void RedefineViewport(int, int);
    };
}

#endif //_UNIVERSE_VIEW_H__
