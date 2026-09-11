#include "sfmlUI.h"
#include "snake.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

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
