#ifndef TERMINALUI_H
#define TERMINALUI_H

#include "game.h"
#include "snake.h"
#include <ncurses.h>

class TerminalUI {

public:
  TerminalUI();
  ~TerminalUI();

  void drawFrame(const Game &game) const;

  Direction getInput() const;
};

#endif // !TERMINALUI_H
