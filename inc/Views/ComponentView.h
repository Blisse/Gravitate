#ifndef _COMPONENT_VIEW_H__
#define _COMPONENT_VIEW_H__

#include "SDL/SDL.h"
#include <GL/glut.h>
#include <glm/glm.hpp>
#include <vector>

namespace Gravity {

    class ComponentView {
    private:
        ComponentView* parent;
        bool isVisible;
        glm::vec4 position;

    protected:
        std::vector<ComponentView*> children;

    public:
        virtual void Paint() = 0;
    };
}

#endif //_COMPONENT_VIEW_H__
