#include "gravity.h"
#include <iostream>

using namespace std;

namespace Gravity {

    Gravity::Gravity() {
        isRunning = true;
        window = new RootWindow();
    }

    int Gravity::OnExecute()  {
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

    bool Gravity::OnInit() {
        return isRunning = window->Initialize();
    }

    void Gravity::OnEvent(SDL_Event* Event) {
        Gravity::SDLEvents::OnEvent(Event);
    }

    void Gravity::OnLoop() {

    }

    void Gravity::OnRender() {
        window->Paint();
    }

    void Gravity::OnCleanup() {
        SDL_Quit();
    }

    void Gravity::OnExit() {
        isRunning = false;
    }

    int Gravity::Execute() {
        return Gravity::OnExecute();
    }
}
