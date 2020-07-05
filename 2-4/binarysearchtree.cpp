#include "binarysearchtree.hpp"
#include <iostream>
using namespace std;

bool Binarysearchtree::find(const int x) {
  if (p == nullptr)
    return false;
  else if (x == p->val)
    return true;
  else if (x < p->val) {
    return Binarysearchtree(p->lch).find(x);
  } else
    return Binarysearchtree(p->rch).find(x);
  return true;
}

Node *Binarysearchtree::insert(const int x) {
  if (p == nullptr) {
    p = new Node;
    p->val = x;
    return p;
  } else {
    if (x < p->val)
      p->lch = Binarysearchtree(p->lch).insert(x);
    else
      p->rch = Binarysearchtree(p->rch).insert(x);
    return p;
  }
}

void Binarysearchtree::remove(const int x) {
  if (p == nullptr)
    return;
  if (x < p->val)
    Binarysearchtree(p->lch).remove(x);
  else if (x > p->val)
    Binarysearchtree(p->rch).remove(x);

  // in case x == p->val
  else if (p->lch == nullptr)
    p = p->rch;
  else if (p->lch->rch == nullptr) {
    Node *q = p->lch;
    q->rch = p->rch;
    p = move(q);
  } else {
    Node *q;
    for (q = p->lch; q->rch->rch != nullptr; q = q->rch)
      ;

    // now the maximum in the p->lch is q->rch->val. we want to bring this val
    // to the top.
    Node *r = q->rch;
    q->rch = move(r->lch);
    // now bring r->val to the top by swapping p and r.
    r->lch = p->lch;
    r->rch = p->rch;
    p = move(r);
  }
}

void Binarysearchtree::print() {
  if (p == nullptr)
    return;

  // bad printing. I don't have good solution yet.
  cout << p->val << endl << "/ \\" << endl;

  Binarysearchtree(p->lch).print();
  cout << " ";
  Binarysearchtree(p->rch).print();
}
