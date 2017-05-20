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

     Level* main_menu = new Level();

      Image* background = new Image(game.renderer, "../assets/images/menu_screen.jpg", std::make_pair(0,0), true, std::make_pair(1024,576), std::make_pair(1024,576), std::make_pair(0,0));
      GameObject* menu_background = new GameObject("menu_background", std::make_pair(0,0));
      menu_background->add_component("menu_background", background);

      Text* title = new Text("MindScape", "../assets/fonts/FFF_Tusj.ttf", 90, game.renderer);
      GameObject* game_title = new GameObject("game_title", std::make_pair(280, 30));
      game_title->add_component("game_title", title);

      Text* text_start = new Text("Start", "../assets/fonts/FFF_Tusj.ttf", 35, game.renderer);
      GameObject* start = new GameObject("start", std::make_pair(450, 275));
      start->add_component("start", text_start);

      Text* text_instructions= new Text("Instructions", "../assets/fonts/FFF_Tusj.ttf", 35, game.renderer);
      GameObject* instructions = new GameObject("instructions", std::make_pair(450, 310));
      instructions->add_component("instructions", text_instructions);

      Text* text_credits= new Text("Credits", "../assets/fonts/FFF_Tusj.ttf", 35, game.renderer);
      GameObject* credits = new GameObject("credits", std::make_pair(450, 345));
      credits->add_component("credits", text_credits);

      Text* text_exit = new Text("Exit", "../assets/fonts/FFF_Tusj.ttf", 35, game.renderer);
      GameObject* exit = new GameObject("exit", std::make_pair(450, 380));
      exit ->add_component("exit", text_exit);

      Text* sel = new Text(">", "../assets/fonts/FFF_Tusj.ttf", 35, game.renderer);
      GameObject* select = new GameObject("select", std::make_pair(425, 275));
      select->add_component("select", sel);

      Audio* music = new Audio("../assets/audios/loop1-1.mp3", Audio::audio_type::music);
      GameObject * menu_loop =  new GameObject("menu_loop", std::make_pair(0,0));
      menu_loop->add_component("menu_loop", music);


      main_menu->add_object("game_title", game_title);
      main_menu->activate_game_object("game_title");

      main_menu->add_object("select", select);
      main_menu->activate_game_object("select");

      main_menu->add_object("start", start);
      main_menu->activate_game_object("start");

      main_menu->add_object("instructions", instructions);
      main_menu->activate_game_object("instructions");

      main_menu->add_object("credits", credits);
      main_menu->activate_game_object("credits");

      main_menu->add_object("exit", exit);
      main_menu->activate_game_object("exit");

      main_menu->add_object("menu_background", menu_background);
      main_menu->activate_game_object("menu_background");

      main_menu->add_object("menu_loop", menu_loop);
      main_menu->activate_game_object("menu_loop");

       return main_menu;
}

int main(int,char**){
  Game& game = Game::get_instance();
  game.set_information(globals::game_name,globals::window_size);
  game.game_init();

  Level* menu;
  menu = main_menu(game);
  game.add_scene("menu inicial", menu);

  game.change_scene(menu);
  game.run();

  return 0;
}
