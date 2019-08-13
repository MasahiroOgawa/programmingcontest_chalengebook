#include <iostream>
#include <set>
using namespace std;

int main(){
    set<int> s;
    s.insert(1);
    s.insert(3);
    s.insert(5);

    auto it = s.find(1);
    if(it != s.end()) cout << "1 found.\n";
    else cout << " 1 not found.\n";

    it = s.find(2);
    if(it != s.end()) cout << "2 found.\n";
    else cout << "2 not found.\n";

    s.erase(3);
    if(s.count(3) != 0) cout << "3 found.\n";
    else cout << "3 not found.\n";

    for(int i : s)
        cout << i << ' ';
}
