#include "State.h"

State::State() : quit(false){}

bool State::QuitRequested(){
  return quit;
}

void State::LoadAssets(){
  bg.Open("../Over.jpg");
}

void State::Update(float dt){
  if(SDL_QuitRequested()) quit = true;
}

void State::Render(){
  bg.Render(0,0);
}
