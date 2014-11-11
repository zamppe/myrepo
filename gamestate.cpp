#include "gamestate.h"
#include "engine.h"
#include <SDL.h>

GameState::GameState(Engine *e){
  this->e = e;
}

GameState::~GameState(){
  ;
}

void GameState::keydown(SDL_Keycode keycode){
  ;
}

void GameState::update(){
  ;
}

void GameState::render(){
;
}



GameState_Menu::GameState_Menu(){
  items = new std::vector<MenuItem*>;
  index = 0;
  this->buildMenu();
}

GameState_Menu::~GameState_Menu(){
  ;
}

void GameState_Menu::buildMenu(){
  MenuItem *item;
  item = new MenuItem(20, 20, "play");
  this->addItem(item);
  e->allocateTextResource(item);
  item = new MenuItem(20, 50, "quit"); // is this oke or do i fuk up the previous item somehow
  this->addItem(item);
  e->allocateTextResource(item);
}

void GameState_Menu::keydown(SDL_Keycode keycode){

  if(keycode==SDLK_s && index+1<items->size()) index++;
  if(keycode==SDLK_w && index>0) index--;
  //if(keycode==SDLK_ENTER && index==1) index--;

}

void GameState_Menu::update(){
  ;
}


void GameState_Menu::addItem(MenuItem *item){
  items->push_back(item);

}

void GameState_Menu::render(){
  unsigned int i = 0;
  for(auto &item:*items){
      e->renderText(item, i == index);
      i++;
  }
}
