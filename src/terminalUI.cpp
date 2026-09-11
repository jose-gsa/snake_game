#include "terminalUI.h"
#include "snake.h"
#include <ncurses.h>
#include <vector>

TerminalUI::TerminalUI() {

  initscr();
  cbreak();
  noecho();

  keypad(stdscr, true);

  curs_set(0);

  nodelay(stdscr, true);
}

TerminalUI::~TerminalUI() { endwin(); }

Direction TerminalUI::getInput() const {

  int input = getch();

  switch (input) {
  case (KEY_UP):
    return Direction::Up;
  case (KEY_LEFT):
    return Direction::Left;
  case (KEY_RIGHT):
    return Direction::Right;
  case (KEY_DOWN):
    return Direction::Down;
  default:
    return Direction::None;
  }
}

void TerminalUI::drawFrame(const Game &game) const {

  erase();

  const auto &snake = game.getSnakePositions();
  const auto map = game.mapCoordinates();

  // Draw the map
  for (int i = 0; i <= map.y; i++) {
    for (int k = 0; k <= map.x; k++) {

      if ((i == 0 || i == map.y) && (k == 0 || k == map.y)) {
        mvaddch(i, k, '+');
      } else if (i == 0 || i == map.y) {
        mvaddch(i, k, '-');
      } else if (k == 0 || k == map.x) {
        mvaddch(i, k, '|');
      }
    }
  }

  // Draw Snake
  mvaddch(snake[0].y, snake[0].x, 'O'); // Head

  // Body
  for (size_t i = 1; i < snake.size(); i++) {

    mvaddch(snake[i].y, snake[i].x, 'o');
  }

  // Draw Apple
  mvaddch(game.applePosition().y, game.applePosition().x, '@');

  refresh();
}
