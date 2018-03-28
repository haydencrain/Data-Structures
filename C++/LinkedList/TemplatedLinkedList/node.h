#ifndef NODE_H_
#define NODE_H_

template <typename T> class node {
  private:
    T data;
    node *next;

  public:
    node(node* n, T d) {
      data = d;
      next = n;
    };

    ~node() {};

    T getData() {
      return data;
    };

    node* getNext() {
      return next;
    };

    void setNext(node *n) {
      next = n;
    };
};

#endif