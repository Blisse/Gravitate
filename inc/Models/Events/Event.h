#ifndef _EVENT_H__
#define _EVENT_H__

#include <string>

namespace Gravity {
  class Event {
  public:
    Event();
    virtual ~Event();
    virtual std::string ToString() const = 0;
    virtual void Dispatch() = 0;
  };
}

#endif //_EVENT_H__
