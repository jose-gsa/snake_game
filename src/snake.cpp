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

void Snake::grow(int x, int y) {

  Node *new_head = new Node;
  new_head->pos_x = x;
  new_head->pos_y = y;
  new_head->prev = this->head;

  this->head->prev = new_head;
  this->head = new_head;
}
