#include "gravity.h"
#include <iostream>
#include <algorithm>

using namespace std;

namespace Gravity {

    GravityGame::GravityGame() {
        isRunning = true;
        timersList = new vector<Timer*>();
    }

    GravityGame::~GravityGame() {

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

            OnTimers();
            OnLoop();
            OnRender();
        }

        OnCleanup();
        return 0;
    }

    bool GravityGame::OnInit() {
        window = new RootWindow();

        return isRunning = window->Initialize();
    }

    void GravityGame::OnEvent(SDL_Event* Event) {
        GravityGame::SDLEvents::OnEvent(Event);
    }

    void GravityGame::OnTimers() {
        for (unsigned int i = 0; i < timersList->size(); i++) {
            timersList->at(i)->CheckTimer();
        }
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

    void GravityGame::Exit() {
        cerr << "Exit called." << endl;
        isRunning = false;
    }

    void GravityGame::HandleKeyEvent(KeyEvent* keyEvent) {
        window->HandleKeyEvent(keyEvent);
    }

    int GravityGame::Execute() {
        return OnExecute();
    }

    void GravityGame::AddTimer(Timer* timer) {
        timersList->push_back(timer);
    }

    void GravityGame::RemoveTimer(Timer* timer) {
        remove(timersList->begin(), timersList->end(), timer);
    }
}
