#include "terminalUI.h"
#include "snake.h"
#include <ncurses.h>

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
