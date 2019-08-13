#ifndef _BINARYSEARCHTREE_H_
#define _BINARYSEARCHTREE_H_
#include <memory>

struct Node {
  int val{0};
  Node *lch{nullptr};
  Node *rch{nullptr};
};

class Binarysearchtree {
public:
  Binarysearchtree() {}
  Binarysearchtree(Node *q) : p(q) {}
  bool find(const int x);
  Node *insert(const int x);
  void remove(const int x);
  void print();

private:
  Node *p{nullptr}; // we cannot use std::unique_ptr<Node> because unique_ptr
                    // must refer to a dynamically allocated object like; new
                    // Node().
};

#endif
