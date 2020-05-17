#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

// sorting version
int main() {
  // input
  vector<int> L = {8, 5, 8};
  //    vector<int> L = {2, 8, 5, 8, 6};

  // solve
  ll ans = 0;

  while (L.size() > 1) {
    // find min and 2nd min L.
    sort(L.begin(), L.end());

    // print current L
    cout << "L=";
    for (auto i : L)
      cout << i << ' ';
    cout << endl;

    // aggregate L[0] and L[1]
    int t = L[0] + L[1];
    ans += t;

    // change L[0],L[1] value and reduce the size of L.
    L[0] = t;
    L.erase(L.begin() + 1);
  }

  cout << "min cost = " << ans << endl;

  return 0;
}

/////
///// \brief main
///// \return
///// \detail original book version
// int main(){
//  //input
//  int L[] = {2,8,5,8,6};

//  //solve
//  int N = sizeof(L) / sizeof(int);
//  ll ans = 0;

//  while(N > 1){
//    //print current L
//    cout << "L=";
//    for(int i=0; i<N; ++i) cout << L[i] << ' ';
//    cout << endl;

//    //find min and 2nd min L, and set it to mii1, mii2.
//    int mii1=0,mii2=1;
//    if(L[mii1] > L[mii2]) swap(mii1, mii2);
//    for(int i=2; i<N; ++i){
//      if(L[i] < L[mii1]){ //find minimum L and set to L[mii1]
//	mii2 = mii1;
//	mii1 = i;
//      }else if(L[i] < L[mii2]) mii2 = i; // find 2nd min L and set it to
//      L[mii2]
//    }

//    //aggregate L[mii1] and L[mii2]
//    int t = L[mii1] + L[mii2];
//    ans += t;

//    //change L[mii1],L[mii2] value and reduce the size of L.
//    if(mii1 == N-1) swap(mii1, mii2);
//    L[mii1] = t;
//    L[mii2] = L[N-1];
//    N--;
//  }

//  cout << "min cost = " << ans << endl;

//  return 0;
//}
