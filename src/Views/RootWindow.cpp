#include <iostream>

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include "Views/RootWindow.h"

using namespace std;

namespace Gravity {

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

        gluPerspective(45.0f, ratio, 1.0f, 1000.0f);

        return true;
    }

    void RootWindow::Paint() {

        /* Clear the color and depth buffers. */
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        /* We don't want to modify the projection matrix. */
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();



        SDL_GL_SwapBuffers();
    }

    void RootWindow::RedefineViewport(int width, int height) {
        glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glViewport(0,0,width, height);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluPerspective(45.0f,(GLfloat)width/(GLfloat) height,1.0f,1000.0f);
        glutPostRedisplay();
    }
}
