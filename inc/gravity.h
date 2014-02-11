#ifndef _GRAVITY_H__
#define _GRAVITY_H__

#include "SDL/SDL.h"
#include <GL/glut.h>

#include <vector>

#include "Timer.h"
#include "SDLEvents.h"
#include "RootWindow.h"

namespace Gravity {

	class GravityGame : public SDLEvents {
		static GravityGame* _gravityInstance;
		bool isRunning;
		RootWindow* window;
		std::vector<Timer*> timersList;

		bool OnInit();
		bool InitSDL();
		bool InitOpenGL();
		void OnEvent(SDL_Event*);
		void OnTimers();
		void OnLoop();
		void OnRender();
		void OnCleanup();

		int OnExecute();

		// overrides
		void OnExit();

		GravityGame();

	public:

		void AddTimer(Timer*);
		void RemoveTimer(Timer*);
		int Execute();
		static GravityGame* Instance();
	};

}

#endif //_GRAVITY_H__
