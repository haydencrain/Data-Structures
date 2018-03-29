#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include <cstddef>
#include <string>

#include "node.h"

using std::size_t;

template <typename T> class linked_list {
  private:
    node<T> *head;
    size_t len;

  public:
    linked_list();
    ~linked_list();
    void append(T data);
    size_t length();
    T get(int index);
};

#endif