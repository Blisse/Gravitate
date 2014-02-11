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
        BaseView();
        virtual ~BaseView();

        virtual void Paint();
        virtual void PaintSelf() = 0;

        void AddChild(BaseView*);
    };
}

#endif //_BASE_VIEW_H__
