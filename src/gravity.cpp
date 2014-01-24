#include "gravity.h"

namespace Gravity {

	Gravity::Gravity() {

	}

	int Gravity::OnExecute()  {
		if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
			//std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
			return 1;
		}

		SDL_Quit();

		return 0;
	}

	bool Gravity::OnInit() {
		return true;
	}

	void Gravity::OnEvent(SDL_Event* Event) {

	}

	void Gravity::OnLoop() {

	}

	void Gravity::OnRender() {

	}

	void Gravity::OnCleanup() {
		
	}
}