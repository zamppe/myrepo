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


void GameState_Menu::addMenuItem(MenuItem *item){
  item->texture_white->make((int)item->x, (int)item->y, &item->text, e->getRenderer(), e->getFont(), {255, 255, 255});
  item->texture_green->make((int)item->x, (int)item->y, &item->text, e->getRenderer(), e->getFont(), {255, 0, 0});

  items->push_back(item);

}
void GameState_Menu::render(){
  unsigned int i = 0;
  for(auto &item:*items){
    item->render(i == index);
    i++;
  }
}

GameState_Game::GameState_Game(){
  items = new std::vector<GameItem*>;
}

void GameState_Game::addGameItem(GameItem *item){
  item->texture_white->make((int)item->x, (int)item->y, &item->text, e->getRenderer(), e->getFont(), {255, 255, 255});
  items->push_back(item);
}

void GameState_Game::addTextTypeItem(){
  typeitem = new TextTypeItem(50, 50, "a");
}

void GameState_Game::keydown(SDL_Keycode keycode){

  if(keycode==SDLK_ESCAPE){
    e->activateState("menu");
  }
  if(keycode >= 'a' && keycode <= 'z' )
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
        ;//mats
      }

    }
    typeitem->clearText();
  }
}

void GameState_Game::update(double dt){
  typeitem->texture_white->make((int)typeitem->x, (int)typeitem->y, &typeitem->text, e->getRenderer(), e->getFont(), {255, 255, 255});

  for(auto &item: *items){
    item->x = item->x + item->vx * dt;
    item->texture_white->setX((int)item->x);
    item->texture_white->setY((int)item->y);
  }

}

void GameState_Game::render(){
  typeitem->render();
  for(auto &item: *items){
    item->render();
  }
}
