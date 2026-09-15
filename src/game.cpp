#include "game.h"
#include "snake.h"
#include <cstdlib>
#include <time.h>
#include <vector>

Game::Game(int x, int y)
    : map_width_X(x), map_height_Y(y), snake(x / 2, y / 2) {

  srand(time(NULL));

  this->gameOver = false;

  this->snake.copyPositions(this->snakePositions);

  Game::spawnApple();
}

void Game::processInput(Direction dir) { this->snake.turn(dir); }

void Game::update() {

  this->snake.move();

  this->snake.copyPositions(this->snakePositions);

  if (this->snake.collided()) {
    this->gameOver = true;
  }

  // snakePositions[0] is the coordinates from snake head
  if (this->snakePositions[0].x >= this->map_width_X ||
      this->snakePositions[0].x < 0 ||
      this->snakePositions[0].y >= this->map_height_Y ||
      this->snakePositions[0].y < 0) {
    this->gameOver = true;
  }

  if (snakePositions[0].x == apple.x && snakePositions[0].y == apple.y) {
    snake.grow();
    spawnApple();
  }
}

void Game::spawnApple() {

  int x;
  int y;
  bool collided;

  do {

    collided = false;

    x = rand() % this->map_width_X;
    y = rand() % this->map_height_Y;

    for (size_t i = 0; i < snakePositions.size(); i++) {

      if (x == snakePositions[i].x && y == snakePositions[i].y) {
        collided = true;
      }
    }
  } while (collided);

  apple.x = x;
  apple.y = y;
}

Position Game::applePosition() const { return this->apple; }

const std::vector<Position> &Game::getSnakePositions() const {

  return this->snakePositions;
}

Position Game::mapCoordinates() const {

  return {this->map_width_X, this->map_height_Y};
}

bool Game::isGameOver() const { return this->gameOver; }
