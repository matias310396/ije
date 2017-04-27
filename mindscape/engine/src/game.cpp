#include "../include/game.hpp"

using namespace engine;

Game* Game::instance = NULL;

void throw_error(const char* function){
  printf("Something's wrong in %s\n", function);
  exit(-1);
}

Game& Game::get_instance(){
  if(!instance){
    instance = new Game();
  }
  return *instance;
}

void Game::game_init(){
  int img_flags = IMG_INIT_PNG;

  if(SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO) < 0){
    throw_error("SDL_Init");
  }
  if(!(IMG_Init(IMG_INIT_PNG) & img_flags)){
    throw_error("IMG_Init");
  }

  if(TTF_Init() == -1)
  {
    throw_error("TTF_Init");
  }

  if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 512 ) < 0 )
  {
    printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
  }

  window = SDL_CreateWindow(game_name.c_str(),SDL_WINDOWPOS_UNDEFINED,
                            SDL_WINDOWPOS_UNDEFINED,window_dimensions.first,window_dimensions.second,SDL_WINDOW_SHOWN);
  if(!window){
    throw_error("SDL_CreateWindow");
  }
  renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
  if(!renderer){
    throw_error("SDL_CreateRenderer");
  }
}

bool Game::load_media(){
  bool success_on_load = true;
  std::string path = "../assets/images/image2.jpg";
  std::string text_path = "../assets/Fonts/FFF_Tusj.ttf";
  //std::string audio_path = "../assets/Sound/loop1-1.mp3";

  if(!image_1->load(path.c_str())){
    printf("Failed to load media at %s\n",path.c_str());
    success_on_load = false;
  }

  if(!text_1->load(text_path)){
     printf("Failed to load media at %s\n",text_path.c_str());
     success_on_load = false;
  }

  if(!loop_song->load()){
    printf("Failed to load media the loop song\n");
    success_on_load = false;
  }

  return success_on_load;
}

void Game::close(){
  //TODO add steps to deallocate all rendered textures
  image_1->free();
  text_1->free();
  loop_song->free();

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  renderer = NULL;
  window = NULL;

  IMG_Quit();
  SDL_Quit();
}

void Game::run(){
  game_init();
  image_1 = new Image(renderer);
  std::string path_font = "../assets/Fonts/FFF_Tusj.ttf";
  text_1 = new Text("MindScape", path_font, 120,renderer);

  loop_song = new Audio("../assets/Sound/loop1-1.mp3","music");

  if(load_media()){
    bool quit_event = false;

    SDL_Event e;
    loop_song->play();
    while(!quit_event){
      while(SDL_PollEvent( &e ) != 0){
        if(e.type == SDL_QUIT){
          quit_event = true;
        }
      }
      SDL_SetRenderDrawColor(renderer,0xFF, 0xFF, 0xFF, 0xFF);
      SDL_RenderClear(renderer);

      image_1->render(0,0);
      text_1->draw(350,050);

      SDL_RenderPresent(renderer);
    }
  }
  else{
    printf("Medias could not be loaded\n");
  }
  close();
}

void Game::set_information(std::string name,std::pair<int,int> dimensions){
  game_name = name;
  window_dimensions = dimensions;
}
