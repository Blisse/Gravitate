#ifndef _KEY_EVENT_H__
#define _KEY_EVENT_H__

#include <SDL/SDL.h>

#include "Event.h"

namespace Gravity {
    class KeyEvent: Event {

    public:
        enum TYPE {
            UP = 0,
            DOWN
        };

        KeyEvent(SDLKey, SDLMod, Uint16, TYPE);
        ~KeyEvent();
        virtual std::string ToString() const;
        virtual void Dispatch();

        SDLKey GetKey();
        SDLMod GetMod();
        Uint16 GetUnicode();
        TYPE GetType();

    private:
        SDLKey key;
        SDLMod mod;
        Uint16 unicode;
        TYPE type;

 };
}

#endif //_KEY_EVENT_H__
