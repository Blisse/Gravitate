#include "Dot.h"

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

using namespace Gravity;

Dot::Dot(): BaseObject(), BaseView() {
    x = 0.0;
    y = 0.0;
    z = 0.0;

    xVel = 0.0;
    yVel = 0.0;
    zVel = 0.0;

    size = 1.0;
}

Dot::~Dot() {

}

float Dot::GetX() {
    return this->x;
}

float Dot::GetY() {
    return this->y;
}

float Dot::GetZ() {
    return this->z;
}

void Dot::SetPosition(float x, float y, float z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

void Dot::PaintSelf() {

    glBegin(GL_QUADS); // of the color cube

        // Top-face
        glColor3f(0.0f, 1.0f, 0.0f); // green
        glVertex3f((float)x + size, (float)y + size, (float)z - size);
        glVertex3f((float)x - size, (float)y + size, (float)z - size);
        glVertex3f((float)x - size, (float)y + size, (float)z + size);
        glVertex3f((float)x + size, (float)y + size, (float)z + size);

        // Bottom-face
        glColor3f(1.0f, 0.0f, 0.0f); // red
        glVertex3f((float)x + size, (float)y - size, (float)z + size);
        glVertex3f((float)x - size, (float)y - size, (float)z + size);
        glVertex3f((float)x - size, (float)y - size, (float)z - size);
        glVertex3f((float)x + size, (float)y - size, (float)z - size);

        // Front-face
        glColor3f(1.0f, 0.5f, 0.0f); // orange
        glVertex3f((float)x + size, (float)y + size, (float)z + size);
        glVertex3f((float)x - size, (float)y + size, (float)z + size);
        glVertex3f((float)x - size, (float)y - size, (float)z + size);
        glVertex3f((float)x + size, (float)y - size, (float)z + size);

        // Back-face
        glColor3f(1.0f, 1.0f, 0.0f); // yellow
        glVertex3f((float)x + size, (float)y - size, (float)z - size);
        glVertex3f((float)x - size, (float)y - size, (float)z - size);
        glVertex3f((float)x - size, (float)y + size, (float)z - size);
        glVertex3f((float)x + size, (float)y + size, (float)z - size);

        // Left-face
        glColor3f(0.0f, 0.0f, 1.0f); // blue
        glVertex3f((float)x - size, (float)y + size, (float)z + size);
        glVertex3f((float)x - size, (float)y + size, (float)z - size);
        glVertex3f((float)x - size, (float)y - size, (float)z - size);
        glVertex3f((float)x - size, (float)y - size, (float)z + size);

        // Right-face
        glColor3f(1.0f, 0.0f, 1.0f); // magenta
        glVertex3f((float)x + size, (float)y + size, (float)z - size);
        glVertex3f((float)x + size, (float)y + size, (float)z + size);
        glVertex3f((float)x + size, (float)y - size, (float)z + size);
        glVertex3f((float)x + size, (float)y - size, (float)z - size);

    glEnd(); // of the color cube
}

bool Dot::HandleKeyEventSelf(KeyEvent* keyEvent) {
    return false;
}
