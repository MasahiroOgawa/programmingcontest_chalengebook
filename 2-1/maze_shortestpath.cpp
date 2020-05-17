#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>
using namespace std;

static const int INF = 99999999;
typedef pair<int, int> P; // row,col

ostream &operator<<(ostream &os, const pair<int, int> &p) {
  os << "(" << p.first << "," << p.second << ")";
  return os;
}

const P operator+(const P &p1, const P &p2) {
  return P(p1.first + p2.first, p1.second + p2.second);
}

///
/// \brief show : show maze or min distance map
///
template <typename T> void show(vector<vector<T>> maze) {
  for (const auto &i : maze) {
    for (const auto &ii : i) {
      cout << ii << ' ';
    }
    cout << endl;
  }
}

///
/// \brief find_char : to find start and goal
/// \param mat
/// \param ch
/// \return
///
P find_char(const vector<vector<char>> &mat, const char ch) {
  for (size_t i = 0; i < mat.size(); ++i) {
    for (size_t j = 0; j < mat[i].size(); ++j) {
      if (mat[i][j] == ch)
        return P(i, j);
    }
  }

  throw runtime_error("no " + string{ch} + " found!");
}

///
/// \brief is_inside
/// \param p
/// \param maze
/// \return
///
bool is_inside(const P &p, const vector<vector<char>> &maze) {
  if (0 <= p.first && p.first < maze.size() && 0 <= p.second &&
      p.second < maze[0].size())
    return true;
  return false;
}

///
/// \brief breadth_first_search
/// \param maze
/// \return
///
int breadth_first_search(const vector<vector<char>> &maze) {
  vector<vector<int>> dist(maze.size(), vector<int>(maze[0].size(), INF));
  // show<int>(dist);
  vector<P> steps{P(1, 0), P(0, 1), P(-1, 0), P(0, -1)};
  queue<P> nextPts; // to check

  // find start and goal
  P start = find_char(maze, 's');
  P goal = find_char(maze, 'g');
  cout << "start=" << start << endl;
  cout << "goal=" << goal << endl;

  nextPts.push(start);
  dist[start.first][start.second] = 0;

  while (nextPts.size()) {
    P pos = nextPts.front();
    nextPts.pop();

    if (pos == goal)
      break;

    // loop for 4 diviations
    for (const auto &step : steps) {
      P next = pos + step;
      if (is_inside(next, maze) && maze[next.first][next.second] != '#' &&
          dist[next.first][next.second] == INF) {
        nextPts.push(next);
        dist[next.first][next.second] = dist[pos.first][pos.second] + 1;
      }
    }
  }

  show<int>(dist);
  return dist[goal.first][goal.second];
}

///
/// \brief main
/// \return
///
int main() {
  // input
  vector<vector<char>> maze{{'s', '.', '.'}, {'#', '.', '.'}, {'#', '.', 'g'}};
  show<char>(maze);

  // compute
  int ans = breadth_first_search(maze);

  // print result
  cout << "min dist = " << ans << endl;

  return 0;
}
