#include <iostream>
#include <vector>
#include <algorithm> // sort

using namespace std;

int main(){
  // input params
  static const int r{10};
  static vector<int> x{1,7,15,20,30,50};

  // prepare computation
  int n = x.size();
  sort(x.begin(), x.end());
  vector<int> checked_pts;

  //compute min check points
  for(int i=0; i<n;){
    int s = x[i]; //non covered left most point

    //define a check point p; distance r from s
    while(i < n && x[i] <= s+r) ++i;
    int p = x[i-1];
    checked_pts.push_back(p);

    // set next non covered left most point
    while(i < n && x[i] <= p+r) ++i;
  }

  // print the answer
  cout << "checked poits = {";
  for(auto i : checked_pts) cout << i << ',';
  cout << "}\n";
  cout << "min number of checked points = " << checked_pts.size() << endl;
    
  return 0;
}
