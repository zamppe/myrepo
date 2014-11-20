#ifndef MENUITEM_H
#define MENUITEM_H

#include <SDL.h>
#include <SDL2/SDL_ttf.h>
#include <string>

class Texture{
  public:
    Texture();
    ~Texture();
    void make(int x, int y, std::string *text, SDL_Renderer *renderer, TTF_Font *font, SDL_Color color);
    void update(int x, int y, std::string *text, TTF_Font *font, SDL_Color color);
    void render();
    void setX(int);
    void setY(int);
    SDL_Rect* getRect();
  private:
    SDL_Renderer *renderer;
    SDL_Texture *texture;
    SDL_Rect *quad;
};



class MenuItem{
  public:
    MenuItem( double, double, std::string );
    ~MenuItem();
    void render(bool is_active);
    double x;
    double y;
    std::string text;
    Texture *texture_white;
    Texture *texture_green;
};


class TextTypeItem{
  public:
    TextTypeItem( double, double, std::string );
    ~TextTypeItem( );
    void render();
    void addChar(SDL_Keycode c);
    void removeChar();
    void clearText();
    std::string text;
    double x;
    double y;
    Texture *texture_white;

};



class GameItem{
  public:
    GameItem( double, double, double, double, std::string );
    ~GameItem( );
    void render();
    void update(double dt);
    void setX(double);
    std::string text;
    double x;
    double y;
    double vx;
    double vy;
    Texture *texture_white;
};

#endif
