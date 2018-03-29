#include "linked_list.h"

template <typename T> linked_list<T>::linked_list() {
  head = nullptr;
  len = 0;
};

template <typename T> linked_list<T>::~linked_list()
{
  node<T> *curr = head;
  while (curr != nullptr)
  {
    node<T> *next = curr->getNext();
    delete curr;
    curr = next;
  }
};

template <typename T> void linked_list<T>::append(T data) {
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

template <typename T>size_t linked_list<T>::length() {
  return len;
};

template <typename T> T linked_list<T>::get(int index)
{
  node<T> *curr = head;
  for (int i = 0; i < index; i++)
  {
    curr = curr->getNext();
  }
  return curr->getData();
};