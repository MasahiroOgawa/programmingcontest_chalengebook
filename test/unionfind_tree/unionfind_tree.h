#ifndef UNIONFIND_TREE_H
#define UNIONFIND_TREE_H

#include <vector>

class Unionfid_tree{
public:
    Unionfid_tree(int num_elem);
    int find_root(int x);
    void unite(int x, int y);
    bool belong_same(int x, int y){return find_root(x) == find_root(y);}

private:
    struct Node{
        Node(int par, int ran):parent(par),rank(ran){}
        int parent;
        int rank; // number of descendants
    };
    std::vector<Node> nodes;
};



#endif // UNIONFIND_TREE_H
