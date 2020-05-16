#include <iostream>
#include <progchallenge/bellman_ford.hpp>
using namespace std;
using namespace graph;

int main() {
  // define graph for the problem
  vector<Edge> a{{2, 10}}; // Edge(to,cost)
  vector<Edge> b{{0, 0}, {3, 20}};
  vector<Edge> c{{1, 0}, {1, -3}};
  vector<Edge> d{{2, 0}};
  Adjacencylist al({a, b, c, d});

  // compute the answer
  int answer;
  if (find_negative_loop(al))
    answer = -1;
  else {
    vector<int> dists = bellman_ford(al);
    answer = dists[al.size() - 1];

    if (answer == INF)
      answer = -2;

    cout << "reference: final distants----------\n";
    for (size_t i = 0; i < dists.size(); ++i)
      cout << "d[" << i << "]= " << dists[i] << endl;
  }

  cout << "answer = " << answer << endl;

  return 0;
}
