#ifndef ENGINE_H
#define ENGINE_H

#include <SDL.h>
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
    Engine(int w, int h);
    ~Engine();
    void start();
    void activateState(std::string);
    void addState(GameState*, std::string);
    void stop();
    SDL_Renderer* getRenderer();
    TTF_Font* getFont();
    SDL_Rect* getRect();
    time_t seed;
  private:
    void loop();
    bool wroom;

    SDL_Rect *window_rect;
    SDL_Window *gWindow;
    SDL_Renderer *gRenderer;
    TTF_Font *gFont;

    SDL_Event e;
    Uint32 old_time, current_time;
    double DT;
    double accumulator;
    std::map <std::string, GameState*> states;
    GameState *gamestate_active;
};



#endif
