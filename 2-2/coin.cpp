//------------
// count minimum nuber of coins
//------------

#include <iostream>
#include <vector>
using namespace std;

int main() {
  // input params
  vector<int> coins{1, 5, 10, 50, 100, 500};
  vector<int> num_coins{3, 2, 1, 3, 0, 2};
  int money{620}; // rest of money should be paid

  // algo
  int ans{0};

  for (int i = coins.size() - 1; i >= 0; --i) {
    int num_coini = min(money / coins[i], num_coins[i]);
    money -= num_coini * coins[i];
    ans += num_coini;
  }

  cout << ans << endl;

  return 0;
}
