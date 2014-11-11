#include "engine.h"



Engine::Engine(){
  SDL_Init( SDL_INIT_VIDEO );
  TTF_Init();
  SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" );
  wroom = false;

  //states = std::map<std::string, GameState*>;
  menutextures = new std::vector<TextTexture*>;

  gFont = TTF_OpenFont( "ARCADE_N.ttf", 28 );
  gWindow = SDL_CreateWindow( "typerbawz", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
  gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED  );

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

void Engine::addState(GameState *state, std::string statename){
  states[statename] = state;
}

void Engine::allocateTextResource(MenuItem *item){

  SDL_Texture *texture_white = NULL;
  SDL_Texture *texture_green = NULL;
  SDL_Surface *textSurface = NULL;
  SDL_Rect renderQuad;

  textSurface = TTF_RenderText_Solid( gFont, item->text.c_str(), { 255, 255, 255 } );
  texture_white = SDL_CreateTextureFromSurface( gRenderer, textSurface );
  textSurface = TTF_RenderText_Solid( gFont, item->text.c_str(), { 0, 255, 0 } );
  texture_green = SDL_CreateTextureFromSurface( gRenderer, textSurface );
  int fontsize = TTF_FontHeight(gFont);
  renderQuad = { (int)item->x, (int)item->y, fontsize * (int)item->text.length(), fontsize};
  menutextures->push_back(new TextTexture(item, texture_green, texture_white, &renderQuad));
};

void Engine::renderText(MenuItem* item, bool is_active){
  for(auto &texture:*menutextures){
    if(is_active){
      SDL_RenderCopyEx( gRenderer, texture->texture_green, NULL, texture->quad, 0.0, NULL, SDL_FLIP_NONE );
    }
    else{
      SDL_RenderCopyEx( gRenderer, texture->texture_white, NULL, texture->quad, 0.0, NULL, SDL_FLIP_NONE );
    }
  }
}

void Engine::start(){
  wroom = true;
  gamestate_active = states["menu"];
  this->loop();
}

void Engine::loop(){
  while(wroom){
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

    //Render texture
    gamestate_active->render();

    //Update screen
    SDL_RenderPresent( gRenderer );

  }
}

TextTexture::TextTexture( MenuItem *item, SDL_Texture *texture_green, SDL_Texture *texture_white, SDL_Rect *quad ){
  this->item = item;
  this->texture_green = texture_green;
  this->texture_white = texture_white;
  this->quad = quad;
}

TextTexture::~TextTexture(){
  ;
}



