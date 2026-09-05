#include "snake.h"

Snake::Snake(int x, int y) {

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
Snake::~Snake() {

  Node *temp = head;

  while (head->next != nullptr) {

    head = head->next;
    delete temp;
    temp = head;
  }

  delete head;
}
