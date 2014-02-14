#ifndef _GRAVITY_H__
#define _GRAVITY_H__

#include "SDL/SDL.h"
#include <GL/glut.h>

#include <vector>

#include "Timer.h"
#include "SDLEvents.h"
#include "RootWindow.h"
#include "KeyEvent.h"

namespace Gravity {

	class GravityGame : public SDLEvents {
		bool isRunning;
		RootWindow* window;
		std::vector<Timer*>* timersList;

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

        GravityGame();
        ~GravityGame();

        GravityGame(GravityGame const&);              // Don't Implement
        void operator=(GravityGame const&); // Don't implement

    public:

		void Exit();
        void HandleKeyEvent(KeyEvent*);

		void AddTimer(Timer*);
		void RemoveTimer(Timer*);
		int Execute();

		static GravityGame& Instance()
        {
            static GravityGame _gravityInstance;
            return _gravityInstance;
        }
	};

}

#endif //_GRAVITY_H__
