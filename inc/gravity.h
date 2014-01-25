#ifndef _GRAVITY_H__
#define _GRAVITY_H__

#include "SDL/SDL.h"
#include "CEvents.h"

namespace Gravity {

	class Gravity : public CEvents {

		bool IsRunning;
		SDL_Surface* RootDisplay;

	public:
		Gravity();
		int OnExecute();

		bool OnInit();
		void OnEvent(SDL_Event*);
		void OnLoop();
		void OnRender();
		void OnCleanup();
		void OnExit();

	};

}

#endif //_GRAVITY_H__