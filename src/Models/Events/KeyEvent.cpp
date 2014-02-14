#include "KeyEvent.h"
#include "gravity.h"

namespace Gravity
{
    KeyEvent::KeyEvent(SDLKey sym, SDLMod mod, Uint16 unicode): Event() {
        this->key = sym;
        this->mod = mod;
        this->unicode = unicode;
    }

    KeyEvent::~KeyEvent() {
    }

    std::string KeyEvent::ToString() const {
        return "KeyEvent";
    }

    void KeyEvent::Dispatch() {
        GravityGame::Instance().HandleKeyEvent(this);
    }

    SDLKey KeyEvent::GetKey() {
        return key;
    }

    SDLMod KeyEvent::GetMod() {
        return mod;
    }

    Uint16 KeyEvent::GetUnicode() {
        return unicode;
    }

}
