#include "SDLEvents.h"
#include "gravity.h"
#include "KeyEvent.h"
#include <iostream>

using namespace std;

namespace Gravity {

    SDLEvents::SDLEvents() {

    }

    SDLEvents::~SDLEvents() {
        //Do nothing
    }

    void SDLEvents::OnEvent(SDL_Event* Event) {
        switch(Event->type) {
            case SDL_ACTIVEEVENT: {
                cout << "SDL_ACTIVEEVENT" << endl;
                switch(Event->active.state) {
                    case SDL_APPMOUSEFOCUS: {
                        if (Event->active.gain) {
                            OnMouseFocus();
                        } else {
                            OnMouseBlur();
                        }
                        break;
                    }
                    case SDL_APPINPUTFOCUS: {
                        if (Event->active.gain) {
                            OnInputFocus();
                        } else {
                            OnInputBlur();
                        }
                        break;
                    }
                    case SDL_APPACTIVE:  {
                        if (Event->active.gain) {
                            OnRestore();
                        } else {
                            OnMinimize();
                        }
                        break;
                    }
                }
                break;
            }

            case SDL_KEYDOWN: {
                cout << "SDL_KEYDOWN" << endl;
                OnKeyDown(Event->key.keysym.sym,
                    Event->key.keysym.mod,
                    Event->key.keysym.unicode);
                break;
            }

            case SDL_KEYUP: {
                cout << "SDL_KEYUP" << endl;
                OnKeyUp(Event->key.keysym.sym,
                    Event->key.keysym.mod,
                    Event->key.keysym.unicode);
                break;
            }

            case SDL_MOUSEMOTION: {
                cout << "SDL_MOUSEMOTION" << endl;
                OnMouseMove(Event->motion.x,
                    Event->motion.y,
                    Event->motion.xrel,
                    Event->motion.yrel,
                    (Event->motion.state & SDL_BUTTON(SDL_BUTTON_LEFT)) != 0,
                    (Event->motion.state & SDL_BUTTON(SDL_BUTTON_RIGHT)) != 0,
                    (Event->motion.state & SDL_BUTTON(SDL_BUTTON_MIDDLE)) != 0);
                break;
            }

            case SDL_MOUSEBUTTONDOWN: {
                cout << "SDL_MOUSEBUTTONDOWN" << endl;
                switch(Event->button.button) {
                    case SDL_BUTTON_LEFT: {
                        OnLButtonDown(Event->button.x,Event->button.y);
                        break;
                    }
                    case SDL_BUTTON_RIGHT: {
                        OnRButtonDown(Event->button.x,Event->button.y);
                        break;
                    }
                    case SDL_BUTTON_MIDDLE: {
                        OnMButtonDown(Event->button.x,Event->button.y);
                        break;
                    }
                }
                break;
            }

            case SDL_MOUSEBUTTONUP:  {
                cout << "SDL_MOUSEBUTTONUP" << endl;
                switch(Event->button.button) {
                    case SDL_BUTTON_LEFT: {
                        OnLButtonUp(Event->button.x,Event->button.y);
                        break;
                    }
                    case SDL_BUTTON_RIGHT: {
                        OnRButtonUp(Event->button.x,Event->button.y);
                        break;
                    }
                    case SDL_BUTTON_MIDDLE: {
                        OnMButtonUp(Event->button.x,Event->button.y);
                        break;
                    }
                }
                break;
            }

            case SDL_JOYAXISMOTION: {
                OnJoyAxis(Event->jaxis.which,Event->jaxis.axis,Event->jaxis.value);
                break;
            }

            case SDL_JOYBALLMOTION: {
                OnJoyBall(Event->jball.which, Event->jball.ball, Event->jball.xrel, Event->jball.yrel);
                break;
            }

            case SDL_JOYHATMOTION: {
                OnJoyHat(Event->jhat.which, Event->jhat.hat, Event->jhat.value);
                break;
            }
            case SDL_JOYBUTTONDOWN: {
                OnJoyButtonDown(Event->jbutton.which, Event->jbutton.button);
                break;
            }

            case SDL_JOYBUTTONUP: {
                OnJoyButtonUp(Event->jbutton.which, Event->jbutton.button);
                break;
            }

            case SDL_QUIT: {
                cout << "SDL_QUIT" << endl;
                OnExit();
                break;
            }

            case SDL_SYSWMEVENT: {
            //Ignore
                break;
            }

            case SDL_VIDEORESIZE: {
                cout << "SDL_VIDEORESIZE" << endl;
                OnResize(Event->resize.w,Event->resize.h);
                break;
            }

            case SDL_VIDEOEXPOSE: {
                cout << "SDL_VIDEOEXPOSE" << endl;
                OnExpose();
                break;
            }

            default: {
                OnUser(Event->user.type, Event->user.code, Event->user.data1, Event->user.data2);
                break;
            }
        }
    }

