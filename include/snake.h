#ifndef SNAKE_H
#define SNAKE_H

#include <vector>

struct Position {
  int x;
  int y;
};

enum class Direction { Up, Down, Left, Right, None };

class Snake {

  struct Node {

    int pos_x;
    int pos_y;
    struct Node *prev;
    struct Node *next;
  };

  Node *head; // start of list
  Node *tail; // end of list
  unsigned size;
  Direction actualDirection;
  bool mustGrow;

  bool col_rec(Node *actual);

public:
  Snake(int x, int y);
  ~Snake();
  void grow();
  void turn(Direction dir);
  void move();
  void copyPositions(std::vector<Position> &buffer) const;
  bool collided();
};

#endif // !SNAKE_H
