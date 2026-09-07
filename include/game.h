#ifndef GAME_H
#define GAME_H

#include "snake.h"
#include <vector>

class Game {

  int map_width_X;
  int map_height_Y;
  bool gameOver;
  Snake snake;
  Position apple;
  std::vector<Position> snakePositions;

  void spawnApple();

public:
  Game(int x, int y);
  ~Game() = default;
  void update();
  void processInput(Direction dir);

  Position applePosition() const;
  Position mapCoordinates() const;
  const std::vector<Position> &getSnakePositions() const;
};

#endif // !GAME_H
