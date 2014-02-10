#ifndef _ROOT_WINDOW_H__
#define _ROOT_WINDOW_H__

#include "BaseView.h"

namespace Gravity {
    class RootWindow : public BaseView {
        bool InitSDL();
        bool InitOpenGL();

    public:
        RootWindow();
        ~RootWindow();
        bool Initialize();
        virtual void PaintSelf();
        void RedefineViewport(int, int);
    };
}

#endif //_ROOT_WINDOW_H__
