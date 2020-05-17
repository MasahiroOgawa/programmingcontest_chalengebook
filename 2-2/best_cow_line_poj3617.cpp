#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  string instr{"acdbcb"};
  string outstr;
  int front = 0;
  int back = instr.length() - 1;

  while (front <= back) {
    bool getleft = true;

    for (int i = 0; front + i <= back; ++i) {
      if (instr[front + i] < instr[back - i]) {
        break;
      } else if (instr[front + i] > instr[back - i]) {
        getleft = false;
        break;
      } // if instr[front+i]==instr[back-i], check next i.
    }

    if (getleft)
      outstr += instr[front++];
    else
      outstr += instr[back--];

    cout << "front,back = " << front << "," << back << endl;
  }

  // output result
  cout << "output = " << outstr << endl;

  return 0;
}
