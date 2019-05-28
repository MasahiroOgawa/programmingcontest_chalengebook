#include <iostream>
using namespace std;

//judge whether we can sum to k using int a1,...,an

//input 
int a[]={1,2,4,7};
int k=13;
// int k=15;

//global
int n = sizeof(a)/sizeof(int);

//use a1,...,ai and compute sum, and judge sum==k or not.
bool depth_first_search(int i, int sum){
  if(i==n) return sum==k;

  if(depth_first_search(i+1, sum)) return true;
  if(depth_first_search(i+1, sum+a[i])) return true;
    
  return false;
}

int main(){
  if(depth_first_search(0,0)) cout << "Yes\n";
  else cout << "No\n";
}
