#ifndef SFMLUI_H
#define SFMLUI_H

#include "game.h"
#include "snake.h"
#include <SFML/Graphics.hpp>

class SfmlUI {

  sf::RenderWindow window;
  int tileSize;

public:
  SfmlUI(int mapWidth, int mapHeight, int tileSize);

  ~SfmlUI() = default;

  bool isOpen() const;

  Direction getInput();

  void drawFrame(const Game &game);
};

#endif // !SFMLUI_H
