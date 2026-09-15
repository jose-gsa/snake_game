#include "game.h"
#include "snake.h"
#include "terminalUI.h"
#include <chrono>
#include <thread>

#define MAP_SIZE_X 30
#define MAP_SIZE_Y 30

int main() {

  Game game(MAP_SIZE_X, MAP_SIZE_Y);
  TerminalUI ui;

  while (!game.isGameOver()) {

    Direction dir = ui.getInput();

    if (dir != Direction::None) {
      game.processInput(dir);
    }

    game.update();
    ui.drawFrame(game);

    std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }

  return 0;
}
