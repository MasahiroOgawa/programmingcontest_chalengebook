#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;

// sorting version
int main() {
  // input
  vector<int> L = {8, 5, 8};
  //    vector<int> L = {2, 8, 5, 8, 6};

  // solve
  ll ans = 0;

  // prepare priority que
  priority_queue<int, vector<int>, greater<int>> que;
  for(auto i : L) que.push(i);

  while (que.size() > 1) {
      // extract 1,2 min elements.
      int l1 = que.top();
      que.pop();
      int l2 = que.top();
      que.pop();

    // aggregate l1,l2
    ans += l1 + l2;

    // change L[0],L[1] value and reduce the size of L.
    que.push(l1+l2);
  }

  cout << "min cost = " << ans << endl;

  return 0;
}
