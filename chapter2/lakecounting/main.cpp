#include <iostream>
#include <vector>
using namespace std;

//----------------------
void fill_lake(vector<vector<int>>& lake){ // nxm lake
  srand(time(NULL));

  for(auto& lakerow : lake){
    for(auto& l : lakerow){
      l = rand() % 2;
      if(l == 0) cout << ".";
      else cout << "w";
    }
    cout << endl;
  }
}

//-------------------
// set all 8-neighbor to 0 of (x,y) recursively
void depthfirstsearch(vector<vector<int>>& lake, int x, int y){
  lake[x][y] = 0;

  // loop 8 neighbors
  for(int dx=-1; dx<=1; ++dx){
    for(int dy=-1; dy<=1; ++dy){
      int nx = x + dx;
      int ny = y + dy;
      
      if(0<=nx && nx < lake.size() && 0<=ny && ny <= lake[0].size() &&
	 lake[nx][ny] == 1) depthfirstsearch(lake,nx,ny);
    }
  }

  return;
}

//----------------------
void solve(vector<vector<int>>& lake){
  int ans{0};

  for(int i=0; i<lake.size(); ++i){
    for(int j=0; j<lake[0].size(); ++j){
      if(lake[i][j] == 1){
	depthfirstsearch(lake,i,j);
	++ans;
      }
    } 
  }

  cout << "ans=" << ans << endl;
}

//------------------
int main(){
  //create lake
  int m{10};
  int n{12};
  vector<vector<int>> lake(m, vector<int>(n)); //m x n size.
  fill_lake(lake);

  solve(lake);

  return 0;
}
