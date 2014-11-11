#include "engine.h"
#include "gamestate.h"


int main(int argc, char *args[]){
  Engine *engine = new Engine();
  engine->addState(new GameState_Menu(engine), "menu");
  engine->addState(new GameState_Game(engine), "game");
  engine->start();
  delete engine;
  return 0;
}



