#ifndef _BASE_VIEW_H__
#define _BASE_VIEW_H__

#include "SDL/SDL.h"
#include <GL/glut.h>
#include <glm/glm.hpp>
#include <vector>

namespace Gravity {

    class BaseView {
    private:
        BaseView* parent;
        bool isVisible;
        glm::vec4 position;

    protected:
        std::vector<BaseView*> children;

    public:
        virtual void Paint() = 0;
    };
}

#endif //_BASE_VIEW_H__
