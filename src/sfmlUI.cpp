#include "sfmlUI.h"
#include "snake.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

SfmlUI::SfmlUI(int mapWidth, int mapHeight, int tileSize)
    : window(sf::VideoMode({(unsigned int)(mapWidth * tileSize),
                            (unsigned int)(mapHeight * tileSize)}),
             "Snake Game"),
      tileSize(tileSize) {

  window.setFramerateLimit(10);
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
