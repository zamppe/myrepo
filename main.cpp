#include "engine.h"
#include "gamestate.h"



int main(int argc, char *args[]){
  Engine *engine = new Engine(1440, 900);
  GameState_Menu *mainmenu = new GameState_Menu();
  mainmenu->setEngine(engine);
  GameState_Game *game = new GameState_Game();
  game->setEngine(engine);

  MenuItem *item;
  item = new MenuItem(20, 20, "play");
  mainmenu->addMenuItem(item);
  item = new MenuItem(20, 50, "quit");
  mainmenu->addMenuItem(item);

  game->addTextTypeItem(10, 10);

  game->level->loadFromFile("lefel1.txt");


  engine->addState(mainmenu, "menu");
  engine->addState(game, "game");
  engine->start();
  delete engine;
  return 0;
}



