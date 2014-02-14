#include <iostream>
#include <iterator>

#include "gravity.h"
#include "BaseView.h"
#include "RootWindow.h"
#include "Dot.h"

using namespace std;

namespace Gravity {

    RootWindow::RootWindow(): BaseView(), TimerListener() {
        Timer* timer = new Timer(1000, true);
        timer->AddTimerListener(this);
        timer->Start();

        dot = new Dot();

        this->AddChild(dot);
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

        gluPerspective(60.0f, ratio, 0.1f, 1000.0f);

        return true;
    }

    void RootWindow::PaintSelf() {

        glHint(GL_PERSPECTIVE_CORRECTION_HINT,GL_NICEST);
        glTranslatef( -5.0f, -5.0f, -50.0f );
        // glRotatef( fXrot, 1.0f, 0.0f, 0.0f );
        // glRotatef( fYrot, 0.0f, 1.0f, 0.0f );
        // glRotatef( fZrot, 0.0f, 0.0f, 1.0f );

        glLineWidth(1.0);
        glBegin(GL_LINES);
            glColor3f(1.0, 0, 0);
            glVertex3f(-1000.0, 0.0, 0.0);
            glVertex3f(1000.0, 0.0, 0.0);
        glEnd();

        glBegin(GL_LINES);
            glColor3f(0, 1.0, 0);
            glVertex3f(0, 0, -1000);
            glVertex3f(0, 0, 1000);
        glEnd();

        glBegin(GL_LINES);
            glColor3f(0, 0, 1.0);
            glVertex3f(0, -1000, 0);
            glVertex3f(0, 1000, 0);
        glEnd();
    }

    bool RootWindow::HandleKeyEventSelf(KeyEvent* keyEvent) {
        cout << "HandleKeyEventSelf on RootWindow reached." << endl;
        switch(keyEvent->GetKey()) {
            case SDLK_ESCAPE: {
                cout << "SDLK_ESCAPE." << endl;
                GravityGame::Instance().Exit();
                return true;
                break;
            }
            default:
                break;
        }

        return false;
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
        if (dot) {
            dot->SetPosition(dot->GetX() + 1.0f, dot->GetY() + 1.0f, dot->GetZ() + 1.0f);
        }
    }
}
