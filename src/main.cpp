#include "game.h"
#include "snake.h"
#include "terminalUI.h"
#include <chrono>
#include <thread>

int main() {

  Game game(30, 30);
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
