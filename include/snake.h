#ifndef SNAKE_H
#define SNAKE_H

enum class Direction { Up, Down, Left, Right };

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

public:
  Snake(int x, int y);
  ~Snake();
  void grow(int x, int y);
  void turn(Direction dir);
  void move();
};

#endif // !SNAKE_H
