#include "gamestate.h"
#include "engine.h"
#include <vector>
#include <algorithm>
#include <SDL.h>
#include "randik.h"

bool rect_rect_collision(SDL_Rect *r1, SDL_Rect *r2){
  if((  r1->x         < (r2->x + r2->w))
  && ((r1->x + r1->w) >  r2->x         )
  && (  r1->y         < (r2->y + r2->h))
  && ((r1->y + r1->h) >  r2->y         ))
  { return true; }
  return false;
}


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

void GameState::reset(){
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

  if((keycode==SDLK_s || keycode == SDLK_DOWN) && index+1<items->size()) index++;
  if((keycode==SDLK_w || keycode == SDLK_UP) && index>0) index--;
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
  level = new Level();
}

void GameState_Game::addGameItem(GameItem *item){
  item->texture_white->make((int)item->x, (int)item->y, &item->text, e->getRenderer(), e->getFont(), {255, 255, 255});
  items->push_back(item);
}
void GameState_Game::removeGameItem(GameItem* item){
  items->erase(std::remove(items->begin(), items->end(), item), items->end());
  delete item;
}

void GameState_Game::addTextTypeItem(int x, int y, std::string text ){
  typeitem = new TextTypeItem(x, y, text);
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
      if(typeitem->text == item->text){
        removeGameItem(item);
      }

    }
    typeitem->clearText();
  }
}
void GameState_Game::update(double dt){
  typeitem->texture_white->make((int)typeitem->x, (int)typeitem->y, &typeitem->text, e->getRenderer(), e->getFont(), {255, 255, 255});

  for(auto &item: *items){
    item->update(dt);
  }

}
#include <stdio.h>
void GameState_Game::reset(){
    SDL_Rect *rekt = e->getRect();
    Randik randik(e->seed);
    printf("%d", randik.getRandomInt(1, 10));
    addGameItem(new GameItem(rekt->w, randik.getRandomInt(0, rekt->h), level->rules->initial_velocity, 0, level->pullRandomWord(e->seed)));
}

void GameState_Game::render(){
  typeitem->render();
  for(auto &item: *items){
    item->render();
    //oke we are out of bounds..
    if(!rect_rect_collision(item->texture_white->getRect(), e->getRect()))
      item->setX(700.0);
  }
}
