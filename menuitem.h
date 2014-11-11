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
#endif
