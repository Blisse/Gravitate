#ifndef _GRAVITY_H__
#define _GRAVITY_H__

#include "SDL/SDL.h"

namespace Gravity {

	class Gravity {

	public:
		Gravity();
		int OnExecute();

		bool OnInit();
		void OnEvent(SDL_Event*);
		void OnLoop();
		void OnRender();
		void OnCleanup();

	};

}

#endif //_GRAVITY_H__