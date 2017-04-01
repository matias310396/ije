#include "Game.h"
#include <iostream>

using namespace std;

Game* Game::instance = nullptr;

void RunAway(const char* function){
  printf("Something's wrong in %s\n", function);
  exit(-1);
}

Game::Game(string title, int width, int height){
  if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
    RunAway("SDL_Init");
  }
  if(!IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF)){
    RunAway("IMG_Init");
  }
  this-> window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
  this-> renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED);
  this-> state = new State();
}

Game::~Game(){
    IMG_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

SDL_Renderer* Game::GetRenderer(){
  return renderer;
}

State& Game::GetState(){
  return *state;
}

Game& Game::GetInstance(){
  if(instance != nullptr){
    return *instance;
  }else{
   instance = new Game("Victor Navarro", 1024, 600);
   return *instance;
  }
}

void Game::Run(){
  while(!(state->QuitRequested())){
    state->Render();
    state->Update(1.4);
    SDL_RenderPresent(renderer);
    SDL_Delay(33);
  }
}
