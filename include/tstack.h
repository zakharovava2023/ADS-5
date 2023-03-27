// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_
#include <string>
template<typename T, int size>
class TStack {
 private:
  T array[1000];
  int top;

 public:
  TStack() :top(-1) {}
  void push(T value) {
    if (isFull()) {
    throw std::string("Full");
    } else {
    array[++top] = value;
    }
  }
  const T& pop() {
    if (isEmpty()) {
    throw std::string("Eempty");
    } else {
    return array[top--];
    }
  }
  const T& get()const {
    return array[top];
  }
  bool isEmpty()const {
    if (top == -1) return true;
    return false;
  }
  bool isFull()const {
    if (top == size - 1) return true;
    return false;
  }
};

#endif  // INCLUDE_TSTACK_H_
