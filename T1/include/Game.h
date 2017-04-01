#ifndef __GAME_H
#define __GAME_H

#include "State.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

using std::string;

class Game {
  private:
    static Game* instance;
    SDL_Window* window;
    SDL_Renderer* renderer;
    State* state;

  public:
    Game(string title, int width, int height);
    ~Game();
    SDL_Renderer* GetRenderer();
    State& GetState();
    static Game& GetInstance();
    void Run();
};

#endif
