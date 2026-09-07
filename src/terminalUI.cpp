#include "terminalUI.h"
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
