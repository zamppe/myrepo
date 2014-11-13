#include "engine.h"
#include "gamestate.h"



int main(int argc, char *args[]){
  Engine *engine = new Engine();
  GameState_Menu *mainmenu = new GameState_Menu();
  mainmenu->setEngine(engine);
  GameState_Game *game = new GameState_Game();
  game->setEngine(engine);

  MenuItem *item;
  item = new MenuItem(20, 20, "play");
  mainmenu->addItem(item);
  engine->allocateMenuTextResource(item);
  item = new MenuItem(20, 50, "quit");
  mainmenu->addItem(item);
  engine->allocateMenuTextResource(item);

  game->addFlyingItem(new GameItem(700, 200, -10, 0, "testing"));
  game->addFlyingItem(new GameItem(700, 300, -100, 0, "fastfuckface"));
  game->addFlyingItem(new GameItem(700, 400, -10, 0, "good luck 8D"));

  engine->addState(mainmenu, "menu");
  engine->addState(game, "game");
  engine->start();
  delete engine;
  return 0;
}



