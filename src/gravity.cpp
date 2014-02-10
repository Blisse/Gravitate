#include "gravity.h"
#include <iostream>

using namespace std;

namespace Gravity {

    GravityGame* GravityGame::_gravityInstance = NULL;

    GravityGame* GravityGame::Instance() {
        if (!GravityGame::_gravityInstance) {
            GravityGame::_gravityInstance = new GravityGame();
        }
        return GravityGame::_gravityInstance;
    }

    GravityGame::GravityGame() {
        isRunning = true;
        window = new RootWindow();
    }

    int GravityGame::OnExecute()  {
        if (OnInit() == false) {
            cerr << "Failed to initialize." << endl;
            return -1;
        }

        SDL_Event Event;
        while (isRunning) {
            while (SDL_PollEvent(&Event)) {
                OnEvent(&Event);
            }

            OnLoop();
            OnRender();
        }

        OnCleanup();
        return 0;
    }

    bool GravityGame::OnInit() {
        return isRunning = window->Initialize();
    }

    void GravityGame::OnEvent(SDL_Event* Event) {
        GravityGame::SDLEvents::OnEvent(Event);
    }

    void GravityGame::OnLoop() {

    }

    void GravityGame::OnRender() {
        /* Clear the color and depth buffers. */
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        /* We don't want to modify the projection matrix. */
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        window->Paint();

        SDL_GL_SwapBuffers();
    }

    void GravityGame::OnCleanup() {
        SDL_Quit();
    }

    void GravityGame::OnExit() {
        isRunning = false;
    }

    int GravityGame::Execute() {
        return GravityGame::OnExecute();
    }
}
