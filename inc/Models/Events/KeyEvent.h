#ifndef _KEY_EVENT_H__
#define _KEY_EVENT_H__

#include <SDL/SDL.h>

#include "Event.h"

namespace Gravity {
  class KeyEvent: Event {
    SDLKey key;
    SDLMod mod;
    Uint16 unicode;

  public:
    KeyEvent(SDLKey, SDLMod, Uint16);
    ~KeyEvent();
    virtual std::string ToString() const;
    virtual void Dispatch();

    SDLKey GetKey();
    SDLMod GetMod();
    Uint16 GetUnicode();

 };
}

#endif //_KEY_EVENT_H__
