#include "Dot.h"

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

using namespace Gravity;

Dot::Dot(): BaseObject(), BaseView() {
    x = 0;
    y = 0;
    xVel = 0;
    yVel = 0;
}

Dot::~Dot() {

}

void Dot::SetPosition(float x, float y) {


}


void Dot::PaintSelf() {

    glBegin(GL_QUADS); // of the color cube

       // Top-face
       glColor3f(0.0f, 1.0f, 0.0f); // green
       glVertex3f(1.0f, 1.0f, -1.0f);
       glVertex3f(-1.0f, 1.0f, -1.0f);
       glVertex3f(-1.0f, 1.0f, 1.0f);
       glVertex3f(1.0f, 1.0f, 1.0f);

       // Bottom-face
       glColor3f(1.0f, 0.5f, 0.0f); // orange
       glVertex3f(1.0f, -1.0f, 1.0f);
       glVertex3f(-1.0f, -1.0f, 1.0f);
       glVertex3f(-1.0f, -1.0f, -1.0f);
       glVertex3f(1.0f, -1.0f, -1.0f);

       // Front-face
       glColor3f(1.0f, 0.0f, 0.0f); // red
       glVertex3f(1.0f, 1.0f, 1.0f);
       glVertex3f(-1.0f, 1.0f, 1.0f);
       glVertex3f(-1.0f, -1.0f, 1.0f);
       glVertex3f(1.0f, -1.0f, 1.0f);

       // Back-face
       glColor3f(1.0f, 1.0f, 0.0f); // yellow
       glVertex3f(1.0f, -1.0f, -1.0f);
       glVertex3f(-1.0f, -1.0f, -1.0f);
       glVertex3f(-1.0f, 1.0f, -1.0f);
       glVertex3f(1.0f, 1.0f, -1.0f);

       // Left-face
       glColor3f(0.0f, 0.0f, 1.0f); // blue
       glVertex3f(-1.0f, 1.0f, 1.0f);
       glVertex3f(-1.0f, 1.0f, -1.0f);
       glVertex3f(-1.0f, -1.0f, -1.0f);
       glVertex3f(-1.0f, -1.0f, 1.0f);

       // Right-face
       glColor3f(1.0f, 0.0f, 1.0f); // magenta
       glVertex3f(1.0f, 1.0f, -1.0f);
       glVertex3f(1.0f, 1.0f, 1.0f);
       glVertex3f(1.0f, -1.0f, 1.0f);
       glVertex3f(1.0f, -1.0f, -1.0f);

    glEnd(); // of the color cube
}
