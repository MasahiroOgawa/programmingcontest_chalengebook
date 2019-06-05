//------------
// count minimum nuber of coins
//------------

#include <iostream>
using namespace std;

int main(){
  //input params
  static const int v[6] = {1,5,10,50,100,500}; // coins
  int c[6] = {3,2,1,3,0,2}; //num of coins
  int money{620}; //rest of money should be paid

  //algo
  int ans{0};

  for(int i=5; i>=0; --i){
    int numi = min(money/v[i], c[i]); //number of coins of i
    money -= numi * v[i];
    ans += numi;
  }

  cout << ans << endl;
  
  return 0;
}
