#ifndef ENGINE_H
#define ENGINE_H

#include <SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <string>
#include <map>
#include <vector>
#include <stdio.h>

#include "menuitem.h"
#include "gamestate.h"


class GameState;
class Engine{
  public:
    Engine();
    ~Engine();
    void start();
    void activateState(std::string);
    void addState(GameState*, std::string);
    void stop();
    SDL_Renderer* getRenderer();
    TTF_Font* getFont();
  private:
    void loop();
    bool wroom;

    const int SCREEN_WIDTH = 1600;
    const int SCREEN_HEIGHT = 600;

    SDL_Window *gWindow;
    SDL_Renderer *gRenderer;
    TTF_Font *gFont;

    SDL_Event e;
    Uint32 old_time, current_time;
    std::map <std::string, GameState*> states;
    GameState *gamestate_active;
};



#endif
