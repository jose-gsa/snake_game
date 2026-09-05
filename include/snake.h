#ifndef SNAKE_H
#define SNAKE_H

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

public:
  Snake(int x, int y);
  ~Snake();
  void grow(int x, int y);
};

#endif // !SNAKE_H
