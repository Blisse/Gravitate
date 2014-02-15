#include "Dot.h"
#include <iostream>

#include "SDL/SDL.h"

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

using namespace std;
using namespace Gravity;

Dot::Dot(): BaseObject(), BaseView(), TimerListener() {
    x = 0.0;
    y = 0.0;
    z = 0.0;

    xVel = 0.0;
    yVel = 0.0;
    zVel = 0.0;

    size = 1.0;

    Timer* timer = new Timer(25, true);
    timer->AddTimerListener(this);
    timer->Start();
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

float Dot::GetSize() {
    return this->size;
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
    if (keyEvent->GetType() == KeyEvent::UP) {

        switch(keyEvent->GetKey()) {
            case SDLK_UP: {
                this->yVel -= this->size / 2;
                return true;
            }
            case SDLK_DOWN: {
                this->yVel += this->size / 2;
                return true;
            }
            case SDLK_LEFT: {
                this->xVel += this->size / 2;
                return true;
            }
            case SDLK_RIGHT: {
                this->xVel -= this->size / 2;
                return true;
            }
            default:
                break;
        }


    } else if (keyEvent->GetType() == KeyEvent::DOWN) {

        switch(keyEvent->GetKey()) {
            case SDLK_UP: {
                this->yVel += this->size / 2;
                return true;
            }
            case SDLK_DOWN: {
                this->yVel -= this->size / 2;
                return true;
            }
            case SDLK_LEFT: {
                this->xVel -= this->size / 2;
                return true;
            }
            case SDLK_RIGHT: {
                this->xVel += this->size / 2;
                return true;
            }
            default:
                break;
        }
    }

    return false;
}


void Dot::HandleTimer(Timer* timer) {
    this->SetPosition(this->GetX() + this->xVel,
        this->GetY() + this->yVel,
        this->GetZ() + this->zVel
    );
}
