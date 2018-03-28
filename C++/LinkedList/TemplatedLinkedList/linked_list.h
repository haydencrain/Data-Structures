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
    linked_list() {
      head = nullptr;
      len = 0;
    };

    ~linked_list() {

    };

    void append(T data) {
      node<T> *newNode = new node<T>(nullptr, data);
      if (head == nullptr)
      {
        head = newNode;
      }
      else
      {
        node<T> *curr = head;
        while (curr->getNext() != nullptr)
        {
          curr = curr->getNext();
        }
        curr->setNext(newNode);
      }
      len++;
    };

    size_t length() {
      return len;
    };

    T get(int index) {
      node<T> *curr = head;
      for (int i = 0; i < index; i++) {
        curr = curr->getNext();
      }
      return curr->getData();
    };
};

#endif