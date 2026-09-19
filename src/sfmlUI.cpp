#include "sfmlUI.h"
#include "snake.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/System/Angle.hpp>
#include <SFML/System/Vector2.hpp>
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
  spriteSnakeHead.setOrigin({8.f, 8.f});

  if (!textureSnakeBody.loadFromFile("assets/body.png")) {
    throw std::runtime_error("Could not load assets/body.png");
  }
  textureSnakeBody.setSmooth(false);
  spriteSnakeBody.setTexture(textureSnakeBody, true);
  spriteSnakeBody.setScale({scaleX, scaleY});
  spriteSnakeBody.setOrigin({8.f, 8.f});

  if (!textureSnakeTail.loadFromFile("assets/tail.png")) {
    throw std::runtime_error("Could not load assets/tail.png");
  }
  textureSnakeTail.setSmooth(false);
  spriteSnakeTail.setTexture(textureSnakeTail, true);
  spriteSnakeTail.setScale({scaleX, scaleY});
  spriteSnakeTail.setOrigin({8.f, 8.f});

  if (!textureSnakeTurn.loadFromFile("assets/turn.png")) {
    throw std::runtime_error("Could not load assets/turn.png");
  }
  textureSnakeTurn.setSmooth(false);
  spriteSnakeTurn.setTexture(textureSnakeTurn, true);
  spriteSnakeTurn.setScale({scaleX, scaleY});
  spriteSnakeTurn.setOrigin({8.f, 8.f});

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

  auto const map = game.mapCoordinates();

  for (int y = 0; y < map.y; y++) {
    for (int x = 0; x < map.x; x++) {

      if ((x + y) % 2 == 0) {

        this->spriteGrassLight.setPosition(
            {(float)(x * this->tileSize), (float)(y * this->tileSize)});
        this->window.draw(spriteGrassLight);

      } else {
        this->spriteGrassDark.setPosition(
            {(float)(x * this->tileSize), (float)(y * this->tileSize)});
        this->window.draw(spriteGrassDark);
      }
    }
  }

  // Draw Apple
  this->spriteApple.setPosition(
      {(float)(game.applePosition().x * this->tileSize),
       (float)(game.applePosition().y * this->tileSize)});

  this->window.draw(spriteApple);

  // Draw Snake
  const auto snake = game.getSnakePositions();

  if (snake[0].x > snake[1].x) {
    this->spriteSnakeHead.setRotation(sf::degrees(90));
  } else if (snake[0].x < snake[1].x) {
    this->spriteSnakeHead.setRotation(sf::degrees(270));
  } else if (snake[0].y > snake[1].y) {
    this->spriteSnakeHead.setRotation(sf::degrees(180));
  } else if (snake[0].y < snake[1].y) {
    this->spriteSnakeHead.setRotation(sf::degrees(0));
  }

  this->spriteSnakeHead.setPosition(
      {(float)((snake[0].x + 0.5f) * this->tileSize),
       (float)((snake[0].y + 0.5f) * this->tileSize)});
  this->window.draw(spriteSnakeHead);

  for (size_t i = 1; i < snake.size() - 1; i++) {

    sf::Vector2<float> positon = {
        (float)((snake[i].x + 0.5f) * this->tileSize),
        (float)((snake[i].y + 0.5f) * this->tileSize)};

    sf::Angle angle;
    bool isTurn = false;

    if (snake[i - 1].x == snake[i + 1].x) {
      angle = sf::degrees(0);
    } else if (snake[i - 1].y == snake[i + 1].y) {
      angle = sf::degrees(90);
    } else if (snake[i - 1].x != snake[i + 1].x &&
               snake[i - 1].y != snake[i + 1].y) {

      const auto &anterior = snake[i - 1];
      const auto &atual = snake[i];
      const auto &proximo = snake[i + 1];

      bool esquerda = anterior.x < atual.x || proximo.x < atual.x;
      bool direita = anterior.x > atual.x || proximo.x > atual.x;
      bool cima = anterior.y < atual.y || proximo.y < atual.y;
      bool baixo = anterior.y > atual.y || proximo.y > atual.y;

      if (baixo && esquerda) {
        angle = sf::degrees(0);
      } else if (esquerda && cima) {
        angle = sf::degrees(90);
      } else if (cima && direita) {
        angle = sf::degrees(180);
      } else if (direita && baixo) {
        angle = sf::degrees(270);
      }

      isTurn = true;
    }

    if (isTurn) {
      spriteSnakeTurn.setPosition(positon);
      spriteSnakeTurn.setRotation(angle);
      this->window.draw(spriteSnakeTurn);
    } else {
      spriteSnakeBody.setPosition(positon);
      spriteSnakeBody.setRotation(angle);
      this->window.draw(spriteSnakeBody);
    }
  }

  spriteSnakeTail.setPosition(
      {(float)((snake[snake.size() - 1].x + 0.5f) * this->tileSize),
       (float)((snake[snake.size() - 1].y + 0.5f) * this->tileSize)});

  if (snake[snake.size() - 2].x < snake[snake.size() - 1].x) {
    spriteSnakeTail.setRotation(sf::degrees(270));
  } else if (snake[snake.size() - 2].x > snake[snake.size() - 1].x) {
    spriteSnakeTail.setRotation(sf::degrees(90));
  } else if (snake[snake.size() - 2].y < snake[snake.size() - 1].y) {
    spriteSnakeTail.setRotation(sf::degrees(0));
  } else if (snake[snake.size() - 2].y > snake[snake.size() - 1].y) {
    spriteSnakeTail.setRotation(sf::degrees(180));
  }
  this->window.draw(spriteSnakeTail);

  this->window.display();
}
