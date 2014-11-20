#include "engine.h"
#include <time.h>


Engine::Engine(int w, int h){
  SDL_Init( SDL_INIT_VIDEO );
  TTF_Init();
  SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" );
  wroom = false;

  window_rect = new SDL_Rect();
  *window_rect = {0, 0, w, h};
  gFont = TTF_OpenFont( "ARCADE_N.ttf", 28 );
  gWindow = SDL_CreateWindow( "typerbawz", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w, h,  SDL_WINDOW_SHOWN );
  //gWindow = SDL_CreateWindow( "typerbawz", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w, h, SDL_WINDOW_FULLSCREEN  );
  gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC   );


  old_time = 0;
  current_time = 0;
  accumulator = 0.0f;
  DT = 1/60.0f;

  seed = time(NULL);
}


Engine::~Engine(){
  TTF_CloseFont( gFont );
	gFont = NULL;
  SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
  gWindow = NULL;
	gRenderer = NULL;
  TTF_Quit();
	SDL_Quit();
}

void Engine::activateState(std::string statename){
  gamestate_active = states[statename];
  if(statename == "game") gamestate_active->reset();
}

SDL_Renderer* Engine::getRenderer(){
  return gRenderer;
}

TTF_Font* Engine::getFont(){
  return gFont;
}

SDL_Rect* Engine::getRect(){
  return window_rect;
}

void Engine::addState(GameState *state, std::string statename){
  states[statename] = state;
}

void Engine::start(){
  wroom = true;
  gamestate_active = states["menu"];
  this->loop();
}

void Engine::stop(){
  wroom = false; //:(
}

void Engine::loop(){
  while(wroom){
    old_time = current_time;
    current_time = SDL_GetTicks();
    accumulator += (current_time - old_time) / 1000.0f;
    while( SDL_PollEvent( &e ) != 0 ){
      if( e.type == SDL_QUIT ){
        wroom = false;
      }
      if( e.type == SDL_KEYDOWN){
          gamestate_active->keydown(e.key.keysym.sym);

      }
    }

    SDL_SetRenderDrawColor( gRenderer, 0, 0, 0, 0xFF );
    SDL_RenderClear( gRenderer );

    for(;accumulator >= DT; accumulator-=DT){
      gamestate_active->update(DT);
    }

    //Render texture
    gamestate_active->render();
    //Update screen
    SDL_RenderPresent( gRenderer );

  }
}



