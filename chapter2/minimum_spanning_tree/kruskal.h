#ifndef KRUSKAL_H
#define KRUSKAL_H
#include <vector>

struct Edge {
  int from;
  int to;
  int cost;
};

inline bool operator<(const Edge &e1, const Edge &e2){
  return e1.cost < e2.cost;
}

class Kruskal
{
public:
    Kruskal(const int num_vertex, const std::vector<Edge> &edges);
    int comp_mincost();
private:
    int num_vertex_;
    std::vector<Edge> edges_;
};

#endif // KRUSKAL_H
