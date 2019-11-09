#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <string>
using namespace std;

static const int INF = 99999999;
typedef pair<int, int> P; //row,col

ostream& operator<<(ostream& os, const pair<int,int>& p){
  os << "(" << p.first << "," << p.second << ")";
}

const P operator+(const P& p1, const P& p2){
  return P(p1.first + p2.first, p1.second + p2.second);
}

//---------
template<typename T>
void show(vector<vector<T>> maze){
  for(const auto& i : maze){
    for(const auto& ii : i){
      cout << ii;
    }
    cout << endl;
  }
}

//----------
P find_char(const vector<vector<char>>& mat, const char ch){
  for(int i=0; i<mat.size(); ++i){
    for(int j=0; j<mat[i].size(); ++j){
      if(mat[i][j] == ch) return P(i,j);
    }
  }

  throw runtime_error("no "+ string{ch} + " found!");
}

//-------------
bool is_inside(const P& p, const vector<vector<char>>& maze){
  if(0 <= p.first && p.first < maze.size() && 0 <= p.second && p.second < maze[0].size())
    return true;
  return false;
}

//----------
int breadth_first_search(const vector<vector<char>>& maze){
  vector<vector<int>> dist(maze.size(),vector<int>(maze[0].size(),INF));
  // show<int>(dist);
  vector<P> divs{P(1,0),P(0,1),P(-1,0),P(0,-1)};
  queue<P> que; // next Points to check

  //find start and goal
  P start = find_char(maze, 's');
  P goal = find_char(maze, 'g');
  cout << "start=" << start << endl;
  cout << "goal=" << goal << endl;

  que.push(start);
  dist[start.first][start.second] = 0;

  while(que.size()){
    P pos = que.front();
    que.pop();

    if(pos==goal) break;

    // loop for 4 diviations
    for(const auto& div : divs){
      P next = pos + div;
      if(is_inside(next, maze) && maze[next.first][next.second] != '#'
	 && dist[next.first][next.second] == INF){
	que.push(next);
	dist[next.first][next.second] = dist[pos.first][pos.second] + 1;
      }
    }
  }

  show<int>(dist);
  return dist[goal.first][goal.second];
}

//---------
void solve(const vector<vector<char>>& maze){
  int ans = breadth_first_search(maze);
  cout << "min dist = " << ans << endl;
}

int main(){
  //input
  vector<vector<char>> maze{{'s','.','.'},{'#','.','.'},{'#','.','g'}};
  
  show<char>(maze);
  solve(maze);
  
  return 0;
}
