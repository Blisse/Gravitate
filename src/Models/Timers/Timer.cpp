#include "SDL/SDL.h"
#include <algorithm>
#include <iostream>

#include "gravity.h"
#include "Timer.h"

using namespace std;
using namespace Gravity;

Timer::Timer(unsigned long delayMS, bool repeat) {
    this->startTicks = 0;
    this->running = false;
    this->delayMS = delayMS;
    this->repeat = repeat;
}

Timer::~Timer() {
    RemoveTimer(this);
}

void Timer::Start() {
    if (!running) {
        AddTimer(this);
        startTicks = SDL_GetTicks();
        running = true;
    }
}

void Timer::Stop() {
    if (running) {
        RemoveTimer(this);
        running = false;
    }
}

bool Timer::IsRunning() {
    return running;
}

void Timer::AddTimerListener(TimerListener* listener) {
    timerListeners.push_back(listener);
}

void Timer::RemoveTimerListener(TimerListener* listener) {
    std::remove(timerListeners.begin(), timerListeners.end(), listener);
}

void Timer::CheckTimer() {
    if (!this->running) {
      return;
    }

    unsigned long currentTimeMS = SDL_GetTicks();
    unsigned long elapsedTimeMS = currentTimeMS - startTicks;
    if (elapsedTimeMS > delayMS) {
      NotifyListeners();

      startTicks = SDL_GetTicks();
      if (!repeat) {
        Stop();
      }
    }
}

void Timer::NotifyListeners() {
    for (int i = 0; i < timerListeners.size(); i++) {
        timerListeners[i]->HandleTimer(this);
    }
}

void Timer::SetDelay(unsigned long delayMS) {
    this->delayMS = delayMS;
}

void Timer::AddTimer(Timer* timer) {
        GravityGame::Instance().AddTimer(timer);
}

void Timer::RemoveTimer(Timer* timer) {
    GravityGame::Instance().RemoveTimer(timer);
}
