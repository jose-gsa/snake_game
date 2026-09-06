#include "snake.h"
#include <vector>

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
  new_head->next = this->head;
  new_head->prev = nullptr;

  this->head->prev = new_head;
  this->head = new_head;
}

void Snake::turn(Direction dir) {

  // Snake cannot turn 180 degres
  if (this->actualDirection == Direction::Up && dir == Direction::Down) {

    return;
  }
  if (this->actualDirection == Direction::Left && dir == Direction::Right) {

    return;
  }
  if (this->actualDirection == Direction::Right && dir == Direction::Left) {

    return;
  }
  if (this->actualDirection == Direction::Down && dir == Direction::Up) {

    return;
  }

  Node *new_head = new Node;
  new_head->next = this->head;
  this->head->prev = new_head;

  new_head->pos_x = this->head->pos_x;
  new_head->pos_y = this->head->pos_y;

  if (dir == Direction::Up) {
    new_head->pos_y--;
  }
  if (dir == Direction::Down) {
    new_head->pos_y++;
  }
  if (dir == Direction::Left) {
    new_head->pos_x--;
  }
  if (dir == Direction::Right) {
    new_head->pos_x++;
  }

  this->head = new_head;

  Node *temp = this->tail->prev;
  delete this->tail;

  this->tail = temp;
  this->tail->next = nullptr;

  this->actualDirection = dir;
}

void Snake::move() { Snake::turn(this->actualDirection); }

void Snake::copyPositions(std::vector<Position> &buffer) const {

  Node *actual = this->head;
  buffer.clear();

  while (actual != nullptr) {
    buffer.push_back({actual->pos_x, actual->pos_y});
    actual = actual->next;
  }
}

bool Snake::collided() {

  Node *actual = this->head->next;

  return col_rec(actual);
}

bool Snake::col_rec(Node *actual) {

  if (actual == nullptr) {
    return false;
  }

  if (actual->pos_x == this->head->pos_x &&
      actual->pos_y == this->head->pos_y) {
    return true;
  }

  return Snake::col_rec(actual->next);
}
