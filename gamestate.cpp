#include "gamestate.h"
#include "engine.h"
#include <vector>
#include <SDL.h>

GameState::GameState(){
  ;
}

GameState::~GameState(){
  ;
}
void GameState::setEngine(Engine *e){
  this->e = e;
}

void GameState::keydown(SDL_Keycode keycode){
  ;
}

void GameState::update(double){
  ;
}

void GameState::render(){
;
}



GameState_Menu::GameState_Menu(){
  items = new std::vector<MenuItem*>;
  index = 0;
}

GameState_Menu::~GameState_Menu(){
  ;
}



void GameState_Menu::keydown(SDL_Keycode keycode){

  if(keycode==SDLK_s && index+1<items->size()) index++;
  if(keycode==SDLK_w && index>0) index--;
  if(keycode==SDLK_RETURN){
    if(index==1)e->stop();
    else if(index==0)e->activateState("game");

  }

}

void GameState_Menu::update(double){
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

GameState_Game::GameState_Game(){
  items = new std::vector<GameItem*>;
  typeitem = new TextTypeItem(50, 50, "a");
}

void GameState_Game::addFlyingItem(GameItem *item){
  e->allocateGameItemTexture(item);
  items->push_back(item);
}

#include <stdio.h>
void GameState_Game::keydown(SDL_Keycode keycode){

  if(keycode==SDLK_ESCAPE){
    e->activateState("menu");
  }
  if(keycode > 96 && keycode < 123 )
  {
    typeitem->addChar(keycode);
  }
  if(keycode==SDLK_BACKSPACE){
    typeitem->removeChar();
  }
  if(keycode==SDLK_RETURN){
    for(auto &item : *items){
      //compare entered text to all flying texts until mats is found
      if(typeitem->text.compare(item->text)==0){
        printf("mats!!!!!!!!!\n");
      }
      else printf("%s does not mats to %s\n", typeitem->text.c_str(), item->text.c_str());

    }
    typeitem->clearText();
  }
}

void GameState_Game::update(double dt){

  for(auto &item: *items){
    item->x = item->x + item->vx * dt;
    printf("%f", dt);
    e->updateGameTextures();
    printf("%f\n", item->x);
  }

}

void GameState_Game::render(){
  e->updateTypeTexture(typeitem);
  e->renderTextTypeItem();
  e->renderGameItems();
}
