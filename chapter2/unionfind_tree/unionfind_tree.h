#ifndef UNIONFIND_TREE_H
#define UNIONFIND_TREE_H

#include <vector>

class Unionfid_tree{
public:
    Unionfid_tree(int n);
    int find_root(int x);
    void unite(int x, int y);
    bool same(int x, int y){return find_root(x) == find_root(y);}

private:
    std::vector<int> par;
    std::vector<int> rank;
};



#endif // UNIONFIND_TREE_H
