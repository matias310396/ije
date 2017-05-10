#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include "../../include/game_event.hpp"
#include <list>
#include "keyboard_event.hpp"

namespace engine{

  class Translator {
    Translator();
    ~Translator();

    public:
      static std::list<GameEvent> keyboard_events_to_game_events(std::list<KeyboardEvent>);
      static std::list<GameEvent> game_events;
  };

}

#endif

