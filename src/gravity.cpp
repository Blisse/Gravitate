#include "gravity.h"

namespace Gravity {

	Gravity::Gravity() {
		IsRunning = true;
		RootDisplay = NULL;
	}

	int Gravity::OnExecute()  {
		if (OnInit() == false) {
			return -1;
		}

		SDL_Event Event;

		while (IsRunning) {
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
	    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
	        return false;
	    }
	 
	    if((RootDisplay = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL) {
	        return false;
	    }
	 
	    return true;
	}

	void Gravity::OnEvent(SDL_Event* Event) {
		Gravity::CEvents::OnEvent(Event);
	}

	void Gravity::OnLoop() {

	}

	void Gravity::OnRender() {

	}

	void Gravity::OnCleanup() {
		SDL_Quit();
	}

	void Gravity::OnExit() {
		IsRunning = false;
	}
}