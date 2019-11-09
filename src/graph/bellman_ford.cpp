#include "bellman_ford.hpp"

using namespace std;

///
/// \brief bellman_ford
/// \param al
/// \return
///
vector<int> bellman_ford(const Adjacencylist& al)
{
    // initialize
    static constexpr int INF{ 999999 };
    vector<int> dists(al.size(), INF);
    dists[0] = 0;

    bool update{ true };
    while (update) {
        update = false;
        for (size_t vindx = 0; vindx < al.size(); ++vindx) {
            for (auto edge : al[vindx]) {
                if (dists[edge.to] > dists[vindx] + edge.cost) {
                    dists[edge.to] = dists[vindx] + edge.cost;
                    update = true;
                }
            }
        } // adjacency list
    } // while

    return dists;
}

///
/// \brief find_negative_loop
/// \param al
/// \return
/// find negative loop using bellman ford algorithm
///
bool find_negative_loop(const Adjacencylist& al)
{
    vector<int> dists(al.size(), 0);

    for (size_t vindx = 0; vindx < al.size(); ++vindx) {
        for (auto edge : al[vindx]) {
            if (dists[edge.to] > dists[vindx] + edge.cost) {
                dists[edge.to] = dists[vindx] + edge.cost;

                // if there still exist an update at the last step(al.size-1), it must
                // has a negative loop.
                if (vindx == al.size() - 1)
                    return true;
            }
        } // edge loop
    } // vertex loop

    return false;
}
