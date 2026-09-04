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
  Snake(int x, int y) {

    head = new Node;
    head->prev = nullptr;
    head->pos_x = x;
    head->pos_y = y;

    tail = new Node;
    tail->prev = head;
    tail->next = nullptr;
    tail->pos_x = x + 1;
    tail->pos_y = y;

    head->next = tail;

    size = 2;
  }
  ~Snake() = default;
};

#endif // !SNAKE_H
#define SNAKE_H
