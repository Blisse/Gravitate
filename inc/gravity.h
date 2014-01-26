#ifndef _GRAVITY_H__
#define _GRAVITY_H__

#include "SDL/SDL.h"
#include <GL/glut.h>

#include "SDLEvents.h"
#include "Views/UniverseView.h"

namespace Gravity {

	class Gravity : public SDLEvents {

		bool isRunning;
		UniverseView* window;

		bool OnInit();
		bool InitSDL();
		bool InitOpenGL();
		void OnEvent(SDL_Event*);
		void OnLoop();
		void OnRender();
		void OnCleanup();

		int OnExecute();

		// overrides
		void OnExit();

	public:
		Gravity();
		int Execute();

	};

}

#endif //_GRAVITY_H__
