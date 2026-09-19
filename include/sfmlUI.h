#ifndef SFMLUI_H
#define SFMLUI_H

#include "game.h"
#include "snake.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

class SfmlUI {

  sf::RenderWindow window;
  int tileSize;

  sf::Texture textureApple;
  sf::Texture textureSnakeHead;
  sf::Texture textureSnakeBody;
  sf::Texture textureSnakeTurn;
  sf::Texture textureSnakeTail;
  sf::Texture textureGrassLight;
  sf::Texture textureGrassDark;

  sf::Sprite spriteApple;
  sf::Sprite spriteSnakeHead;
  sf::Sprite spriteSnakeBody;
  sf::Sprite spriteSnakeTurn;
  sf::Sprite spriteSnakeTail;
  sf::Sprite spriteGrassLight;
  sf::Sprite spriteGrassDark;

public:
  SfmlUI(int mapWidth, int mapHeight, int tileSize);

  ~SfmlUI() = default;

  bool isOpen() const;

  Direction getInput();

  void drawFrame(const Game &game);
};

#endif // !SFMLUI_H
