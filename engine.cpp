#include "engine.h"



Engine::Engine(){
  SDL_Init( SDL_INIT_VIDEO );
  TTF_Init();
  SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" );
  wroom = false;

  gFont = TTF_OpenFont( "ARCADE_N.ttf", 28 );
  gWindow = SDL_CreateWindow( "typerbawz", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
  gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED  );

  old_time = 0;
  current_time = 0;
}


Engine::~Engine(){
  TTF_CloseFont( gFont );
	gFont = NULL;
  SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
  gWindow = NULL;
	gRenderer = NULL;
  TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}

void Engine::activateState(std::string statename){
  gamestate_active = states[statename];
}

SDL_Renderer* Engine::getRenderer(){
  return gRenderer;
}

TTF_Font* Engine::getFont(){
  return gFont;
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

    gamestate_active->update((current_time - old_time) / 1000.0f);

    //Render texture
    gamestate_active->render();

    //Update screen
    SDL_RenderPresent( gRenderer );

  }
}



