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

class TextTexture{
  public:
    TextTexture( MenuItem *item, SDL_Texture*, SDL_Texture*, SDL_Rect* );
    TextTexture( TextTypeItem *, SDL_Texture *, SDL_Rect * );
    ~TextTexture();
    MenuItem *item;
    SDL_Texture *texture_green;
    SDL_Texture *texture_white;
    SDL_Rect *quad;
};

class GameTexture{
  public:
    GameTexture( GameItem *item, SDL_Texture*, SDL_Rect* );
    ~GameTexture();
    GameItem *item;
    SDL_Texture *texture_green;
    SDL_Texture *texture_white;
    SDL_Rect *quad;
    void setX(int);
    void setY(int);
};
class GameState;
class Engine{
  public:
    Engine();
    ~Engine();
    void start();
    void activateState(std::string);
    void addState(GameState*, std::string);
    void allocateMenuTextResource(MenuItem*);
    void updateTypeTexture(TextTypeItem*);
    void allocateGameItemTexture(GameItem*);
    void updateGameTextures();
    void renderText(MenuItem*, bool);
    void renderTextTypeItem();
    void renderGameItems();
    void stop();
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
    std::vector<TextTexture*> *menutextures;
    std::vector<GameTexture*> *gametextures;
    TextTexture *typetexture;
    GameState *gamestate_active;

};



#endif
