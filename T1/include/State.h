#ifndef STATE_H
#define STATE_H

#include <SDL2/SDL.h>

#include "Sprite.h"

class State {

private:
  Sprite bg;
  bool quit;

public:
  State();
  bool QuitRequested();
  void LoadAssets();
  void Update(float dt);
  void Render();
};

#endif
