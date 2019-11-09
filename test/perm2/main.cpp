#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  //param
  static const int n{3};
  
  vector<int> perm(n);
  for(int i=0;i<n;++i) perm[i] = i;

  do{
    cout << "{";
    for(const auto i : perm) cout << i << ",";
    cout <<"}\n";
  }while(next_permutation(perm.begin(),perm.end()));

  return 0;
}
