#ifndef _WINDOW_ROOT_VIEW_H__
#define _WINDOW_ROOT_VIEW_H__

#include "ComponentView.h"

namespace Gravity {
    class WindowRootView : public ComponentView {

    public:
        WindowRootView() {};
        ~WindowRootView() {};
        void Paint();
    };
}

#endif //_WINDOW_ROOT_VIEW_H__
