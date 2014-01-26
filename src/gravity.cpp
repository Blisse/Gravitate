#include "gravity.h"
#include <iostream>

using namespace std;

namespace Gravity {

	Gravity::Gravity() {
		isRunning = true;
		window = new WindowRootView();
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
		return InitSDL() && InitOpenGL();
	}

	bool Gravity::InitSDL() {

	    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
	    	std::cerr << "Video initialization failed: " << SDL_GetError() << endl;
	        return isRunning = false;
	    }

	    const SDL_VideoInfo* info = SDL_GetVideoInfo();

	    if(!info) {
	    	cerr <<  "Video query failed: " << SDL_GetError() << endl;
	        return isRunning = false;
	    }

	    int width = 640;
	    int height = 480;
	    int bpp = info->vfmt->BitsPerPixel;
	    int flags = SDL_OPENGL;

	    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 5);
	    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 5);
	    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 5);
	    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
	    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	    if(SDL_SetVideoMode(width, height, bpp, flags) == 0) {
	        cerr << "Video mode set failed: " << SDL_GetError() << endl;
	        return isRunning = false;
	    }

	    return true;
	}

	bool Gravity::InitOpenGL() {
	    int width = 640;
	    int height = 480;
	    float ratio = (float) width / (float) height;

	    glShadeModel(GL_SMOOTH);
	    glCullFace(GL_BACK);
	    glFrontFace(GL_CCW);
	    glEnable(GL_CULL_FACE);
	    glClearColor(0, 0, 0, 0);

	    glViewport(0, 0, width, height);

	    glMatrixMode(GL_PROJECTION);
	    glLoadIdentity();

	    /*
	     * EXERCISE:
	     * Replace this with a call to glFrustum.
	     */
	    gluPerspective(60.0, ratio, 1.0, 1024.0);

	    return true;
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
