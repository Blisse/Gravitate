#include <iostream>
#include <iterator>

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include "RootWindow.h"
#include "BaseView.h"

using namespace std;

namespace Gravity {

    RootWindow::RootWindow(): BaseView(), TimerListener() {
        Timer* timer = new Timer(1000, true);
        timer->AddTimerListener(this);
        timer->Start();
    }

    RootWindow::~RootWindow() {

    }

    bool RootWindow::Initialize() {
        return InitSDL() && InitOpenGL();
    }

    bool RootWindow::InitSDL() {

        if (SDL_Init(SDL_INIT_VIDEO) < 0) {
            std::cerr << "Video initialization failed: " << SDL_GetError() << endl;
            return false;
        }

        const SDL_VideoInfo* info = SDL_GetVideoInfo();

        if(!info) {
            cerr <<  "Video query failed: " << SDL_GetError() << endl;
            return false;
        }

        int width = 640;
        int height = 480;
        int bpp = info->vfmt->BitsPerPixel;
        int flags = SDL_OPENGL;

        SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 5);
        SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 5);
        SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 5);
        SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
        SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

        if(SDL_SetVideoMode(width, height, bpp, flags) == 0) {
            cerr << "Video mode set failed: " << SDL_GetError() << endl;
            return false;
        }

        return true;
    }

    bool RootWindow::InitOpenGL() {
        int width = 640;
        int height = 480;
        float ratio = (float) width / (float) height;

        glShadeModel(GL_SMOOTH);
        glCullFace(GL_BACK);
        glFrontFace(GL_CCW);
        glPolygonMode (GL_FRONT_AND_BACK, GL_FILL);
        glEnable(GL_CULL_FACE);
        glEnable(GL_DEPTH_TEST);

        glClearColor(0.1, 0.1, 0.1, 0.0);

        glViewport(0, 0, width, height);

        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();

        gluPerspective(45.0f, ratio, 0.1f, 1000.0f);

        return true;
    }

    void RootWindow::PaintSelf() {

        glHint(GL_PERSPECTIVE_CORRECTION_HINT,GL_NICEST);
        glTranslatef( -5.0f, -5.0f, -50.0f );
        // glRotatef( fXrot, 1.0f, 0.0f, 0.0f );
        // glRotatef( fYrot, 0.0f, 1.0f, 0.0f );
        // glRotatef( fZrot, 0.0f, 0.0f, 1.0f );

        glLineWidth(1.0);
        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_LINES);
            glVertex3f(0.0, 0.0, 0.0);
            glVertex3f(1000, 0, 0);
        glEnd();

        glBegin(GL_LINES);
            glVertex3f(0.0, 0.0, 0.0);
            glVertex3f(0, 0, 1000);
        glEnd();

        glBegin(GL_LINES);
            glVertex3f(0.0, 0.0, 0.0);
            glVertex3f(0, 1000, 0);
        glEnd();

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
           glVertex3f(2.0f, 2.0f, 2.0f);
           glVertex3f(-2.0f, 2.0f, 2.0f);
           glVertex3f(-2.0f, -2.0f, 2.0f);
           glVertex3f(2.0f, -2.0f, 2.0f);

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

    void RootWindow::RedefineViewport(int width, int height) {
        glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glViewport(0,0,width, height);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluPerspective(45.0f,(GLfloat)width/(GLfloat) height,1.0f,1000.0f);
        glutPostRedisplay();
    }

    void RootWindow::HandleTimer(Timer* timer) {
        std::cout << "HandleTimer Reached" << std::endl;
    }
}
