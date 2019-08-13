#include "unionfind_tree.h"
using namespace std;

Unionfid_tree::Unionfid_tree(int n){
    for(int i=0;i<n;++i){
        par.push_back(i);
        rank.push_back(0);
    }
}

int Unionfid_tree::find_root(int x){
    if(par[x] == x) return x;
    else return par[x] = find_root(par[x]);
}

void Unionfid_tree::unite(int x, int y){
    x = find_root(x);
    y = find_root(y);

    if(x == y) return;
    else if(rank[x] < rank[y]) par[x] = y;
    else{
        par[y] = x;
        if(rank[x] == rank[y]) rank[x]++;
    }
}
