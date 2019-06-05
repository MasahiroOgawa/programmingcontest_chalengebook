#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;


//sorting version
int main(){
  // input
  vector<int>L = {2,8,5,8,6};

  // solve
  ll ans = 0;

  while(L.size() > 1){
    // find min and 2nd min L, and set it to mii1, mii2.
    sort(L.begin(), L.end());

    // print current L
    cout << "L=";
    for(auto i : L) cout << i << ' ';
    cout << endl;

    // aggregate L[mii1] and L[mii2]
    int t = L[0] + L[1];
    ans += t;

    // change L[mii1],L[mii2] value and reduce the size of L.
    L[0] = t;
    L.erase(L.begin()+1);
  }

  cout << "min cost = " << ans << endl;

  return 0;
}
