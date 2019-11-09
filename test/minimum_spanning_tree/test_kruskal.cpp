#include <iostream>
#include "kruskal.h"
#include <vector>
using namespace std;

int main() {
  int num_vertex = 7;
  vector<Edge> edges{{0, 2, 1}, {1, 2, 2}, {1, 4, 10}, {2, 3, 3}, {2, 5, 7},
                     {3, 5, 1}, {3, 6, 5}, {4, 5, 5},  {5, 6, 8}};
  Kruskal kruskal(num_vertex, edges);
  cout << "minimum spanning tree's total cost = " << kruskal.comp_mincost()
       << endl;
}
