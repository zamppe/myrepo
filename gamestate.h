#ifndef GAMESTATE_H
#define GAMESTATE_H
#include <vector>
#include <SDL.h>

#include "menuitem.h"
#include "engine.h"

class Engine;

class GameState{
public:
  GameState(Engine*);
  virtual ~GameState();
  virtual void keydown(SDL_Keycode keycode);
  virtual void update();
  virtual void render();
  Engine *e;
};


class GameState_Menu : public GameState{
  public:
    GameState_Menu();
    ~GameState_Menu();
    void keydown(SDL_Keycode keycode);
    void update();
    void addItem(MenuItem*);
    void render();
    void buildMenu();
  private:
    std::vector<MenuItem*> *items;
    MenuItem *active_item;
    unsigned int index;
    Engine *e;
};

class GameState_Game : public GameState{
  public:
    GameState_Game();
    ~GameState_Game();
    void keydown(SDL_Keycode keycode);
    void update();

};

#endif
