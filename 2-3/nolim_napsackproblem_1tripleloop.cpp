#include <iostream>
#include <vector>

using namespace std;

void printdp(vector<vector<int>>& dp){
  cout << "dp=";
  for(auto& row : dp){
    for(auto i : row)
      cout << i << ' ';
    cout << endl;
  }
  cout << endl;
}

int main(){
  //input
  vector<int> w={3,4,2}; // weight
  vector<int> v={4,5,3}; // value
  int W = 7; //limit weight

  //define values
  int n = w.size();
  vector<vector<int>> dp(n+1, vector<int>(W+1,0));
  
  //solve
  for(int i=0; i<n; ++i)
    for(int j=0; j<=W; ++j)
      for(int k=0; k*w[i] <= j; ++k)
	dp[i+1][j] = max(dp[i+1][j], dp[i][j-k*w[i]] + k*v[i]);

  printdp(dp);

  cout << "answer = " << dp[n][W] << endl;
  return 0;
}
