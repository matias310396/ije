#ifndef GAME_H
#define GAME_H
#include "SDL2basics.hpp"
#include <string>
#include "../include/image.hpp"
#include "../include/text.hpp"
#include "../include/audio.hpp"

namespace engine{

  class Game{
    public:
      std::string game_name;
      std::pair<int,int> window_dimensions;
      SDL_Window* window;
      SDL_Renderer* renderer;
      Text* text_1;
      Audio* loop_song;
      Image* images[3];


      Game(){};
      ~Game(){};

      static Game& get_instance();
      inline SDL_Renderer * canvas(){
        return renderer;
      }
      void run();
      void game_init();
      void close();
      bool load_media();
      void set_information(std::string name,std::pair<int,int> dimensions);
      static Game* instance;
  };

}

#endif
