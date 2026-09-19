#include "game.h"
#include "sfmlUI.h"
#include "snake.h"
#include <iostream>

#define MAP_SIZE_X 20
#define MAP_SIZE_Y 20
#define TILE_SIZE 30

int main() {

  Game game(MAP_SIZE_X, MAP_SIZE_Y);
  SfmlUI ui(MAP_SIZE_X, MAP_SIZE_Y, TILE_SIZE);

  while (ui.isOpen()) {
    try {
      Direction dir = ui.getInput();

      if (dir != Direction::None) {
        game.processInput(dir);
      }
      game.update();

      if (game.isGameOver()) {
        break;
      }

      ui.drawFrame(game);
    } catch (const std::exception &error) {
      std::cerr << "Error running the game: " << error.what() << std::endl;
      return 1;
    }
  }
  return 0;
}
