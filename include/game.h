#ifndef GAME_H
#define GAME_H

#include "snake.h"

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
};

#endif // !GAME_H
