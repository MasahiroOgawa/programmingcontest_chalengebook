#include <iostream>
#include <map>

using namespace std;

int main(){
  // input params
  int s[] = {1,2,4,6,8};
  int e[] = {3,5,7,9,10};

  // init jobs
  int n = sizeof(s)/sizeof(int);
  map<int,int> jobs;
  for(int i=0; i<n; ++i)
    jobs.insert(make_pair(e[i],s[i]));
  // for(auto j : jobs) cout << j.first << ',' << j.second << endl;

  // find jobs
  int t{0};
  int ans{0};
  for(auto j : jobs){
    if(t < j.second){
      ++ans;
      t = j.first;
    }
  }

  cout << "max number of jobs = " << ans << endl;
  return 0;
}
