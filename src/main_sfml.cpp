#include "game.h"
#include "sfmlUI.h"
#include "snake.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#define MAP_SIZE_X 20
#define MAP_SIZE_Y 20
#define TILE_SIZE 30

int main() {

  Game game(MAP_SIZE_X, MAP_SIZE_Y);
  SfmlUI ui(MAP_SIZE_X, MAP_SIZE_Y, TILE_SIZE);

  while (ui.isOpen()) {

    Direction dir = ui.getInput();

    if (dir != Direction::None) {
      game.processInput(dir);
    }
    game.update();

    if (game.isGameOver()) {
      break;
    }

    ui.drawFrame(game);
  }

  return 0;
}
