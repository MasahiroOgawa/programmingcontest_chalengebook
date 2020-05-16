#include "search.hpp"

namespace progchallenge {

bool binary_search(const int x, const std::vector<int> &v){
    int l=0;
    int r=v.size();

    // search until the range become empty.
    while(r-l>0){
        int c = (l+r)/2;
        if(v.at<int>(c) == x) return true;
        else if(v[c] < x) l = c+1;
        else r = c;
    }

    return false;
}

} // namespace progchallenge
