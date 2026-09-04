#ifndef SNAKE_H
#define SNAKE_H

class Snake {

  typedef struct Node {

    int pos_x;
    int pos_y;
    struct Node *prev;
    struct Node *next;

  } Node;

  Node *head; // start of list
  Node *tail; // end of list
  unsigned size;

public:
  Snake() = default;
  ~Snake() = default;
};

#endif // !SNAKE_H
#define SNAKE_H
