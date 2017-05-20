#include <iostream>
#include <unordered_map>
#include <string>
#include "../engine/include/game.hpp"
#include "../engine/include/audio.hpp"
#include "../engine/include/image.hpp"
#include "../engine/include/text.hpp"
#include "../engine/include/scene.hpp"
#include "../engine/include/level.hpp"
#include "../include/globals.hpp"

using namespace engine;

Level * main_menu(Game game){

    //Higth, Weigths, Positions
     std::pair<int, int> bg_dimensions(1280,960);
     std::pair<int, int> bg_position(0,0);
     std::pair<int, int> title_position(350,050);
    //
    // //Components
    // Image* bg_menu = new Image(game.renderer, "../assets/images/menu_screen.jpg", bg_position, true, bg_dimensions, bg_dimensions, bg_position);
    // Text* title_menu = new Text("MindScape", "../assets/fonts/font.ttf", 120, game.renderer);
    // Audio* music = new Audio("../assets/audios/loop1-1.mp3", Audio::audio_type::music);
    //
    // //Game Objects
    // GameObject* background = new GameObject("background_menu", bg_position);
    // GameObject* audio_loop = new GameObject("audio_loop", bg_position);
    // GameObject* title = new GameObject("title_menu", title_position);
    //
    // //Constituting game objects
    // background->add_component("bg_image", bg_menu);
    // audio_loop-> add_component("audio", music);
    // title-> add_component("title_menu", title_menu);
    //
    // Level* main_menu = new Level();
    //
    // main_menu->add_object("title_menu", title);
    // main_menu->add_object("bg_menu", background);
    // main_menu->add_object("audio_loop", audio_loop);
    //
       return main_menu;
    //
}

int main(int,char**){
  Game& game = Game::get_instance();
  game.set_information(globals::game_name,globals::window_size);
  game.game_init();

  std::pair<int, int> place (0, 0);
  std::pair<int, int> anotherplace (0, 0);
  //std::pair<int, int> whfirstimage (576, 1024);
  //std::pair<int, int> whsecondimage (108, 140);
  Image* images1 = new Image(game.renderer, "../assets/images/scott.png", place, true, std::make_pair(108, 140), std::make_pair(108, 140), anotherplace);
  Image* images2 = new Image(game.renderer, "../assets/images/menu_screen.jpg", place, true, std::make_pair(1024, 576), std::make_pair(1024, 576), anotherplace);
  GameObject* boy = new GameObject("boy", place);
  GameObject* background = new GameObject("background", anotherplace);
  boy->add_component("image", images1);
  background->add_component("image", images2);


  Level* level1 = new Level();
  // menu = main_menu(game);

  level1->add_object("boy", boy);
  level1->add_object("background", background);
  level1->activate_game_object("boy");level1->activate_game_object("background");
  game.add_scene("first level", level1);

  Level* menu;
  menu = main_menu(game);

  game.change_scene(level1);
  game.run();

  return 0;
}
