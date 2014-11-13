#ifndef MENUITEM_H
#define MENUITEM_H

#include <SDL.h>
#include <SDL2/SDL_ttf.h>
#include <string>




class MenuItem{
  public:
    MenuItem( double, double, std::string );
    ~MenuItem();
    double x;
    double y;
    std::string text;
};


class TextTypeItem{
  public:
    TextTypeItem( double, double, std::string );
    ~TextTypeItem( );
    void addChar(SDL_Keycode c);
    void removeChar();
    void clearText();
    std::string text;
    double x;
    double y;


};

class GameItem{
  public:
    GameItem( double, double, double, double, std::string );
    ~GameItem( );
    std::string text;
    double x;
    double y;
    double vx;
    double vy;

};

#endif
