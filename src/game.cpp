#include "game.h"
#include "snake.h"

Game::Game(int x, int y)
    : map_width_X(x), map_height_Y(y), snake(x / 2, y / 2) {

  Game::spawnApple();
}
