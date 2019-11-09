#include <iostream>
#include <vector>

using namespace std;

const int n = 4;
vector<int> G[n];
int color[n];

void define_graph(){
//    //triangle
//    G[0].push_back(1);
//    G[1].push_back(0);
//    G[0].push_back(2);
//    G[2].push_back(0);
//    G[2].push_back(1);
//    G[1].push_back(2);

//type2
        G[0].push_back(1);
        G[1].push_back(0);
        G[0].push_back(3);
        G[3].push_back(0);
        G[2].push_back(1);
        G[1].push_back(2);
        G[2].push_back(3);
        G[3].push_back(2);
}

bool dfs(int v, int c) {
  color[v] = c;
  for (size_t i = 0; i < G[v].size(); ++i) {
    if (color[G[v][i]] == c)
      return false;
    if (color[G[v][i]] == 0 && !dfs(G[v][i], -c))
      return false;
  }

  return true;
}

bool solve() {
  for (int i = 0; i < n; ++i) {
    if (color[i] == 0)
      if (!dfs(i, 1))
        return false;
  }
  return true;
}

int main() {
    define_graph();

  if (solve())
    cout << "Yes, we can paint in 2 colors.\n";
  else
    cout << "No, we can't.\n";
}
