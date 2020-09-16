#include <iostream>
#include <progchallenge/kruskal.hpp>

using namespace std;
using namespace progchallenge;

int main() {
  int N{5}, M{5};
  vector<Edge> relations{{4, 3, 6831}, {1, 3, 4583}, {0, 0, 6592},
                         {0, 1, 3063}, {3, 3, 4975}, {1, 3, 2049},
                         {4, 2, 2104}, {2, 2, 781}}; // men,women,intimacy

  vector<Edge> mix_relations; // mix men and women
  for (auto e : relations) {
    mix_relations.push_back({e.from, N + e.to, -e.cost});
  }

  Kruskal kruskal(N + M, mix_relations);
  cout << "min hiring cost = " << 10000 * (N + M) + kruskal.comp_mincost()
       << endl;
}