    void SDLEvents::OnInputFocus() {
        //Pure virtual, do nothing
    }

    void SDLEvents::OnInputBlur() {
        //Pure virtual, do nothing
    }

    void SDLEvents::OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode) {
        KeyEvent* event = new KeyEvent(sym, mod, unicode);
        event->Dispatch();
        delete event;
    }

    void SDLEvents::OnKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode) {
        //Pure virtual, do nothing
    }

    void SDLEvents::OnMouseFocus() {
        //Pure virtual, do nothing
    }

    void SDLEvents::OnMouseBlur() {
        //Pure virtual, do nothing
    }

    void SDLEvents::OnMouseMove(int mX, int mY, int relX, int relY, bool Left, bool Right, bool Middle) {
        //Pure virtual, do nothing
    }

    void SDLEvents::OnMouseWheel(bool Up, bool Down) {
        //Pure virtual, do nothing
    }

    void SDLEvents::OnLButtonDown(int mX, int mY) {
        //Pure virtual, do nothing

    }
    void SDLEvents::OnLButtonUp(int mX, int mY) {
        //Pure virtual, do nothing
    }

    void SDLEvents::OnRButtonDown(int mX, int mY) {
        //Pure virtual, do nothing
    }

    void SDLEvents::OnRButtonUp(int mX, int mY) {
        //Pure virtual, do nothing
    }

    void SDLEvents::OnMButtonDown(int mX, int mY) {
        //Pure virtual, do nothing
    }

    void SDLEvents::OnMButtonUp(int mX, int mY) {
        //Pure virtual, do nothing
    }

    void SDLEvents::OnJoyAxis(Uint8 which,Uint8 axis,Sint16 value) {
        //Pure virtual, do nothing
    }

    void SDLEvents::OnJoyButtonDown(Uint8 which,Uint8 button) {
        //Pure virtual, do nothing
    }

    void SDLEvents::OnJoyButtonUp(Uint8 which,Uint8 button) {
        //Pure virtual, do nothing
    }

    void SDLEvents::OnJoyHat(Uint8 which,Uint8 hat,Uint8 value) {
        //Pure virtual, do nothing
    }

    void SDLEvents::OnJoyBall(Uint8 which,Uint8 ball,Sint16 xrel,Sint16 yrel) {
        //Pure virtual, do nothing
    }

    void SDLEvents::OnMinimize() {
        //Pure virtual, do nothing
    }

    void SDLEvents::OnRestore() {
        //Pure virtual, do nothing
    }

    void SDLEvents::OnResize(int w,int h) {
        //Pure virtual, do nothing
    }

    void SDLEvents::OnExpose() {
        //Pure virtual, do nothing
    }

    void SDLEvents::OnExit() {
        //Pure virtual, do nothing
        GravityGame::Instance().Exit();
    }

    void SDLEvents::OnUser(Uint8 type, int code, void* data1, void* data2) {
        //Pure virtual, do nothing
    }
}
