#include "Sprite.h"
#include "Game.h"

Sprite::Sprite(){
  texture = nullptr;
}

Sprite::Sprite(string file){
  texture = nullptr;
  Open(file);
}

Sprite::~Sprite(){
  if(texture) SDL_DestroyTexture(texture);
}

void Sprite::Open(string file){
  if(texture) SDL_DestroyTexture(texture);
  texture = IMG_LoadTexture(Game::GetInstance().GetRenderer(), file.c_str());
  if(!texture) exit(-1);
  SDL_QueryTexture(texture, nullptr, nullptr, &width, &height);
  SetClip(0,0, width, height);
}

void Sprite::SetClip(int x, int y, int w, int h){
  clipRect = SDL_Rect{x, y, w, h};
}

void Sprite::Render(int x, int y){
  SDL_Rect* dst = new SDL_Rect { x, y, clipRect.w, clipRect.h};
  SDL_RenderCopy(Game::GetInstance().GetRenderer(), texture, &clipRect, dst);
}

int Sprite::GetWidth(){
  return width;
}

int Sprite::GetHeight(){
  return height;
}

bool Sprite::IsOpen(){
  return texture? true : false;
}
