#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

long long int minscalar_product(std::vector<int> &v1, std::vector<int> &v2) {
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end(), greater<int>());
    return std::inner_product(v1.begin(), v1.end(), v2.begin(), 0);
}

int main() {
    vector<int> v1{1, 3, -5};
    vector<int> v2{-2, 4, 1};
    cout << minscalar_product(v1, v2) << endl;

    v1 = vector<int>{1, 2, 3, 4, 5};
    v2 = vector<int>{1, 0, 1, 0, 1};
    cout << minscalar_product(v1, v2) << endl;

    return 0;
}
