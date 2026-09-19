#include "sfmlUI.h"
#include "snake.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <stdexcept>

SfmlUI::SfmlUI(int mapWidth, int mapHeight, int tileSize)
    : window(sf::VideoMode({(unsigned int)(mapWidth * tileSize),
                            (unsigned int)(mapHeight * tileSize)}),
             "Snake Game"),
      tileSize(tileSize), spriteApple(textureApple),
      spriteSnakeHead(textureSnakeHead), spriteSnakeBody(textureSnakeBody),
      spriteSnakeTurn(textureSnakeTurn), spriteSnakeTail(textureSnakeTail),
      spriteGrassLight(textureGrassLight), spriteGrassDark(textureGrassDark) {

  window.setFramerateLimit(10);

  if (!textureApple.loadFromFile("assets/apple.png")) {
    throw std::runtime_error("Could not load assets/apple.png");
  }
  textureApple.setSmooth(false);
  spriteApple.setTexture(textureApple, true);

  // All assets are 16x16
  float scaleX = (float)tileSize / textureApple.getSize().x;
  float scaleY = (float)tileSize / textureApple.getSize().y;

  spriteApple.setScale({scaleX, scaleY});

  if (!textureSnakeHead.loadFromFile("assets/head.png")) {
    throw std::runtime_error("Could not load assets/head.png");
  }
  textureSnakeHead.setSmooth(false);
  spriteSnakeHead.setTexture(textureSnakeHead, true);
  spriteSnakeHead.setScale({scaleX, scaleY});

  if (!textureSnakeBody.loadFromFile("assets/body.png")) {
    throw std::runtime_error("Could not load assets/body.png");
  }
  textureSnakeBody.setSmooth(false);
  spriteSnakeBody.setTexture(textureSnakeBody, true);
  spriteSnakeBody.setScale({scaleX, scaleY});

  if (!textureSnakeTail.loadFromFile("assets/tail.png")) {
    throw std::runtime_error("Could not load assets/tail.png");
  }
  textureSnakeTail.setSmooth(false);
  spriteSnakeTail.setTexture(textureSnakeTail, true);
  spriteSnakeTail.setScale({scaleX, scaleY});

  if (!textureSnakeTurn.loadFromFile("assets/turn.png")) {
    throw std::runtime_error("Could not load assets/turn.png");
  }
  textureSnakeTurn.setSmooth(false);
  spriteSnakeTurn.setTexture(textureSnakeTurn, true);
  spriteSnakeTurn.setScale({scaleX, scaleY});

  if (!textureGrassLight.loadFromFile("assets/grass2.png")) {
    throw std::runtime_error("Could not load assets/grass2.png");
  }
  textureGrassLight.setSmooth(false);
  spriteGrassLight.setTexture(textureGrassLight, true);
  spriteGrassLight.setScale({scaleX, scaleY});

  if (!textureGrassDark.loadFromFile("assets/grass1.png")) {
    throw std::runtime_error("Could not load assets/grass1.png");
  }
  textureGrassDark.setSmooth(false);
  spriteGrassDark.setTexture(textureGrassDark, true);
  spriteGrassDark.setScale({scaleX, scaleY});
}

bool SfmlUI::isOpen() const { return this->window.isOpen(); }

Direction SfmlUI::getInput() {

  while (const std::optional<sf::Event> event = this->window.pollEvent()) {
    if (event->is<sf::Event::Closed>()) {
      this->window.close();
    }
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
    return Direction::Up;
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
    return Direction::Left;
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
    return Direction::Right;
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
    return Direction::Down;

  return Direction::None;
}

void SfmlUI::drawFrame(const Game &game) {

  this->window.clear(sf::Color::Black);

  sf::RectangleShape block({(float)this->tileSize, (float)this->tileSize});

  // Draw Apple
  block.setFillColor(sf::Color::Red);

  block.setPosition({(float)(game.applePosition().x * this->tileSize),
                     (float)(game.applePosition().y * this->tileSize)});

  this->window.draw(block);

  // Draw Snake
  block.setFillColor(sf::Color::Blue);

  for (const auto &snake : game.getSnakePositions()) {
    block.setPosition(
        {(float)(snake.x * this->tileSize), (float)(snake.y * this->tileSize)});
    this->window.draw(block);
  }

  this->window.display();
}
