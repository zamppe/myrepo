#ifndef ENGINE_H
#define ENGINE_H

#include <SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <string>
#include <map>
#include <stdio.h>

#include "menuitem.h"
#include "gamestate.h"

class TextTexture{
  public:
    TextTexture( MenuItem *item, SDL_Texture*, SDL_Texture*, SDL_Rect* );
    ~TextTexture();
    MenuItem *item;
    SDL_Texture *texture_green;
    SDL_Texture *texture_white;
    SDL_Rect *quad;
};
class GameState;
class Engine{
  public:
    Engine();
    ~Engine();
    void start();
    void activateState(std::string);
    void addState(GameState*, std::string);
    void allocateTextResource(MenuItem*);
    void renderText(MenuItem*, bool);
  private:
    void loop();
    bool wroom;

    const int SCREEN_WIDTH = 1600;
    const int SCREEN_HEIGHT = 600;

    SDL_Window *gWindow;
    SDL_Renderer *gRenderer;
    TTF_Font *gFont;

    SDL_Event e;

    std::map <std::string, GameState*> states;
    std::vector<TextTexture*> *menutextures;
    GameState *gamestate_active;

};



#endif
