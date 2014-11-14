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
  mainmenu->addMenuItem(item);
  item = new MenuItem(20, 50, "quit");
  mainmenu->addMenuItem(item);

  game->addTextTypeItem();
  game->addGameItem(new GameItem(700, 200, -10, 0, "testing"));
  game->addGameItem(new GameItem(700, 300, -100, 0, "fastfuckface"));
  game->addGameItem(new GameItem(700, 400, -10, 0, "good luck 8D"));

  engine->addState(mainmenu, "menu");
  engine->addState(game, "game");
  engine->start();
  delete engine;
  return 0;
}



