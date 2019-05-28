#include <iostream>
#include <vector>
using namespace std;

static const int n{4};
vector<bool> used(n,false);
vector<int> perm(n);

void print_perm(){
  cout << "{";
  for(const auto i : perm) cout << i << ',';
  cout << "}\n";
}

void create_print_sortperm(const int pos){
  if(pos==n) print_perm();

  for(int i=0; i<n; ++i){
    if(!used[i]){
      perm[pos] = i;
      used[i] = true;
      create_print_sortperm(pos+1);
      used[i] = false;
    }
  }
  
  return;
}

int main(){
  create_print_sortperm(0);
  
  return 0;
}
