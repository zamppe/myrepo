#include "menuitem.h"

MenuItem::MenuItem( double x, double y, std::string text ){
  this->x = x;
  this->y = y;
  this->text = text;
}

MenuItem::~MenuItem(){
  ;
}

TextTypeItem::TextTypeItem(double x, double y, std::string text){
  this->x = x;
  this->y = y;
  this->text = text;
}

TextTypeItem::~TextTypeItem(){
;
}
void TextTypeItem::addChar(SDL_Keycode c){
  this->text.push_back(c);
}

void TextTypeItem::removeChar(){
  if(!this->text.empty()) this->text.pop_back();
}

void TextTypeItem::clearText(){
  this->text.erase(this->text.begin(), this->text.end());
}

GameItem::GameItem( double x, double y, double vx, double vy, std::string text ){
  this->x = x;
  this->y = y;
  this->vx = vx;
  this->vy = vy;
  this->text = text;
}

GameItem::~GameItem(){
  ;
}
