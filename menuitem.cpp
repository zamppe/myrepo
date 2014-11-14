#include "menuitem.h"


Texture::Texture(){
  renderer = NULL;
  texture = NULL;
  quad = new SDL_Rect();
}

Texture::~Texture(){
  SDL_DestroyTexture(texture);
}

void Texture::make(int x, int y, std::string *text, SDL_Renderer *renderer, TTF_Font *font, SDL_Color color){
  if(texture != NULL) SDL_DestroyTexture(texture);
  if(this->renderer == NULL) this->renderer = renderer;
  SDL_Surface *textSurface = NULL;
  textSurface = TTF_RenderText_Solid( font, text->c_str(), color );
  texture = SDL_CreateTextureFromSurface( this->renderer, textSurface );
  SDL_FreeSurface(textSurface);

  int fontsize = TTF_FontHeight(font);
  *quad =  { x, y, fontsize * (int)text->length(), fontsize};
}


void Texture::setX(int x){
  quad->x = x;
}

void Texture::setY(int y){
  quad->y = y;
}

void Texture::render(){
  SDL_RenderCopyEx( renderer, texture, NULL, this->quad, 0.0, NULL, SDL_FLIP_NONE );
}

MenuItem::MenuItem( double x, double y, std::string text ){
  this->x = x;
  this->y = y;
  this->text = text;
  texture_white = new Texture();
  texture_green = new Texture();
}

MenuItem::~MenuItem(){
  ;
}

void MenuItem::render(bool is_active){
  if(is_active) texture_green->render();
  else texture_white->render();
}

TextTypeItem::TextTypeItem(double x, double y, std::string text){
  this->x = x;
  this->y = y;
  this->text = text;
  texture_white = new Texture();
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

void TextTypeItem::render(){
  texture_white->render();
}

GameItem::GameItem( double x, double y, double vx, double vy, std::string text ){
  this->x = x;
  this->y = y;
  this->vx = vx;
  this->vy = vy;
  this->text = text;
  texture_white = new Texture();
}

GameItem::~GameItem(){
  ;
}

void GameItem::render(){
  texture_white->render();
}
