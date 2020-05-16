#include <vector>
#include <iostream>
#include <climits>
using namespace std;


int MAX_N = 1000;
vector<long> memo(MAX_N, 0);

long fibonacci(int n){
  if(n<0) throw(out_of_range("input is negative!"));
  if(n<2) return n;
  if(memo.at(n) != 0) return memo.at(n); // ever computed.
  if(memo.at(n-1) > LONG_MAX/2) throw(out_of_range("input is too large!"));

  return  memo.at(n) = fibonacci(n-1) + fibonacci(n-2);
}

int main()try{
  cout << "MAX= " << LONG_MAX << endl;
  for(int i=0; i<100; ++i)   
    cout << "fibonacci(" << i << ")= " << fibonacci(i) << endl;
 }catch(exception& e){ cerr << e.what() << endl; }
