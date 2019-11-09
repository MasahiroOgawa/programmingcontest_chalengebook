#include <iostream>
#include <vector>

using namespace std;

////////////////////////
/// \brief The Priority_queue class
////////////////////////
class Priority_queue {
public:
  Priority_queue(const vector<int> &v);
  void push(const int x);
  int pop();
  void print();

private:
  vector<int> heap_;
};

Priority_queue::Priority_queue(const vector<int> &v) { heap_ = v; }

void Priority_queue::push(const int x) {
  heap_.push_back(x);
  int i = heap_.size() - 1;

  while (i > 0) {
    int p = (i - 1) / 2;
    if (heap_[p] <= x)
      break;

    heap_[i] = heap_[p];
    i = p;
  }
  heap_[i] = x;
}

int Priority_queue::pop(){
    int ret = heap_.front();

    //move last value from top to lower.
    int x = heap_.back();
    unsigned int i=0;
    while(i*2+1<heap_.size()){
        unsigned int l = 2*i+1;
        unsigned int r = 2*i+2;
        if(r<heap_.size() && heap_[r] < heap_[l]) l = r;
        if(heap_[l] >= x) break;
        heap_[i] = heap_[l];
        i = l;
    }
    heap_[i] = x;

    heap_.pop_back(); // remove x.
    return ret;
}

void Priority_queue::print() {
  for (auto i : heap_)
    cout << ' ' << i;
  cout << endl;
}

///////////////////////////
/// \brief main
/// \return
///////////////////////////
int main() {
  // input
  vector<int> v{1, 2, 4, 7, 8, 5};

  Priority_queue pque(v);
  pque.print();

  pque.push(3);
  pque.print();

  cout << "pop=" << pque.pop() << endl;
  pque.print();
}
