#ifndef GAMESTATE_H
#define GAMESTATE_H
#include <vector>
#include <SDL.h>

#include "menuitem.h"


class Engine;

class GameState{
public:
  GameState();
  ~GameState();
  virtual void keydown(SDL_Keycode keycode);
  virtual void update(double);
  virtual void render();
  void setEngine(Engine *e);
  Engine *e;
};


class GameState_Menu : public GameState{
  public:
    GameState_Menu();
    ~GameState_Menu();
    void keydown(SDL_Keycode keycode);
    void update(double);
    void addMenuItem(MenuItem*);
    void render();
  private:
    std::vector<MenuItem*> *items;
    MenuItem *active_item;
    unsigned int index;
};

class GameState_Game : public GameState{
  public:
    GameState_Game();
    ~GameState_Game();
    void addGameItem(GameItem*);
    void addTextTypeItem();
    void keydown(SDL_Keycode keycode);
    void update(double);
    void render();
  private:
    TextTypeItem *typeitem;
    std::vector<GameItem*> *items;

};

#endif
