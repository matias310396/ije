#include "../include/texture.hpp"
#include <string>

using namespace engine;

bool Texture::load_image_from_file(std::string image_path){
  free();

  SDL_Texture* new_texture = NULL;

  SDL_Surface* loaded_surface = IMG_Load( image_path.c_str() );
  if( loaded_surface != NULL ){
    new_texture = SDL_CreateTextureFromSurface( renderer, loaded_surface );
    if(new_texture != NULL){

      width = loaded_surface->w;
      height = loaded_surface->h;

    }else{

      printf( "Unable to create texture from %s! SDL Error: %s\n", image_path.c_str(), SDL_GetError() );

    }

    SDL_FreeSurface( loaded_surface );
  }else{
    printf("Unable to load image %s! Image error: %s\n",image_path.c_str(), IMG_GetError() ); 
  }

  texture = new_texture;
  return texture != NULL;
}

void Texture::free(){
  if( texture != NULL){
    SDL_DestroyTexture(texture);
    texture = NULL;
    width = 0;
    height = 0;
  }
}

void Texture::render(int x,int y){
  SDL_Rect render_quad = { x, y, width, height };
  SDL_RenderCopy( renderer, texture, NULL, &render_quad );
}

int Texture::get_width(){
  return width;
}

int Texture::get_height(){
  return height;
}